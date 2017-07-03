#pragma once

#include "Person.h"

#include <iostream>

class Employee : public Person
{
    int m_salary;
    
protected:
    std::string GetType() const override;
    void SaveToStream(std::ostream& stream) const override;
    
public:
    Employee(std::string const& name, int salary);
    int GetSalary() const;
    void SetSalary(int salary);
    void Print() const override;
};