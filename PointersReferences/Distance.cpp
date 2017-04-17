#include "Distance.h"

#include <iostream>

void Add(Distance& d1, Distance const& d2)
{
    d1.feet += d2.feet;
    d1.inches += d2.inches;
    if (d1.inches >= 12.0f)
    {
        d1.feet += 1;
        d1.inches -= 12.0f;
    }
}

void Substract(Distance& d1, Distance const& d2)
{
    d1.feet -= d2.feet;
    d1.inches -= d2.inches;
    if (d1.inches < 0)
    {
        d1.inches += 12.0f;
        d1.feet -= 1;
    }
}

Distance Summ(Distance const& d1, Distance const& d2)
{
    Distance result = d1;
    Add(result, d2);
    return result;
}

Distance Difference(Distance const& d1, Distance const& d2)
{
    Distance result = d1;
    Substract(result, d2);
    return result;
}

Distance Read()
{
    Distance result;
    std::cout << "feet: ";
    std::cin >> result.feet;
    std::cout << "inches: ";
    std::cin >> result.inches;
    return result;
}

void Print(Distance const& value)
{
    std::cout << value.feet << "\'" << value.inches << "\"";
}

void ReadArray(Distance* array, int count)
{
    for (int i = 0; i < count; ++i)
    {
        array[i] = Read();
    }
}

void PrintArray(Distance* array, int count)
{
    for (int i = 0; i < count; ++i)
    {
        Print(array[i]);
        std::cout << " ";
    }
    std::cout << std::endl;
}

void Swap(Distance& a, Distance& b)
{
    Distance c = a;
    a = b;
    b = c;
}

bool IsGreater(Distance const& a, Distance const& b)
{
    return (a.feet > b.feet) || (a.feet == b.feet && a.inches > b.inches);
}

void PushMaxToTop(Distance* array, int count)
{
    for (int i = 1; i < count; ++i)
    {
        Distance& current = array[i];
        Distance& previous = array[i - 1];
        if (IsGreater(previous, current))
        {
            Swap(previous, current);
        }
    }
}

void BubbleSort(Distance* array, int count)
{
    for (int subCount = count; subCount > 1; --subCount)
    {
        PushMaxToTop(array, subCount);
    }
}