#include "Distance.h"

#include <clocale>
#include <iostream>

int main()
{
    int const count = 5;
    Distance* array = new Distance[count];
    
    ReadArray(array, count);
    std::cout << "Исходный массив:\n";
    PrintArray(array, count);
    BubbleSort(array, count);
    std::cout << "Отсортированный массив:\n";
    PrintArray(array, count);
    
    delete[] array;
    return 0;
}