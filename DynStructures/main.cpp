#include "Data.h"
#include "List.h"

#include <iostream>

bool SalaryGreaterThan500(struct Data* data)
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
}

int main()
{
    TestListFunctional();
    
    return 0;
}