#include "Queue.h"

#include <cstdlib>
#include <iostream>

struct Queue* CreateQueue(unsigned int size)
{
    struct Queue* result = (struct Queue*)malloc(sizeof(struct Queue*));
    result->FirstChunk = (struct Data**)malloc(sizeof(struct Data*) * size);
    result->SecondChunk = (struct Data**)malloc(sizeof(struct Data*) * size);
    result->size = size;
    result->bottom = 0;
    result->top = 0;
    return result;
}

void DestroyQueue(struct Queue* queue)
{
    free(queue->FirstChunk);
    free(queue->SecondChunk);
    free(queue);
}

void Push(struct Queue* queue, struct Data* data)
{
    unsigned int count = queue->top - queue->bottom;
    if (count < queue->size)
    {
        if (queue->top >= queue->size)
        {
            queue->SecondChunk[queue->top % queue->size] = data;
        }
        else
        {
            queue->FirstChunk[queue->top] = data;
        }
        ++queue->top;
    }
    else
    {
        std::cout << "Queue is full" << std::endl;
    }
}

struct Data* Pop(struct Queue* queue)
{
    if (queue->bottom < queue->top)
    {
        struct Data* result = queue->FirstChunk[queue->bottom];
        ++queue->bottom;
        if (queue->bottom >= queue->size)
        {
            struct Data** tmp = queue->FirstChunk;
            queue->FirstChunk = queue->SecondChunk;
            queue->SecondChunk = tmp;
            queue->bottom -= queue->size;
            queue->top -= queue->size;
        }
        return result;
    }
    return NULL;
}

unsigned int GetCount(const struct Queue* queue)
{
    return queue->top - queue->bottom;
}

bool IsEmpty(const struct Queue* queue)
{
    return queue->top <= queue->bottom;
}