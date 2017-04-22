#pragma once

struct Data
{
    char Name[20];
    int Salary;
};

typedef bool (*DataCompareFunc)(const struct Data*);

struct Data* CreateData(char const* name, int salary);
struct Data* ReadData();
void PrintData(struct Data* data);
int CompareByName(const struct Data* d1, const struct Data* d2);