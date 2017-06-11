#pragma once

#include "Data.h"

struct ListNode
{
    struct Data* ListData;
    struct ListNode* Next;
};

struct ListNode* CreateSingleLinkedList(struct Data* listData);
void Destroy(struct ListNode* node);
struct ListNode* GetLastNode(struct ListNode* first);
struct ListNode* PushBack(struct ListNode* first, struct ListNode* newNode);
struct ListNode* Insert(struct ListNode* first, struct ListNode* newNode);
struct ListNode* Remove(struct ListNode* first, struct ListNode* toDelete);
struct ListNode* Find(struct ListNode* first, DataCompareFunc compare);
int GetCount(struct ListNode* first);
void PrintList(struct ListNode* first);
void SwapData(struct ListNode* node1, struct ListNode* node2);
void BubbleSort(struct ListNode* first);
struct ListNode* Reverse(struct ListNode* first);