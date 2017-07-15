#include "Student.h"
#include <memory>
#include <exception>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <fstream>

class StudentCard
{
private:
    std::unique_ptr<Student> m_student;
    std::string m_groupName;
    
public:
    StudentCard(std::unique_ptr<Student> student, std::string const& groupName):
        m_student(std::move(student)),
        m_groupName(groupName)
    {
    }
    
    ~StudentCard()
    {
        std::cout << "StudentCard destructor\n";
    }
    
    std::string const& GetGroupName() const
    {
        return m_groupName;
    }
    
    Student const& GetStudent() const
    {
        return *m_student;
    }
};

std::unique_ptr<StudentCard> CreateStudentCard(std::unique_ptr<Student> student, std::string const& groupName)
{
    return std::unique_ptr<StudentCard>(new StudentCard(std::move(student), groupName));
}

void ThrowExceptFunc()
{
    throw std::runtime_error("Sorry, but I have to throw it");
}

void WorkWithUniquePtr()
{
    std::cout << "--=== Working with unique_ptr ===--\n";
    try
    {
        std::unique_ptr<Student> student(new Student());
        student->SetName("Ivanov");
        student->SetRating(6);
        std::unique_ptr<Student> student2(new Student("Petrov", 7));
        student2.reset(new Student("Shukherman", 9));
        
        std::unique_ptr<StudentCard> studentCard = CreateStudentCard(std::move(student), "PP2016");
        std::unique_ptr<StudentCard> studentCard2;
        studentCard2 = CreateStudentCard(std::move(student2), "PP2016");
        
        ThrowExceptFunc();
    }
    catch (std::exception const& e)
    {
        std::cout << e.what() << "\n";
    }
    
    std::unique_ptr<Student[]> students(new Student[3]);
    students[0].SetName("Azarenko");
    students[1].SetName("Eroshenko");
    
    std::unique_ptr<int, void(*)(int*)> customDestructorPtr(new int[10],
        [](int* array)
        {
            std::cout << "Deleting array of int\n";
            delete [] array;
        });
    
    std::unique_ptr<int, std::default_delete<int[]>> customDestructorPtr2(new int[10]);
    std::unique_ptr<Student> student3(new Student("Petrov", 7));
    Student* rawPtr = student3.get();
    rawPtr->Print();
    Student* rawPtr2 = student3.release();
    if (student3.get() != nullptr)
    {
        student3->Print();
    }
    delete rawPtr2;
}

class Person
{
public:
    std::string Name;
    
    std::shared_ptr<Person> Mother;
    std::shared_ptr<Person> Father;
    std::vector<std::shared_ptr<Person>> Kids;
    
    Person(std::string const& name,
           std::shared_ptr<Person> mom = nullptr,
           std::shared_ptr<Person> dad = nullptr) :
    Name(name),
    Mother(mom),
    Father(dad)
    {
        std::cout << "Creating " << Name << std::endl;
    };
    ~Person()
    {
        std::cout << "Destroying " << Name << std::endl;
    };
};

std::shared_ptr<Person> InitFamily(std::string const& name)
{
    std::shared_ptr<Person> mom(new Person(name + "\'s mom"));
    std::shared_ptr<Person> dad(new Person(name + "\'s dad"));
    std::shared_ptr<Person> kid(new Person(name, mom, dad));
    mom->Kids.push_back(kid);
    dad->Kids.push_back(kid);
    return kid;
}

class Person2
{
public:
    std::string Name;
    
    std::shared_ptr<Person2> Mother;
    std::shared_ptr<Person2> Father;
    std::vector<std::weak_ptr<Person2>> Kids;
    
    Person2(std::string const& name,
           std::shared_ptr<Person2> mom = nullptr,
           std::shared_ptr<Person2> dad = nullptr) :
    Name(name),
    Mother(mom),
    Father(dad)
    {
        std::cout << "Creating " << Name << std::endl;
    };
    ~Person2()
    {
        std::cout << "Destroying " << Name << std::endl;
    };
};

