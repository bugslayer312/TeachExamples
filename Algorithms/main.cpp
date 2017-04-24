#include "sort.h"

#include <iostream>

int main()
{
    int const count = 100000;
    int array[count];
    for (int i = 0; i < 50; ++i)
    {
        generate(array, count);
        qsort2(array, count);
        std::cout << "Test " << (testIncreasing(array, count) ? "passed" : "failed") << std::endl;
    }
    // print(array, count);
    return 0;
}