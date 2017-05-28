#include "Distance.h"
#include "Student.h"

#include <iostream>

/*
class Distance
{
private:
    int m_feet;
    float m_inches;
    
public:
    int GetFeet()
    {
        return m_feet;
    };
    float GetInches()
    {
        return m_inches;
    };
    void SetData(int feet, float inches)
    {
        m_feet = feet;
        m_inches = inches;
    };
    void Read()
    {
        std::cin >> m_feet >> m_inches;
    };
    void Print()
    {
        std::cout << m_feet << "\'" << m_inches << "\"" << std::endl;
    };
};
*/

void ExampleWithStudent()
{
    Student st1("Ivanov", 6.0f);
    Student st2 = st1;
    st2.SetName("Petrov");
    st1.Print();
    st2.Print();
}

void ExampleWithDistance()
{
    std::cout << "Enter first distance: ";
    Distance d1;
    std::cin >> d1;
    std::cout << "Enter second distance: ";
    Distance d2;
    std::cin >> d2;
    Distance d3 = d1 + d2;
    std::cout << "Summ: " << d3 << "\n";
}

int main()
{
    // ExampleWithStudent();
    ExampleWithDistance();
    return 0;
}