std::shared_ptr<Person2> InitFamily2(std::string const& name)
{
    std::shared_ptr<Person2> mom(new Person2(name + "\'s mom"));
    std::shared_ptr<Person2> dad(new Person2(name + "\'s dad"));
    std::shared_ptr<Person2> kid(new Person2(name, mom, dad));
    mom->Kids.push_back(kid);
    dad->Kids.push_back(kid);
    return kid;
}

class TmpFileGuard
{
    std::string m_fileName;
    
public:
    TmpFileGuard(std::string const& fileName):
        m_fileName(fileName)
    {
    }
    
    void operator()(std::fstream* stream)
    {
        std::cout << "Closing file " << m_fileName << std::endl;
        delete stream;
        std::cout << "Removing file " << m_fileName << std::endl;
        std::remove(m_fileName.c_str());
    }
};

int main()
{
    WorkWithUniquePtr();
    
    std::cout << "\n--=== Working with shared_ptr ===--\n";
    {
        Student ivanov("Ivanov", 5);
        Student petrov("Petrov", 6);
        
        std::stack<Student> dutyList;
        dutyList.push(ivanov);
        dutyList.push(petrov);
        dutyList.push(ivanov);
        dutyList.push(petrov);
        dutyList.push(ivanov);
        
        while (!dutyList.empty())
        {
            std::cout << "Today is on duty " << dutyList.top().GetName() << std::endl;
            dutyList.pop();
        }
    }
    
    std::cout << std::endl;
    {
        std::shared_ptr<Student> ivanovPtr(new Student("Ivanov", 5));
        std::shared_ptr<Student> petrovPtr = std::make_shared<Student>("Petrov", 5);
        
        std::cout << ivanovPtr.use_count() << " " << petrovPtr.use_count() << std::endl;
        std::stack<std::shared_ptr<Student>> dutyList2;
        dutyList2.push(ivanovPtr);
        dutyList2.push(petrovPtr);
        dutyList2.push(ivanovPtr);
        dutyList2.push(petrovPtr);
        dutyList2.push(ivanovPtr);
        std::cout << ivanovPtr.use_count() << " " << petrovPtr.use_count() << std::endl;
        while (!dutyList2.empty())
        {
            std::cout << "Today is on duty " << dutyList2.top()->GetName() << std::endl;
            dutyList2.pop();
        }
    }
    std::cout << std::endl;
    
    {
        std::shared_ptr<Person> andrew = InitFamily("Andrew");
        std::cout << andrew->Name << " ptr shared " << andrew.use_count() << " times\n";
        std::cout << andrew->Mother->Name << " first child is " <<
            andrew->Mother->Kids[0]->Name << std::endl;
    }
    std::cout << std::endl;
    
    {
        std::shared_ptr<Person2> alex = InitFamily2("Alex");
        std::cout << alex->Name << " ptr shared " << alex.use_count() << " times\n";
        
        std::weak_ptr<Person2> momsKid = alex->Mother->Kids[0];
        if (!momsKid.expired())
        {
            std::shared_ptr<Person2> momsKidSharedPtr = momsKid.lock();
            std::cout << alex->Name << " ptr shared " << alex.use_count() << " times\n";
            std::cout << alex->Mother->Name << " first child is " <<
                momsKidSharedPtr->Name << std::endl;
        }
        std::cout << alex->Name << " ptr shared " << alex.use_count() << " times\n";
    }
    std::cout << std::endl;
    
    std::shared_ptr<std::fstream> tmpFile(
        new std::fstream("tmpfile.txt", std::ios::in|std::ios::out|std::ios::app),
        TmpFileGuard("tmpfile.txt"));
    
    *tmpFile << "Hello";
    tmpFile->flush();
    tmpFile->seekg(0, std::ios::beg);
    std::string str;
    *tmpFile >> str;
    std::cout << str << std::endl;
    
    return 0;
}