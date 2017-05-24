#pragma once

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
    void Add(Distance const& d);
    void Deduct(Distance const& d);
    
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
};

//Distance Summ(Distance const& d1, Distance const& d2);
//Distance Diff(Distance const& d1, Distance const& d2);
