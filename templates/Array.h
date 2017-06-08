#pragma once

#include <cstring>
#include <iostream>

template<class T, size_t N>
class Array
{
    T m_data;

public:
    Array();

    template<size_t N1>
    Array(Array<T, N1> const& rhs);

    T& operator[](size_t i);

    template<size_t N1>
    Array<T, N>& operator=(Array<T, N1> const& rhs);

    size_t GetCount() const;
};

template<class T, size_t N>
Array<T, N>::Array()
{
    for (size_t i = 0; i < N)
    {
        m_data = T();
    }
}

template<class T, size_t N>
template<size_t N1>
Array<T, N>::Array(Array<T, N1> const& rhs)
{
    for (size_t i = 0; i < N; ++i)
    {
        m_data[i] = (i < N1 ? rhs[i] : T());
    }
}

template<class T, size_t N>
T& Array<T, N>::operator[](size_t i)
{
    if (i < 0 || i >= N)
    {
        std::cout << "Array: Invalid index\n";
        exit(1);
    }
    return m_data[i];
}

template<class T, size_t N>
template<size_t N1>
Array<T, N>& Array<T, N>::operator=(Array<T, N1> const& rhs)
{
    if ((void*)this != (void*)&rhs)
    {
        for (size_t i = 0; i < N; ++i)
        {
             m_data[i] = (i < N1 ? rhs[i] : T1());
        }
    }
    return *this;
}

template<class T, size_t N>
size_t Array<T, N>::GetCount() const
{
    return N;
}