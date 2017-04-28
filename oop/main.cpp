#include <iostream>

// Объявление класса
class Distance
{
private:
    int m_feet;
    float m_inches;
    
public:
    int GetFeet();
    float GetInches();
    void SetData(int feet, float inches);
    void PrintData();
};

// Реализация методов класса
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
void Distance::PrintData()
{
    std::cout << m_feet << "\'" << m_inches << "\"" << std::endl;
}

struct Distance2
{
    // по умолчанию открытый доступ
    int Feet;
    float Inches;
    
    void PrintData()
    {
        std::cout << Feet << "\'" << Inches << "\"" << std::endl;
    }
};

int main()
{
    Distance d; // создается d - объект класса Distance
    d.SetData(5, 2.0f);
    // d.m_feet = 4; ЗАПРЕЩЕНО, т. к. закрыт доступ
    d.PrintData();
    std::cout << "Feet count = " << d.GetFeet() << std::endl;
    return 0;
}