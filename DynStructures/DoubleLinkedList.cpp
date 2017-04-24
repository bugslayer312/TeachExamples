#include "DoubleLinkedList.h"

#include <cstdlib>

struct List2Node* CreateDoubleLinkedList(struct Data* listData)
{
    struct List2Node* result = (struct List2Node*)malloc(sizeof(struct List2Node));
    result->ListData = listData;
    result->Prev = NULL;
    result->Next = NULL;
    return result;
}

void Destroy(struct List2Node* node)
{
    while (node)
    {
        struct List2Node* p = node;
        node = node->Next;
        free(p->ListData);
        free(p);
    }
}

struct List2Node* GetFirstNode(struct List2Node* node)
{
    if (!node)
    {
        return NULL;
    }
    while (node->Prev)
    {
        node = node->Prev;
    }
    return node;
}

struct List2Node* GetLastNode(struct List2Node* node)
{
    if (!node)
    {
        return NULL;
    }
    while (node->Next)
    {
        node = node->Next;
    }
    return node;
}

struct List2Node* PushBack(struct List2Node* first, struct List2Node* newNode)
{
    newNode->Next = NULL;
    if (first)
    {
        struct List2Node* lastNode = GetLastNode(first);
        lastNode->Next = newNode;
        newNode->Prev = lastNode;
    }
    else
    {
        newNode->Prev = NULL;
        first = newNode;
    }
    return first;
}

struct List2Node* Insert(struct List2Node* first, struct List2Node* newNode)
{
    newNode->Next = newNode->Prev = NULL;
    if (!first)
    {
        // insert at empty list, new node become first
        return newNode;
    }
    
    struct List2Node* prev = NULL;
    struct List2Node* p = first;
    while (p)
    {
        if (CompareByName(newNode->ListData, p->ListData) < 0)
        {
            if (prev)
            {
                // update links with previous
                prev->Next = newNode;
                newNode->Prev = prev;
                return first;
            }
            else
            {
                // new element become first
                first = newNode;
            }
            // update links with next
            newNode->Next = p;
            p->Prev = newNode;
            return first;
        }
        prev = p;
        p = p->Next;
    }
    // insert at end, update link with previous
    prev->Next = newNode;
    newNode->Prev = prev;
    return first;
}

struct List2Node* Remove(struct List2Node* first, struct List2Node* toDelete)
{
    struct List2Node* prev = NULL;
    struct List2Node* p = first;
    struct List2Node* newFirst = first;
    while (p)
    {
        if (p == toDelete)
        {
            if (p->Next)
            {
                // update next after removed node link
                p->Next->Prev = prev;
            }
            if (prev)
            {
                // update before removed node  link
                prev->Next = p->Next;
            }
            else
            {
                // remove first node
                newFirst = p->Next;
            }
            p->Prev = p->Next = NULL;
            break;
        }
        prev = p;
        p = p->Next;
    }
    return newFirst;
}

struct List2Node* Find(struct List2Node* first, DataCompareFunc compare)
{
    struct List2Node* p = first;
    while (p)
    {
        if ((*compare)(p->ListData))
        {
            return p;
        }
        p = p->Next;
    }
    return NULL;
}

void SwapData(struct List2Node* node1, struct List2Node* node2)
{
    Data* tmp = node1->ListData;
    node1->ListData = node2->ListData;
    node2->ListData = tmp;
}

void ShakeForwardIteration(struct List2Node* firstNode, struct List2Node* lastNode)
{
    for (struct List2Node* curNode = firstNode; curNode != lastNode;)
    {
        struct List2Node* nextNode = curNode->Next;
        if (CompareByName(curNode->ListData, nextNode->ListData) > 0)
        {
            SwapData(curNode, nextNode);
        }
        curNode = nextNode;
    }
}

void ShakeBackwardIteration(struct List2Node* firstNode, struct List2Node* lastNode)
{
    for (struct List2Node* curNode = lastNode; curNode != firstNode;)
    {
        struct List2Node* prevNode = curNode->Prev;
        if (CompareByName(prevNode->ListData, curNode->ListData) > 0)
        {
            SwapData(prevNode, curNode);
        }
        curNode = prevNode;
    }
}

void ShakeSort(struct List2Node* firstNode)
{
    bool moveForward = true;
    for (struct List2Node* lastNode = GetLastNode(firstNode); firstNode != lastNode; moveForward = !moveForward)
    {
        if (moveForward)
        {
            ShakeForwardIteration(firstNode, lastNode);
            lastNode = lastNode->Prev;
        }
        else
        {
            ShakeBackwardIteration(firstNode, lastNode);
            firstNode = firstNode->Next;
        }
    }
}

int GetCount(struct List2Node* first)
{
    int result = 0;
    struct List2Node* p = first;
    while (p)
    {
        ++result;
        p = p->Next;
    }
    return result;
}

void PrintList(struct List2Node* first)
{
    struct List2Node* p = first;
    while (p)
    {
        PrintData(p->ListData);
        p = p->Next;
    }
}