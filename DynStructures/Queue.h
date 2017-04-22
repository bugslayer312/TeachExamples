#pragma once

#include "Data.h"

struct Queue
{
    struct Data** FirstChunk;
    struct Data** SecondChunk;
    unsigned int size;
    unsigned int bottom;
    unsigned int top;
};

struct Queue* CreateQueue(unsigned int size);
void DestroyQueue(struct Queue* queue);
void Push(struct Queue* queue, struct Data* data);
struct Data* Pop(struct Queue* queue);
unsigned int GetCount(const struct Queue* queue);
bool IsEmpty(const struct Queue* queue);