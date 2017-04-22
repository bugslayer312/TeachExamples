#pragma once

#include "Data.h"

struct Stack
{
    Data** bottom;
    int pos;
    unsigned int size;
};

struct Stack* CreateStack(unsigned int size);
void DestroyStack(struct Stack* stack);
void Push(struct Stack* stack, Data* data);
Data* Top(const struct Stack* stack);
Data* Pop(struct Stack* stack);
int GetCount(const struct Stack* stack);
bool IsEmpty(const struct Stack* stack);
