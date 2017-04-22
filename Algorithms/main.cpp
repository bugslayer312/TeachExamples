#include "sort.h"

#include <iostream>

int main()
{
    int const count = 30;
    int array[count];
    generate(array, count);
    qsort(array, count);
    print(array, count);
    return 0;
}