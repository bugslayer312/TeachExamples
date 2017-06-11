#include "Distance.h"

#include <iostream>
#include <cstdlib>

// without using initialization list
/*
Distance::Distance()
{
    m_feet = 0;
    m_inches = 0;
}

Distance::Distance(int feet)
{
    m_feet = feet;
    m_inches = 0;
}

Distance::Distance(int feet, float inches)
{
    m_feet = feet;
    m_inches = inches;
}
*/

// using initialization list

Distance::Distance() :
    m_feet(0),
    m_inches(0)
{
}

Distance::Distance(int feet, float inches) :
    m_feet(feet),
    m_inches(inches)
{
}

// delegating constructors: calling constructor from constructor

Distance::Distance(int feet) :
    Distance(feet, 0)
{
}

int Distance::GetFeet() const
{
    return m_feet;
}

float Distance::GetInches() const
{
    return m_inches;
}

void Distance::SetData(int feet, float inches)
{
    m_feet = feet;
    m_inches = inches;
}

void Distance::Read()
{
    std::cin >> m_feet >> m_inches;
}

void Distance::Print() const
{
    std::cout << m_feet << "\'" << m_inches << "\"" << std::endl;
}

/*void Distance::Add(Distance const& d)
{
    m_feet += d.m_feet;
    m_inches += d.m_inches;
    if (m_inches >= 12.0f)
    {
        m_inches -= 12.0f;
        m_feet += 1;
    }
}

void Distance::Deduct(Distance const& d)
{
    m_feet -= d.m_feet;
    m_inches -= d.m_inches;
    if (m_inches < 0)
    {
        m_inches += 12.0f;
        m_feet -= 1;
    }
}

Distance Summ(Distance const& d1, Distance const& d2)
{
    Distance result = d1;
    result.Add(d2);
    return result;
}

Distance Diff(Distance const& d1, Distance const& d2)
{
    Distance result = d1;
    result.Deduct(d2);
    return result;
}
*/

float Distance::ToInches() const
{
    return m_feet * 12.0f + m_inches;
}

void Distance::operator+=(Distance const& rhs)
{
    m_feet += rhs.m_feet;
    m_inches += rhs.m_inches;
    if (m_inches >= 12.0f)
    {
        m_inches -= 12.0f;
        m_feet += 1;
    }
}

void Distance::operator-=(Distance const& rhs)
{
    m_feet -= rhs.m_feet;
    m_inches -= rhs.m_inches;
    if (m_inches < 0)
    {
        m_inches += 12.0f;
        m_feet -= 1;
    }
}

Distance Distance::operator+(Distance const& rhs)
{
    Distance result = *this;
    result += rhs;
    return result;
}

Distance Distance::operator-(Distance const& rhs)
{
    Distance result = *this;
    result -= rhs;
    return result;
}

bool Distance::operator==(Distance const& rhs) const
{
    return ToInches() == rhs.ToInches();
}

bool Distance::operator!=(Distance const& rhs) const
{
    return !(*this == rhs);
}

bool Distance::operator<=(Distance const& rhs) const
{
    return ToInches() <= rhs.ToInches();
}

bool Distance::operator>(Distance const& rhs) const
{
    return !(*this <= rhs);
}

Distance& Distance::operator++()
{
    ++m_feet;
    return *this;
}

Distance Distance::operator++(int)
{
    Distance copy(*this);
    ++m_feet;
    return copy;
}

float operator/(Distance const& lhs, Distance const& rhs)
{
    return lhs.ToInches()/rhs.ToInches();
}

SquareInches operator*(Distance const& lhs, Distance const& rhs)
{
    return lhs.ToInches()*rhs.ToInches();
}

std::ostream& operator<<(std::ostream& stream, Distance const& d)
{
    stream << d.m_feet << "\'" << d.m_inches << "\"";
    return stream;
}

std::istream& operator>>(std::istream& stream, Distance& d)
{
    char buffer[20];
    stream.getline(buffer, 19);
    char* begin = buffer;
    int feet = strtol(begin, &begin, 10);
    if (*begin != '\'')
    {
        std::cout << "Wrong format\n";
        exit(-1);
    }
    float inches = strtof(++begin, &begin);
    if (*begin != '\"')
    {
        std::cout << "Wrong format\n";
        exit(-1);
    }
    d.m_feet = feet;
    d.m_inches = inches;
    return stream;
}