//#include "Array.h"
//#include "List.h"
#include "SomeStuff.h"
//#include "DynArray.h"
//#include "Student.h"

#include <iostream>
//#include <algorithm>

class Student
{
    float m_rating = 0;
public:
    Student(float rating) : m_rating(rating) {};
    bool operator>(Student const& rhs) const
    {
        return m_rating > rhs.m_rating;
    }
    float GetRating() const
    {
        return m_rating;
    }
};

template<class T>
class IsGreaterRating
{
public:
    bool operator()(const T& a, const T& b) const
    {
        return a.GetRating() > b.GetRating();
    }
};

int main()
{
    //DynArray<int> d = {100, 200, 300};
    //std::cout << d << ;//std::endl;
    Student students[] = {5.0f, 7.3f, 2.03 };
    BubbleSort(students, 3, IsGreaterRating<Student>());
    
    
    return 0;
}
