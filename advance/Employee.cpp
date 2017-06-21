#include "Employee.h"

Employee::Employee()
{
    std::cout << "Employee default constructor\n";
}

Employee::~Employee()
{
    std::cout << "Employee destructor\n";
}

int Employee::GetSalary() const
{
    return m_salary;
}

void Employee::SetSalary(int salary)
{
    m_salary = salary;
}

void Employee::Print() const
{
    Person::Print();
    std::cout << "Salary: " << m_salary << std::endl;
}