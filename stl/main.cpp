// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "Student.h"

#include <sstream>
#include <string>
#include <iostream>
#include <cmath>
#include <exception>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <list>
#include <fstream>
#include <deque>

class CalcException : public std::exception
{
public:
    char const* what() const _NOEXCEPT override
    {
        return "Invalid argument";
    }
};

double CalcSqrt(double value)
{
    if (value < 0)
    {
        throw CalcException();
    }
    return sqrt(value);
}

void Sort(int* array, int count)
{
    
}

void lesson_09_07_2017()
{
    /*std::string str = "type:student name:Ivanov rating:8";
     std::istringstream is(str);
     std::string buf;
     while (!is.eof())
     {
     is >> buf;
     std::istringstream is2(buf);
     char part[1024];
     is2.getline(part, 1024, ':');
     std::cout << "key=" << part;
     is2.getline(part, 1024, ':');
     std::cout << ", value=" << part << std::endl;
     }
     
     double val = -6;
     try
     {
     double res = CalcSqrt(val);
     std::cout << res << std::endl;
     }
     catch (std::exception& ex)
     {
     std::ostringstream os;
     os << "Error in function CalcSqrt()" <<
     ", argument: " << val << ", :" <<
     ex.what();
     std::cout << os.str() << std::endl;
     }
     
     std::ostringstream os1;
     os1 << 5 << " + " << 6 << " = " << (5 + 6);
     std::cout << os1.str() << std::endl;
     
     std::istringstream is1("123");
     int a;
     is1 >> a;
     std::cout << a + 1 << std::endl; */
    
    std::vector<int> v;
    for (int i = 1; i < 10; ++i)
    {
        v.push_back(i);
    }
    
    //std::copy(v.begin(), v.end(),
    //	std::ostream_iterator<int>(std::cout, " "));
    
    std::vector<int> v1 = { 1, 19, 20 };
    std::vector<int> v2(std::move(v1));
    std::copy(v2.begin(), v2.end(),
              std::ostream_iterator<int>(std::cout, " "));
    
    std::cout << std::endl;
    
    std::vector<int> v3(v.begin(), v.begin() + 5);
    std::copy(v3.begin(), v3.end(),
              std::ostream_iterator<int>(std::cout, " "));
    
    std::cout << std::endl;
    
    std::cout << v3.front() << " " << v3.back()
    << std::endl;
    
    std::cout << v3.size() << " " << v3.capacity()
    << std::endl;
    v3.push_back(0);
    std::cout << v3.size() << " " << v3.capacity()
    << std::endl;
    
    v3.reserve(20);
    v3.resize(15);
    std::copy(v3.begin(), v3.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::cout << v3.size() << " " << v3.capacity()
    << std::endl;
    std::cout << std::endl;
    
    std::vector<int>::reverse_iterator it = v3.rbegin();
    for (; it != v3.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::copy(v3.rbegin(), v3.rend(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    int* array = &v3[0];
    int* array1 = &v3.front();
    int* array2 = v3.data();
    Sort(v3.data(), v3.size());
    
    v3.insert(v3.begin() + 1, 100);
    std::copy(v3.begin(), v3.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    std::vector<int>::iterator it1 = v3.insert(v3.begin() + 5, 5, 500);
    std::copy(v3.begin(), v3.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    std::cout << std::distance(v3.begin(), it1)
    << std::endl;
    
    it1 = v3.erase(it1);
    std::copy(v3.begin(), v3.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    v3.erase(it1, it1 + 5);
    std::copy(v3.begin(), v3.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    for (std::vector<int>::iterator i = v3.begin();
         i != v3.end();)
    {
        if ((*i % 2) == 0)
        {
            i = v3.erase(i);
        }
        else
        {
            ++i;
        }
    }
    std::copy(v3.begin(), v3.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    v3.insert(v3.begin(), 0);
    v3.insert(v3.begin() + 2, 0);
    v3.resize(10);
    v3.insert(v3.end(), 5, 100);
    std::copy(v3.begin(), v3.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    /*auto it4 = std::remove(v3.begin(), v3.end(), 0);
     std::copy(v3.begin(), v3.end(),
     std::ostream_iterator<int>(std::cout, " "));
     std::cout << std::endl;
     
     std::cout << std::distance(v3.begin(), it4)
     << std::endl;
     
     v3.erase(it4, v3.end());*/
    v3.erase(std::remove(v3.begin(), v3.end(), 0), v3.end());
    std::copy(v3.begin(), v3.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    std::vector<int> v4;
    v4.reserve(100);
    v4.insert(v4.begin(), { 1, 3, 4, 5 });
    std::cout << v4.size() << " " << v4.capacity()
    << std::endl;
    v4.shrink_to_fit();
    std::cout << v4.size() << " " << v4.capacity()
    << std::endl;
    
    for (std::size_t i = 0; i < v4.size(); ++i)
    {
        std::cout << v4[i] << " ";
    }
    
    std::vector<int> v5 = { 1, 2, 7, 34, 7, 3, 40 };
    std::copy(v5.begin(), v5.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    std::function<bool(int&)> lambda = [](int& el)
    {
        return (el % 2) != 0;
    };
    
    auto it5 = std::remove_if(v5.begin(), v5.end(), lambda);
    v5.erase(it5, v5.end());
    std::copy(v5.begin(), v5.end(),
              std::ostream_iterator<int>(std::cout, " "));
}

void lesson_10_07_2017()
{
    std::vector<int> v = { 1, 3, 7, 4, 40, 23, 15, 9, 3 };
    
    int min = 10;
    int max = 25;
    
    std::function<bool(int&)> lambda = [&min, &max](int& el)
    {
        return el >= min && el <= max;
    };
    
    auto it = std::remove_if(v.begin(), v.end(), lambda);
    v.erase(it, v.end());
    std::copy(v.begin(), v.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    it = std::remove(v.begin(), v.end(), 3);
    v.erase(it, v.end());
    std::copy(v.begin(), v.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    min = 0;
    max = 10;
    std::copy_if(v.begin(), v.end(),
                 std::ostream_iterator<int>(std::cout, " "), lambda);
    std::cout << std::endl;
    
    std::vector<Student> students = { Student("Ivanov", 5),
        Student("Azarenko", 8), Student("Kozlov", 8),
        Student("Eroshenko", 3), Student("Belkin", 4),
        Student("Shukherman", 6)
    };
    
    std::sort(students.begin(), students.end());
    
    for (auto it = students.begin(); it != students.end(); ++it)
    {
        it->Print();
    }
    
    std::function<bool(Student const&, Student const&)> compareByRating =
    [](Student const& st1, Student const& st2)
    {
        return st1.GetRating() < st2.GetRating();
    };
    
    std::cout << "====================================\n";
    
    std::sort(students.begin(), students.end(), compareByRating);
    
    for (auto it = students.begin(); it != students.end(); ++it)
    {
        it->Print();
    }
    
    std::sort(students.begin(), students.end(), std::greater<Student>());
    for (auto it = students.begin(); it != students.end(); ++it)
    {
        it->Print();
    }
    
    std::list<int> list = { 2, 6, 4, 8, 25, 14, 4, 8, 4, 7 };
    
    std::list<int>::iterator startIt = list.begin();
    std::advance(startIt, 5);
    
    std::list<int>::iterator it1 = std::find(startIt, list.end(), 4);
    
    if (it1 != list.end())
    {
        std::cout << std::distance(list.begin(), it1) + 1 << std::endl;
        std::cout << *it1 << std::endl;
    }
    else
    {
        std::cout << "not found\n";
    }
    
    list.push_front(5);
    list.push_front(10);
    
    std::copy(list.begin(), list.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl << std::endl;
    
    auto listLambda = [](int const& el)
    {
        return el >= 10;
    };
    
    list.remove_if(listLambda);
    std::copy(list.begin(), list.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl << std::endl;
    
    // std::sort(list.begin(), list.end());
    list.sort();
    std::copy(list.begin(), list.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl << std::endl;
    
    auto isGreater = [](int& el1, int& el2)
    {
        return el1 > el2;
    };
    
    list.sort(isGreater);
    std::copy(list.begin(), list.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl << std::endl;
    
    /*auto remainerEquals = [](int& el1, int& el2)
     {
     return (el1 % 3) == (el2 % 3);
     }; */
    
    // list.unique(remainerEquals);
    list.unique();
    std::copy(list.begin(), list.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl << std::endl;
    
    std::istringstream is("10 23 5 7 8 4");
    std::vector<int> v3;
    v3.resize(10);
    std::copy(std::istream_iterator<int>(is),
              std::istream_iterator<int>(),
              v3.begin());
    
    std::copy(v3.begin(), v3.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl << std::endl;
}

void _transform()
{
    std::vector<int> v1 = { 2, 4, 7, 9 };
    std::copy(v1.begin(), v1.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    std::vector<int> v2 = { 5, 6, 0, 1 };
    std::copy(v2.begin(), v2.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    std::function<int(int)> _sqr = [](int a)
    {
        return a * a;
    };
    
    std::vector<int> result;
    
    std::transform(v1.begin(), v1.end(),
                   std::back_inserter(result), _sqr);
    
    std::copy(result.begin(), result.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    /* std::function<int(int)> _mult = [](int a, int b)
     {
     return a * b;
     }; */
    
    //std::transform(v1.begin(), v1.end(),
    //	v2.begin(), result.begin(), _mult);
}

void createFile()
{
    std::ofstream os("song.txt", std::ios::out | std::ios::trunc);
    os << "we all live in a yellow submarine yellow submarine yellow submarine";
}

int Summ(int a, int b, int c)
{
    return a + b + c;
}

bool less(int a, int b)
{
    return a < b;
}

int main()
{
    // lesson_09_07_2017();
    // lesson_10_07_2017();
    
    // createFile();
    
    std::vector<std::string> words;
    
    std::ifstream is("song.txt", std::ios::in);
    
    /* while (!is.eof())
     {
     std::string buffer;
     is >> buffer;
     words.push_back(buffer);
     } */
    
    std::function<bool(std::string const&)> lambda = [](std::string const& st)
    {
        char buff = st[0];
        if (buff == 'a' || buff == 'e' || buff == 'y'
            || buff == 'u' || buff == 'i'
            || buff == 'o')
        {
            return true;
        }
        else
        {
            return false;
        }
        
    };
    
    //std::copy_if(std::istream_iterator<std::string>(is),
    //	std::istream_iterator<std::string>(),
    //	std::back_inserter(words), lambda);
    std::copy(std::istream_iterator<std::string>(is),
              std::istream_iterator<std::string>(),
              std::back_inserter(words));
    auto iter = std::remove_if(words.begin(), words.end(), std::not1(lambda));
    words.erase(iter, words.end());
    
    std::copy(words.begin(), words.end(),
              std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
    
    auto it = std::unique(words.begin(), words.end());
    
    words.erase(it, words.end());
    
    std::copy(words.begin(), words.end(),
              std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
    
    auto lambda2 = [](std::string const& w1, std::string const& w2)
    {
        return w1.size() < w2.size();
    };
    
    std::sort(words.begin(), words.end(), lambda2);
    
    std::copy(words.begin(), words.end(),
              std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
    
    std::deque<Student> d;
    d.push_front(Student("Ivanov", 7));
    d.push_front(Student("Azarenko", 5));
    d.push_front(Student("Petrov", 3));
    
    auto printStudent = [](Student const& st)
    {
        st.Print();
    };
    
    //std::for_each(d.begin(), d.end(),
    //	printStudent);
    
    std::for_each(d.begin(), d.end(),
                  std::bind(&Student::Print,
                            std::placeholders::_1));
    
    /*std::function<int(int,int,int)> summ3 =
     Summ;
     
     int a = summ3(1, 2, 3);
     
     std::function<int(int, int)> summ2 =
     std::bind(summ3, std::placeholders::_1,
     std::placeholders::_2, 0);
     
     a = summ2(1, 2);
     
     std::function<bool(int, int)> greater =
     std::bind(less, std::placeholders::_2,
     std::placeholders::_1); */
    
    std::sort(d.begin(), d.end(), std::less<Student>());
    std::for_each(d.begin(), d.end(),
                  std::bind(&Student::Print,
                            std::placeholders::_1));
    std::cout << std::endl;
    
    std::sort(d.begin(), d.end(), std::bind(std::less<Student>(),
                                            std::placeholders::_2, std::placeholders::_1));
    std::for_each(d.begin(), d.end(),
                  std::bind(&Student::Print,
                            std::placeholders::_1));
    std::cout << std::endl;
    
    std::vector<int> v = { 1, 11, 15, 19, 21, 3 };
    
    std::copy_if(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "),
                 std::bind(std::logical_and<bool>(),
                           std::bind(std::greater<int>(), std::placeholders::_1, 10),
                           std::bind(std::less<int>(), std::placeholders::_1, 20)));
    std::cout << std::endl;
    
    std::deque<std::string> names = { "Kozlov", "Eroshenko", "Shukherman" };
    
    std::vector<Student> students;
    
    int rating = 6;
    
    std::function<Student(std::string const&)> createStudent =
    [&rating](std::string const& name)
    {
        return Student(name, rating);
    };
    
    std::transform(names.begin(), names.end(),
                   std::back_inserter(students), createStudent);
    std::for_each(students.begin(), students.end(),
                  std::bind(&Student::Print,
                            std::placeholders::_1));
    
    return 0;
}

// https://pastebin.com/m3rhBc15