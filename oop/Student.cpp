#include "Student.h"

#include <cstring>
#include <iostream>

// static field initialization
int Student::g_count = 0;

void Student::IncreaseCount()
{
    ++g_count;
}

void Student::DecreaseCount()
{
    --g_count;
}

int Student::GetStudentCount()
{
    return g_count;
}

Student::Student() :
    m_rating(0)
{
    IncreaseCount();
}

Student::Student(String const& name, int rating) :
    m_name(name),
    m_rating(rating)
{
    IncreaseCount();
}

Student::Student(Student const& student) :
    m_name(student.m_name),
    m_rating(student.m_rating)
{
    IncreaseCount();
}

Student::~Student()
{
    DecreaseCount();
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
    std::cout << m_name << ": " << m_rating << "\n";
}

Student& Student::operator=(Student const& student)
{
    if (this == &student)
    {
        return *this;
    }
    m_rating = student.m_rating;
    m_name = student.m_name;
    return *this;
}