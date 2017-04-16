#pragma once

struct Distance
{
    int feet;
    float inches;
};

void Add(Distance* d1, Distance const* d2);
void Substract(Distance* d1, Distance const* d2);
Distance Summ(Distance const* d1, Distance const* d2);
Distance Difference(Distance const* d1, Distance const* d2);
Distance Read();
void Print(Distance const* value);

void ReadArray(Distance* array, int count);
void PrintArray(Distance* array, int count);
void BubbleSort(Distance* array, int count);