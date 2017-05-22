#pragma once

class Distance
{
private:
    int m_feet;
    float m_inches;
    
public:
    int GetFeet();
    float GetInches();
    void SetData(int feet, float inches);
    void Read();
    void Print();
    void Add(Distance const& d);
    void Deduct(Distance const& d);
};

Distance Summ(Distance const& d1, Distance const& d2);
Distance Diff(Distance const& d1, Distance const& d2);