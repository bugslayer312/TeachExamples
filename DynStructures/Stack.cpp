#include "Stack.h"

#include <cstdlib>
#include <iostream>

struct Stack* CreateStack(unsigned int size)
{
    struct Stack* result = (struct Stack*)malloc(sizeof(Stack));
    result->bottom = (struct Data**)malloc(sizeof(struct Data*) * size);
    result->size = size;
    result->pos = 0;
    return result;
}

void DestroyStack(struct Stack* stack)
{
    free(stack->bottom);
    free(stack);
}

void Push(struct Stack* stack, Data* data)
{
    if (stack->pos < stack->size)
    {
        stack->bottom[stack->pos] = data;
        ++stack->pos;
    }
    else
    {
        std::cout << "Stack is full" << std::endl;
    }
}

Data* Top(const struct Stack* stack)
{
    if (stack->pos > 0)
    {
        return stack->bottom[stack->pos - 1];
    }
    return NULL;
}

Data* Pop(struct Stack* stack)
{
    if (stack->pos > 0)
    {
        return stack->bottom[--stack->pos];
    }
    return NULL;
}

int GetCount(const struct Stack* stack)
{
    return stack->pos;
}

bool IsEmpty(const struct Stack* stack)
{
    return stack->pos <= 0;
}