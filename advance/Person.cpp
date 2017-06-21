#include "Person.h"

#include <iostream>

void Person::SetName(String const& name)
{
    m_name = name;
}

String const& Person::GetName() const
{
    return m_name;
}

void Person::Print() const
{
    std::cout << "Name: " << m_name << std::endl;
}

// PersonList
void PersonList::Add(Person* person)
{
    m_data.push_back(person);
}

void PersonList::Print() const
{
    for (Person* person : m_data)
    {
        person->Print();
    }
}

PersonList::~PersonList()
{
    for (Person* person : m_data)
    {
        delete person;
    }
}