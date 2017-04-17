#include "Distance.h"

#include <clocale>
#include <iostream>

int main()
{
    Distance d1 = {3, 5.0f};
    Distance d2 = {2, 8.0f};
    Distance summ = Summ(d1, d2);
    Distance diff = Difference(d1, d2);
    
    Print(d1);
    std::cout << " + ";
    Print(d2);
    std::cout << " = ";
    Print(summ);
    std::cout << std::endl;
    
    Print(d1);
    std::cout << " - ";
    Print(d2);
    std::cout << " = ";
    Print(diff);
    std::cout << std::endl;
    return 0;
}