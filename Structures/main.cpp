#include <Data.h>

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctype.h>

typedef bool (*ConditionMatchFunc)(const struct Data*);
typedef int (*CompareTwoDataFunc)(const struct Data*, const struct Data*);

void swap(struct Data** data1, struct Data** data2)
{
    struct Data* tmp = *data1;
    *data1 = *data2;
    *data2 = tmp;
}

void BubbleSortIteration(struct Data** data, int count, CompareTwoDataFunc compare)
{
    for (int i = 1; i < count; ++i)
    {
        if (compare(data[i-1], data[i]) > 0)
        {
            swap(&data[i-1], &data[i]);
        }
    }
}

void BubbleSort(struct Data** data, int count, CompareTwoDataFunc compare)
{
    for (int subCount = count; subCount > 1; --subCount)
    {
        BubbleSortIteration(data, subCount, compare);
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

void PrintByCondition(struct Data** array, int arrayCount, ConditionMatchFunc predicate)
{
    for (int i = 0; i < arrayCount; ++i)
    {
        if ((*predicate)(array[i]))
        {
            PrintData(array[i]);
        }
    }
}

bool SalaryGreater500(const struct Data* data)
{
    return data->Salary > 500;
}

bool NameStartsWithLetterLessThanK(const struct Data* data)
{
    return toupper(data->Name[0]) < 'K';
}

void CompareData(const struct Data* data1, const struct Data* data2, CompareTwoDataFunc compare)
{
    int compareResult = compare(data1, data2);
    if (compareResult)
    {
        if (compareResult < 0)
        {
            printf("%s is less than %s\n", data1->Name, data2->Name);
        }
        else
        {
            printf("%s is greater than %s\n", data1->Name, data2->Name);
        }
    }
    else
    {
        printf("%s equals to %s\n", data1->Name, data2->Name);
    }
}

int CompareDataByName(const struct Data* data1, const struct Data* data2)
{
    return strcmp(data1->Name, data2->Name);
}

int CompareDataBySalary(const struct Data* data1, const struct Data* data2)
{
    if (data1->Salary == data2->Salary)
    {
        return 0;
    }
    return (data1->Salary < data2->Salary) ? -1 : 1;
}

void PrintArray(struct Data** data, int count)
{
    for (int i = 0; i < count; ++i)
    {
        PrintData(data[i]);
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

    printf("Salary greater than 500:\n");
    PrintByCondition(array, count, SalaryGreater500);
    
    printf("Name starts with letter less than K:\n");
    PrintByCondition(array, count, NameStartsWithLetterLessThanK);
    
    struct Data* data1 = ReadData();
    struct Data* data2 = ReadData();
    printf("Compare data by name:\n");
    CompareData(data1, data2, CompareDataByName);
    printf("Compare data by salary:\n");
    CompareData(data1, data2, CompareDataBySalary);
    
    // sort data by name
    BubbleSort(array, count, CompareDataByName);
    PrintArray(array, count);
    
    // sort data by salary
    BubbleSort(array, count, CompareDataBySalary);
    PrintArray(array, count);
    
    for (int i = 0; i < count; ++i)
    {
        free(array[i]);
    }
    
    return 0;
}