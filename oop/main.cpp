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

int main()
{
    ExampleWithStudent();
    return 0;
}