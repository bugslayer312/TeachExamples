#pragma once

#include "Person.h"
#include "String.h"

class Student : public Person
{
private:
    int m_rating;

public:
    Student();
    Student(String const& name, int rating);
    Student(Student const& student);
    Student(Student&& student);
    ~Student();

    String const& GetName() const;
    int GetRating() const;

    void SetName(String const& name);
    void SetRating(int rating);

    void Read();
    void Print() const;

    Student& operator=(Student const& student);
    Student& operator=(Student&& student);
};