#include "Data.h"

#include <cstdlib>
#include <cstring>
#include <iostream>

struct Data* CreateData(char const* name, int salary)
{
    struct Data* result = (struct Data*)malloc(sizeof(struct Data));
    strncpy(result->Name, name, 20);
    result->Salary = salary;
    return result;
}

struct Data* ReadData()
{
    struct Data* result = (struct Data*)malloc(sizeof(struct Data));
    std::cout << "Enter name and salary" << std::endl;
    std::cin >> result->Name >> result->Salary;
    return result;
}

void PrintData(struct Data* data)
{
    std::cout << "Name: " << data->Name << ", Salary: " << data->Salary << std::endl;
}

int CompareByName(const struct Data* d1, const struct Data* d2)
{
    return strcmp(d1->Name, d2->Name);
}