#pragma once

#include <list>
#include "String.h"

class Person
{
protected:
    String m_name;
    
public:
    void SetName(String const& name);
    String const& GetName() const;
    
    void Print() const;
};

class PersonList
{
    std::list<Person*> m_data;
    
public:
    ~PersonList();
    void Add(Person* person);
    void Print() const;
};