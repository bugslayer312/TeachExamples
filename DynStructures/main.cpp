#include "Data.h"
//#include "List.h"
//#include "Stack.h"
//#include "Queue.h"
#include "DoubleLinkedList.h"
#include "SingleLinkedList.h"
//#include "Stack.h"
//#include "Queue.h"
//#include "DoubleLinkedList.h"

#include <iostream>

bool SalaryGreaterThan500(const struct Data* data)
{
    return data->Salary >= 500;
}

bool SalaryLessThan500(const struct Data* data)
{
    return data->Salary < 500;
}

/* void TestListFunctional()
{
    struct ListNode* first = NULL;
    int const count = 5;
    for (int i = 0;i < count; ++i)
    {
        struct Data* data = ReadData();
        struct ListNode* node = CreateSingleLinkedList(data);
        first = Insert(first, node);
    }
    PrintList(first);
    struct ListNode* first2 = NULL;
    while (struct ListNode* found = Find(first, SalaryGreaterThan500))
    {
        first = Remove(first, found);
        first2 = PushBack(first2, found);
    }
    std::cout << "\nFirst list: " << GetCount(first) << " elements" << std::endl;
    PrintList(first);
    std::cout << "\nSecond list: " << GetCount(first2) << " elements" << std::endl;
    PrintList(first2);
    Destroy(first);
    Destroy(first2);
} */

/* void TestStackFunctional()
{
    struct Stack* stack = CreateStack(100);
    int const count = 5;
    for (int i = 0;i < count; ++i)
    {
        struct Data* data = ReadData();
        Push(stack, data);
    }
    std::cout << "Stack count: " << GetCount(stack) << std::endl;
    std::cout << "Stack top:" << std::endl;
    PrintData(Top(stack));
    std::cout << std::endl;
    
    struct Stack* stack2 = CreateStack(100);
    while (struct Data* data = Pop(stack))
    {
        if (data->Name[0] >= 'K')
        {
            PrintData(data);
            free(data);
        }
        else
        {
            Push(stack2, data);
        }
    }
    
    std::cout << std::endl;
    
    while (struct Data* data = Pop(stack2))
    {
        PrintData(data);
        free(data);
    }
} */

/*void HandleQueue(struct Queue* queue, DataCompareFunc predicate, int numHandler)
{
    std::cout << "Handler " << numHandler << std::endl;
    int counter = GetCount(queue);
    while (struct Data* data = Pop(queue))
    {
        if ((*predicate)(data))
        {
            PrintData(data);
            free(data);
            return;
        }
        Push(queue, data);
        if (!--counter)
        {
            break;
        }
    }
    std::cout << "Don't exist elements" << std::endl;
}

void TestQueueFunctional()
{
    int const count = 5;
    struct Queue* queue = CreateQueue(5);
    
    for (int i = 0;i < count; ++i)
    {
        struct Data* data = ReadData();
        Push(queue, data);
    }
    
    while (!IsEmpty(queue))
    {
        HandleQueue(queue, SalaryGreaterThan500, 1);
        HandleQueue(queue, SalaryLessThan500, 2);
    }
} */

/* void TestDoubleLinkedList()
{
    struct List2Node* first = NULL;
    int const count = 5;
    for (int i = 0;i < count; ++i)
    {
        struct Data* data = ReadData();
        struct List2Node* node = CreateDoubleLinkedList(data);
        first = PushBack(first, node);
    }
    ShakeSort(first);
    first = GetFirstNode(first);
    PrintList(first);
    struct List2Node* first2 = NULL;
    while (struct List2Node* found = Find(first, SalaryLessThan500))
    {
        first = Remove(first, found);
        first2 = Insert(first2, found);
    }
    std::cout << "\nFirst list: " << GetCount(first) << " elements" << std::endl;
    PrintList(first);
    std::cout << "\nSecond list: " << GetCount(first2) << " elements" << std::endl;
    PrintList(first2);
    Destroy(first);
    Destroy(first2);
} */

void TestSingleLinkedListSort()
{
    struct ListNode* first = NULL;
    int const count = 5;
    for (int i = 0;i < count; ++i)
    {
        struct Data* data = ReadData();
        struct ListNode* node = CreateSingleLinkedList(data);
        first = PushBack(first, node);
    }
    BubbleSort(first);
    PrintList(first);
    first = Reverse(first);
    std::cout << "\nReverse list:" << std::endl;
    PrintList(first);
    Destroy(first);
}

int main()
{
    // TestListFunctional();

    // TestStackFunctional();

    // TestQueueFunctional();

    // TestDoubleLinkedList();

    TestSingleLinkedListSort();
    return 0;
}