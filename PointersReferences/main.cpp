#include "Distance.h"

#include <clocale>
#include <iostream>

int main()
{
    int a = 1;
    int b = 2;

    int& refa = a;
    std::cout << "refa = " << refa << std::endl << std::endl;

    refa = 5;
    std::cout << "refa = " << refa << ", a = " << a << std::endl;
    std::cout << "pointer to refa = " << &refa << ", pointer to a = " << &a << std::endl << std::endl;
    
    refa = b;
    std::cout << "refa = " << refa << ", a = " << a << std::endl;
    std::cout << "pointer to refa = " << &refa << ", pointer to a = " << &a << std::endl;
    std::cout << "pointer to b = " << &b << std::endl << std::endl;
    
    Distance d1 = {2, 6.0f};
    Distance& refd1 = d1;
    refd1.feet += 5;
    std::cout << "d1 = ";
    Print(&d1);
    std::cout << ", refd1 = ";
    Print(&refd1);
    std::cout << std::endl;
    std::cout << "pointer to d1 = " << &d1 << ", pointer to refd1 = " << &refd1 << std::endl;
    
    return 0;
}