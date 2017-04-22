#include "Data.h"
//#include "List.h"
#include "Stack.h"

#include <iostream>

/* bool SalaryGreaterThan500(struct Data* data)
{
    return data->Salary > 500;
}

void TestListFunctional()
{
    struct ListNode* first = NULL;
    int const count = 5;
    for (int i = 0;i < count; ++i)
    {
        struct Data* data = ReadData();
        struct ListNode* node = Create(data);
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

void TestStackFunctional()
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
}

int main()
{
    // TestListFunctional();
    
    TestStackFunctional();
    
    return 0;
}