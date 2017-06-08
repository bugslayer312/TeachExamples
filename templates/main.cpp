#include "Array.h"
#include "List.h"

#include <iostream>
#include <cstring>
#include <vector>
#include <list>

#include <algorithm>

template<class T>
T const& max(T const& a, T const& b)
{
    return a > b ? a : b;
}

template<class T>
T const& max(T const& a, T const& b, T const& c)
{
    return max(max(a, b), c);
}

char const* max(char const* a, char const* b)
{
    return strcmp(a, b) < 0 ? b : a;
}

/*template<>
char const* max(char const* a, char const* b)
{
    return strcmp(a, b) < 0 ? b : a;
} */

template<typename T>
class AccumulationTraits;

template<>
class AccumulationTraits<char> {
public:
    typedef int AccT;
    static AccT const zero = 0;
};

template <typename T>
typename AccumulationTraits<T>::AccT Average(T const* beg, T const* end)
{
    typedef typename AccumulationTraits<T>::AccT AccT;

    AccT total = AccumulationTraits<T>::zero;
    while (beg != end)
    {
        total += *beg;
        ++beg;
    }
    return total;
}

template <class T>
class GreaterEqual
{
    T value;
public:
    GreaterEqual(T const& v) : value(v) {};
    bool operator()(const T& d)
    {
        return d >= value;
    }
};

// std::copy_if(a, a+10, GreaterEqual<int>(4))

int main()
{
    // vector::iterator
    int a = 1;
    int b = 2;
    std::cout << max(a, b) << "\n";
    std::cout << max("Hello", "World") << "\n";

    List<int> list = { 100, 200, 300 };
    List<int>::iterator it = list.begin();
    list.insert(it, 400);
    list.insert(it, 500);
    it = list.begin();
    ++it;
    ++it;
    List<int>::iterator found = std::find(list.begin(), it, 250);
    for (int& var : list)
    {
        std::cout << var << " ";
    }
    return 0;
}
