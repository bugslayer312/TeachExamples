#pragma once

#include <list>
#include <string>
#include <iosfwd>
#include <exception>

class PersonReadException : public std::exception
{
    std::string m_error;
public:
    PersonReadException(char const* error):
        m_error(error)
    {
    }
    const char* what() const noexcept override
    {
        return (std::string("Person read exception") + m_error).c_str();
    }
};

class Person
{
protected:
    std::string m_name;
    
    virtual std::string GetType() const;
    virtual void SaveToStream(std::ostream& stream) const;
    
public:
    Person() = default;
    Person(std::string const& name);
    virtual ~Person() = default;
    
    void SetName(std::string const& name);
    std::string const& GetName() const;
    
    friend std::ostream& operator<<(std::ostream& stream, Person const& person);
    
    virtual void Print() const;
};

std::ostream& operator<<(std::ostream& stream, Person const& person);

class PersonList
{
    std::list<Person*> m_data;
    
public:
    ~PersonList();
    void Add(Person* person);
    void Print() const;
    void SaveToStream(std::ostream& stream);
    void LoadFromStream(std::istream& stream);
};