#include "ArrayUtils.h"

#include <clocale>
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    int const count = 10;
    int* array = (int*)malloc(sizeof(int)*count);
    ReadArray(array, count);
    std::cout << "Исходный массив:\n";
    PrintArray(array, count);
    BubbleSort(array, count);
    std::cout << "Отсортированный массив:\n";
    PrintArray(array, count);
    free(array);
    return 0;
}