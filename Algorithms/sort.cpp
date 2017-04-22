#include "sort.h"

#include <iostream>
#include <cstdlib>
#include <time.h>

class Randomizer
{
public:
    Randomizer(int min = 0, int max = 100) :
        m_min(min),
        m_max(max)
    {
        srand(time(NULL));
    };
    
    int GetNext()
    {
        return rand() % (m_max - m_min) + m_min;
    }

private:
    int m_min;
    int m_max;
};

Randomizer randomizer;

void swap(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}

int partition(int* arr, int lo, int hi)
{
    int pivot = (arr[lo] + arr[hi]) / 2;
    int i = lo;
    for (int j = hi; i < j;)
    {
        while (i < j && arr[i] <= pivot)
        {
            ++i;
        }
        while (i < j && arr[j] > pivot)
        {
            --j;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    return i;
}

void qsort(int* arr, int lo, int hi)
{
    if (lo < hi)
    {
        int p = partition(arr, lo, hi);
        qsort(arr, lo, p - 1);
        qsort(arr, p, hi);
    }
}

void qsort(int* arr, int count)
{
    qsort(arr, 0, count - 1);
}

void generate(int* arr, int count)
{
    for (int i = 0; i < count; ++i)
    {
        arr[i] = randomizer.GetNext();
    }
}

void print(int* arr, int count)
{
    for (int i = 0; i < count; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}