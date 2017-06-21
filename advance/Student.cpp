#include "Student.h"

#include <cstring>
#include <iostream>


Student::Student() :
    m_rating(0)
{
    std::cout << "Student default constructor\n";
}

Student::Student(String const& name, int rating) :
    m_rating(rating)
{
    m_name = name;
    std::cout << "Student constructor with param\n";
}

Student::Student(Student const& student) :
    m_rating(student.m_rating)
{
    m_name = student.m_name;
    std::cout << "Student copy constructor\n";
}

Student::Student(Student&& student):
    m_rating(student.m_rating)
{
    m_name = std::move(student.m_name);
    std::cout << "Student move constructor\n";
}

Student::~Student()
{
    std::cout << "Student destructor\n";
}

String const& Student::GetName() const
{
    return m_name;
}

int Student::GetRating() const
{
    return m_rating;
}

void Student::SetName(String const& name)
{
    m_name = name;
}

void Student::SetRating(int rating)
{
    m_rating = rating;
}

void Student::Read()
{
    std::cout << "Enter name: ";
    char buffer[21];
    std::cin.getline(buffer, 20);
    m_name = buffer;
    std::cout << "Enter rating: ";
    std::cin >> m_rating;
}

void Student::Print() const
{
    Person::Print();
    std::cout << "Rating: " << m_rating << std::endl;
}

Student& Student::operator=(Student const& student)
{
    if (this != &student)
    {
        m_rating = student.m_rating;
        m_name = student.m_name;
    }
    return *this;
}

Student& Student::operator=(Student&& student)
{
    if (this != &student)
    {
        m_name = std::move(student.m_name);
        m_rating = student.m_rating;
    }
    return *this;
}