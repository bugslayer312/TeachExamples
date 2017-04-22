#pragma once

#include "Data.h"

struct ListNode
{
    struct Data* ListData;
    struct ListNode* Next;
};

typedef bool (*DataCompareFunc)(struct Data*);

struct ListNode* Create(struct Data* listData);
void Destroy(struct ListNode* node);
struct ListNode* GetLastNode(struct ListNode* first);
struct ListNode* PushBack(struct ListNode* first, struct ListNode* newNode);
struct ListNode* Insert(struct ListNode* first, struct ListNode* newNode);
struct ListNode* Remove(struct ListNode* first, struct ListNode* toDelete);
struct ListNode* Find(struct ListNode* first, DataCompareFunc predicate);
int GetCount(struct ListNode* first);
void PrintList(struct ListNode* first);