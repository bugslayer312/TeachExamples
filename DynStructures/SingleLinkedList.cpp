#include "SingleLinkedList.h"

#include <cstdlib>

struct ListNode* CreateSingleLinkedList(struct Data* listData)
{
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
    result->ListData = listData;
    result->Next = NULL;
    return result;
}

void Destroy(struct ListNode* node)
{
    while (node)
    {
        struct ListNode* p = node;
        node = node->Next;
        free(p->ListData);
        free(p);
    }
}

struct ListNode* GetLastNode(struct ListNode* first)
{
    if (!first)
    {
        return NULL;
    }
    struct ListNode* p = first;
    while (p->Next)
    {
        p = p->Next;
    }
    return p;
}

struct ListNode* PushBack(struct ListNode* first, struct ListNode* newNode)
{
    newNode->Next = NULL;
    struct ListNode* lastNode = GetLastNode(first);
    if (lastNode)
    {
        lastNode->Next = newNode;
        return first;
    }
    return newNode;
}

struct ListNode* Insert(struct ListNode* first, struct ListNode* newNode)
{
    newNode->Next = NULL;
    if (!first)
    {
        return newNode;
    }
    
    struct ListNode* prev = NULL;
    struct ListNode* p = first;
    while (p)
    {
        if (CompareByName(newNode->ListData, p->ListData) < 0)
        {
            if (prev)
            {
                prev->Next = newNode;
                newNode->Next = p;
                return first;
            }
            else
            {
                newNode->Next = p;
                return newNode;
            }
        }
        prev = p;
        p = p->Next;
    }
    prev->Next = newNode;
    return first;
}

struct ListNode* Remove(struct ListNode* first, struct ListNode* toDelete)
{
    struct ListNode* prev = NULL;
    struct ListNode* p = first;
    struct ListNode* newFirst = first;
    while (p)
    {
        if (p == toDelete)
        {
            if (prev)
            {
                prev->Next = p->Next;
            }
            else
            {
                newFirst = p->Next;
            }
            p->Next = NULL;
            break;
        }
        prev = p;
        p = p->Next;
    }
    return newFirst;
}

struct ListNode* Find(struct ListNode* first, DataCompareFunc compare)
{
    struct ListNode* p = first;
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

int GetCount(struct ListNode* first)
{
    int result = 0;
    struct ListNode* p = first;
    while (p)
    {
        ++result;
        p = p->Next;
    }
    return result;
}

void PrintList(struct ListNode* first)
{
    struct ListNode* p = first;
    while (p)
    {
        PrintData(p->ListData);
        p = p->Next;
    }
}

void SwapData(struct ListNode* node1, struct ListNode* node2)
{
    struct Data* tmp = node1->ListData;
    node1->ListData = node2->ListData;
    node2->ListData = tmp;
}

void BubbleSortIteration(struct ListNode* first, int nodeCount)
{
    for (struct ListNode* curNode = first; nodeCount > 0; --nodeCount)
    {
        struct ListNode* nextNode = curNode->Next;
        if (CompareByName(curNode->ListData, nextNode->ListData) > 0)
        {
            SwapData(curNode, nextNode);
        }
        curNode = nextNode;
    }
}

void BubbleSort(struct ListNode* first)
{
    for (int iterCount = GetCount(first) - 1; iterCount > 0; --iterCount)
    {
        BubbleSortIteration(first, iterCount);
    }
}

struct ListNode* Reverse(struct ListNode* first)
{
    struct ListNode* prev = NULL;
    struct ListNode* cur = first;
    while (cur)
    {
        struct ListNode* next = cur->Next;
        cur->Next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}