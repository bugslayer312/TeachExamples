// Student.h

#pragma once

#include <string>
#include <iostream>

class Student
{
protected:
    std::string m_name;
    int m_rating = 0;
    
public:
    Student() = default;
    Student(std::string name, int rating) : m_name(name), m_rating(rating)
    {
    }
    ~Student()
    {
        std::cout << "Student " << m_name << " destructor\n";
    }
    
    void SetName(std::string const& name)
    {
        m_name = name;
    }
    std::string GetName() const
    {
        return m_name;
    }
    
    void SetRating(int rating)
    {
        m_rating = rating;
    }
    int GetRating() const
    {
        return m_rating;
    }
    
    void Print() const
    {
        std::cout << "name: " << m_name << ", rating: " << m_rating << std::endl;
    }
    
    bool operator<(Student const& other) const
    {
        return m_name < other.m_name;
    }
};

std::ostream& operator<<(std::ostream& stream, Student const& stud)
{
    stream << "[name: " << stud.GetName() << ", rating: " << stud.GetRating() << "]";
    return stream;
}