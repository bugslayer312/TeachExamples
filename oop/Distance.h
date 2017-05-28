#pragma once

#include <iosfwd>

class SquareInches;

class Distance
{
private:
    int m_feet;
    float m_inches;
    
    float ToInches() const;
    
public:
    Distance();
    Distance(int feet);
    Distance(int feet, float inches);
    
    int GetFeet() const;
    float GetInches() const;
    void SetData(int feet, float inches);
    void Read();
    void Print() const;
    //void Add(Distance const& d);
    //void Deduct(Distance const& d);
    
    void operator+=(Distance const& rhs);
    void operator-=(Distance const& rhs);
    
    Distance operator+(Distance const& rhs);
    Distance operator-(Distance const& rhs);
    
    bool operator==(Distance const& rhs) const;
    bool operator!=(Distance const& rhs) const;
    bool operator<=(Distance const& rhs) const;
    bool operator>(Distance const& rhs) const;
    
    Distance& operator++();
    Distance operator++(int);
    
    friend float operator/(Distance const& lhs, Distance const& rhs);
    friend SquareInches operator*(Distance const& lhs, Distance const& rhs);
    friend std::ostream& operator<<(std::ostream& stream, Distance const& d);
    friend std::istream& operator>>(std::istream& stream, Distance& d);
};

class SquareInches
{
private:
    float m_value;
    
public:
    SquareInches(float value): m_value(value)
    {
    }
    
    inline float GetValue() const
    {
        return m_value;
    }
};

float operator/(Distance const& lhs, Distance const& rhs);
SquareInches operator*(Distance const& lhs, Distance const& rhs);
std::ostream& operator<<(std::ostream& stream, Distance const& d);
std::istream& operator>>(std::istream& stream, Distance& d);
