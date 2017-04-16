#include "ArrayUtils.h"

#include <iostream>

void Swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void PushMaxToTop(int* array, int count)
{
    for (int i = 1; i < count; ++i)
    {
        int* current = &array[i];
        int* previous = current - 1;
        if (*previous > *current)
        {
            Swap(previous, current);
        }
    }
}

void BubbleSort(int* array, int count)
{
    for (int subCount = count; subCount > 1; --subCount)
    {
        PushMaxToTop(array, subCount);
    }
}

void ReadArray(int* array, int count)
{
    for (int i = 0; i < count; ++i)
    {
        std::cout << "Введите число: ";
        std::cin >> array[i];
    }
}

void PrintArray(int* array, int count)
{
    for (int i = 0; i < count; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}