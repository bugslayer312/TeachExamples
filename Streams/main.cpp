#include "Student.h"
#include "Person.h"
#include "Employee.h"

#include <fstream>

void testSave()
{
    PersonList list;
    list.Add(new Student("Ivanov", 8));
    list.Add(new Person("Petrov"));
    list.Add(new Employee("Johan", 10000));
    
    std::ofstream fsave("persons.txt", std::ios::out|std::ios::trunc);
    
    list.SaveToStream(fsave);
}

int main()
{
    try
    {
        PersonList list;
        std::ifstream fload("persons.txt", std::ios::in);
        list.LoadFromStream(fload);
        list.Print();
    }
    catch (std::exception& ex)
    {
        std::cerr << ex.what();
    }
    
    return 0;
}