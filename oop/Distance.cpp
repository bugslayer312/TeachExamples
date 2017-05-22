#include "Distance.h"

#include <iostream>

int Distance::GetFeet()
{
    return m_feet;
}

float Distance::GetInches()
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

void Distance::Print()
{
    std::cout << m_feet << "\'" << m_inches << "\"" << std::endl;
}

void Distance::Add(Distance const& d)
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