#include "Student.h"

#include <cstring>
#include <iostream>


Student::Student() :
    Person(),
    m_rating(0)
{
}

Student::Student(std::string const& name, int rating) :
    Person(name),
    m_rating(rating)
{
}

Student::Student(Student const& student) :
    Person(student),
    m_rating(student.m_rating)
{
}

Student::Student(Student&& student):
    m_rating(student.m_rating)
{
    m_name = std::move(student.m_name);
}

Student::~Student()
{
}

std::string Student::GetType() const
{
    return "student";
}

void Student::SaveToStream(std::ostream& stream) const
{
    Person::SaveToStream(stream);
    stream << " rating:" << m_rating;
}

int Student::GetRating() const
{
    return m_rating;
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