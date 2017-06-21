#pragma once

#include "Person.h"

#include <iostream>

class EmployeeInfo
{
public:
    EmployeeInfo()
    {
        std::cout << "EmployeeInfo constructor\n";
    }
    ~EmployeeInfo()
    {
        std::cout << "EmployeeInfo destructor\n";
    }
};

class Employee : public Person
{
    int m_salary;
    
    EmployeeInfo m_info;
    
public:
    Employee();
    ~Employee();
    int GetSalary() const;
    void SetSalary(int salary);
    void Print() const;
};