#include <Data.h>

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctype.h>

void swap(struct Data** data1, struct Data** data2)
{
    struct Data* tmp = *data1;
    *data1 = *data2;
    *data2 = tmp;
}

void BubbleSortIteration(struct Data** data, int count)
{
    for (int i = 1; i < count; ++i)
    {
        if (strcmp(data[i-1]->Name, data[i]->Name) > 0)
        {
            swap(&data[i-1], &data[i]);
        }
    }
}

void BubbleSort(struct Data** data, int count)
{
    for (int subCount = count; subCount > 1; --subCount)
    {
        BubbleSortIteration(data, subCount);
    }
}

void PrintSalaryGreater500(struct Data** array, int arrayCount)
{
    for (int i = 0; i < arrayCount; ++i)
    {
        if (array[i]->Salary > 500)
        {
            PrintData(array[i]);
        }
    }
}

void PrintNameLessK(struct Data** array, int arrayCount)
{
    for (int i = 0; i < arrayCount; ++i)
    {
        if (toupper(array[i]->Name[0]) < 'K')
        {
            PrintData(array[i]);
        }
    }
}

int main()
{
    int const count = 5;
    struct Data* array[count];
    for (int i = 0; i < count; ++i)
    {
        array[i] = ReadData();
    }
    BubbleSort(array, count);
    for (int i = 0; i < count; ++i)
    {
        struct Data* data = array[i];
        PrintData(data);
        // free(data);
    }
    
    printf("Salary greater than 500:\n");
    PrintSalaryGreater500(array, count);
    
    printf("Name starts with letter less than K:\n");
    PrintNameLessK(array, count);
    
    for (int i = 0; i < count; ++i)
    {
        free(array[i]);
    }
    
    return 0;
}