#include "Person.h"
#include "Student.h"
#include "Employee.h"

#include <iostream>
#include <map>
#include <cstring>

Person* ReadPerson(char* buffer)
{
    std::cout << buffer << std::endl;
    std::map<std::string, std::string> params;
    
    char* str = strtok(buffer, " ");
    while (str)
    {
        std::string part(str);
        std::string::size_type pos = part.find(':');
        if (pos == std::string::npos)
        {
            throw PersonReadException("Invalid format");
        }
        //std::cout << part << std::endl;
        //std::cout << part.substr(0, pos) << "  " << part.substr(pos + 1, part.length() - pos) << std::endl;
        params[part.substr(0, pos)] = part.substr(pos + 1, part.length() - pos - 1);
        str = strtok(NULL, " ");
    }
    if (params.find("type") != params.end() && params.find("name") != params.end())
    {
        std::string type = params["type"];
        std::string name = params["name"];
        if (type == "person")
        {
            return new Person(name);
        }
        else if (type == "student")
        {
            if (params.find("rating") == params.end())
            {
                throw PersonReadException("Not found rating field");
            }
            int rating = atoi(params["rating"].c_str());
            return new Student(name, rating);
        }
        else if (type == "employee")
        {
            if (params.find("salary") == params.end())
            {
                throw PersonReadException("Not found salary field");
            }
            int salary = atoi(params["salary"].c_str());
            return new Employee(name, salary);
        }
    }
    throw PersonReadException("Not found type and name fields");
}

Person::Person(std::string const& name) :
    m_name(name)
{
}

std::string Person::GetType() const
{
    return "person";
}

void Person::SaveToStream(std::ostream& stream) const
{
    stream << "type:" << GetType() << " name:" << GetName();
}

void Person::SetName(std::string const& name)
{
    m_name = name;
}

std::string const& Person::GetName() const
{
    return m_name;
}

void Person::Print() const
{
    std::cout << "Name: " << m_name << std::endl;
}

std::ostream& operator<<(std::ostream& stream, Person const& person)
{
    person.SaveToStream(stream);
    return stream;
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

void PersonList::SaveToStream(std::ostream& stream)
{
    bool first = true;
    for (Person* person : m_data)
    {
        if (first)
        {
            first = !first;
        }
        else
        {
            stream << std::endl;
        }
        stream << *person;
    }
}

void PersonList::LoadFromStream(std::istream& stream)
{
    char buffer[1024];
    while (!stream.eof())
    {
        stream.getline(buffer, 1024);
        Person* person = ReadPerson(buffer);
        m_data.push_back(person);
    }
}

PersonList::~PersonList()
{
    for (Person* person : m_data)
    {
        delete person;
    }
}