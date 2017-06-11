#pragma once

#include <memory>
#include <string.h>

template<typename T>
class AccumulationTraits;

template<>
class AccumulationTraits<float>
{
public:
    typedef double AccT;
};

template<>
class AccumulationTraits<char>
{
public:
    typedef int AccT;
};

template<>
class AccumulationTraits<const char>
{
public:
    typedef int AccT;
};

template<typename T>
T Average(T* array, size_t count)
{
    typename AccumulationTraits<T>::AccT summ = 0;
    for (size_t i = 0; i < count; ++i)
    {
        summ += array[i];
    }
    return summ / count;
}

template<typename T>
T* Find(T* array, size_t count, T const& element)
{
    for (size_t i = 0; i < count; ++i)
    {
        if (array[i] == element)
        {
            return &array[i];
        }
    }
    return nullptr;
}

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
    return strcmp(a, b) > 0 ? a : b;
}

char * max(char* a, char* b)
{
    return strcmp(a, b) > 0 ? a : b;
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

template <class T>
class IsGreater
{
public:
    bool operator()(const T& a, const T& b) const
    {
        return a > b;
    }
};

template<class T,
    template <class T1> class Pred = IsGreater>
void BubbleSort(T* array, size_t count, Pred<T> const& isGreater = IsGreater<T>())
{
    for (size_t i = count; i > 1; --i)
    {
        for (size_t j = 1; j < count; ++j)
        {
            if (isGreater(array[i-1], array[i]))
            {
                T tmp = std::move(array[i-1]);
                array[i-1] = std::move(array[i]);
                array[i] = std::move(tmp);
            }
        }
    }
}