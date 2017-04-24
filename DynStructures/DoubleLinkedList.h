#pragma once

#include "Data.h"

struct List2Node
{
    struct Data* ListData;
    struct List2Node* Prev;
    struct List2Node* Next;
};

struct List2Node* CreateDoubleLinkedList(struct Data* listData);
void Destroy(struct List2Node* node);
struct List2Node* GetFirstNode(struct List2Node* node);
struct List2Node* GetLastNode(struct List2Node* node);
struct List2Node* PushBack(struct List2Node* first, struct List2Node* newNode);
struct List2Node* Insert(struct List2Node* first, struct List2Node* newNode);
struct List2Node* Remove(struct List2Node* first, struct List2Node* toDelete);
struct List2Node* Find(struct List2Node* first, DataCompareFunc compare);
void SwapData(struct List2Node* node1, struct List2Node* node2);
void ShakeSort(struct List2Node* firstNode);
int GetCount(struct List2Node* first);
void PrintList(struct List2Node* first);