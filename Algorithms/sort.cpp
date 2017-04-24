#include "sort.h"

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>

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

struct Bounds
{
    uint32_t Left;
    uint32_t Right;
};

struct BoundsStack
{
    Bounds* data;
    uint32_t top;
    uint32_t size;
};

struct BoundsStack* CreateStack(uint32_t size)
{
    struct BoundsStack* result = (struct BoundsStack*)malloc(sizeof(struct BoundsStack));
    result->data = (struct Bounds*)malloc(sizeof(struct Bounds) * size);
    result->size = size;
    result->top = 0;
    return result;
}

void FreeStack(struct BoundsStack* stack)
{
    free(stack->data);
    free(stack);
}

void Push(struct BoundsStack* stack, struct Bounds bounds)
{
    if (stack->top < stack->size)
    {
        stack->data[stack->top++] = bounds;
    }
    else
    {
        std::cout << "Stack is full\n";
    }
}

struct Bounds Pop(struct BoundsStack* stack)
{
    if (stack->top > 0)
    {
        return stack->data[--stack->top];
    }
    std::cout << "Stack is empty\n";
    return {0, 0};
}

bool IsEmpty(const struct BoundsStack* stack)
{
    return stack->top <= 0;
}

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

void qsort2(int* arr, int count)
{
    //int stackMax = 1;
    struct BoundsStack* stack = CreateStack(log2l(count) * 2);
    
    struct Bounds bounds = {0, count - 1};
    Push(stack, bounds);
    while (!IsEmpty(stack))
    {
        bounds = Pop(stack);
        int left = bounds.Left;
        int right = bounds.Right;
        while (left < right)
        {
            int p = partition(arr, left, right);
            if (p < right)
            {
                bounds.Left = p;
                bounds.Right = right;
                Push(stack, bounds);
                //if (stack->top > stackMax)
                //{
                //    stackMax = stack->top;
                //}
            }
            right = p - 1;
        }
    }
    
    // std::cout << "Stack usage: " << stackMax << " of " << stack->size << "\n";
    FreeStack(stack);
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

bool testIncreasing(int* arr, int count)
{
    for (int i = 0; i < count - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}