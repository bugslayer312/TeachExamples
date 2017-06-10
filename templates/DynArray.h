#pragma once

#include <iostream>

template<class T>
class DynArray
{
    T* m_data = nullptr;
    size_t m_capacity = 0;
    size_t m_size = 0;

public:
    DynArray() = default;
    DynArray(size_t capacity);
    DynArray(DynArray const& rhs);
    DynArray(DynArray&& rhs);
    DynArray& operator=(DynArray const& rhs);
    DynArray& operator=(DynArray&& rhs);
    
    void reserve(size_t newCapacity);
    size_t size() const;
    size_t capacity() const;
    
    void push_back(T const& item);
    void pop_back();
    void clear();
    
    T& operator[](size_t idx);
    T const& operator[](size_t idx) const;
};

template<class T>
DynArray<T>::DynArray(size_t capacity):
    m_capacity(capacity)
{
    if (m_capacity > 0)
    {
        m_data = new T[m_capacity];
    }
}

template<class T>
DynArray<T>::DynArray(DynArray const& rhs):
    m_capacity(rhs.m_capacity),
    m_size(rhs.m_size)
{
    if (m_capacity > 0)
    {
        m_data = new T[m_capacity];
        for (size_t i = 0; i < m_size; ++i)
        {
            m_data[i] = rhs.m_data[i];
        }
    }
}

template<class T>
DynArray<T>::DynArray(DynArray&& rhs):
    m_capacity(rhs.m_capacity),
    m_size(rhs.m_size),
    m_data(rhs.m_data)
{
    rhs.m_capacity = 0;
    rhs.m_size = 0;
    rhs.m_data = nullptr;
}

template<class T>
DynArray<T>& DynArray<T>::operator=(DynArray<T> const& rhs)
{
    if (&rhs != this)
    {
        DynArray<T> temp(rhs);      // copy to temp
        *this = std::move(temp);    // grabbing data from temp
    }
    return *this;
}

template<class T>
DynArray<T>& DynArray<T>::operator=(DynArray<T>&& rhs)
{
    if (&rhs != this)
    {
        delete [] m_data;
        m_capacity = rhs.m_capacity;
        m_size = rhs.m_size;
        m_data = rhs.m_data;

        rhs.m_capacity = 0;
        rhs.m_size = 0;
        rhs.m_data = nullptr;
    }
    return *this;
}

template<class T>
void DynArray<T>::reserve(size_t newCapacity)
{
    if (m_capacity == newCapacity)
    {
        return;
    }

    m_capacity = newCapacity;
    if (m_size >= m_capacity)
    {
        m_size = m_capacity;
    }
    DynArray<T> temp(*this);    // copy to temp
    delete [] m_data;
    *this = std::move(temp);    // grabbing data from temp
}

template<class T>
size_t DynArray<T>::size() const
{
    return m_size;
}

template<class T>
size_t DynArray<T>::capacity() const
{
    return m_capacity;
}

template<class T>
void DynArray<T>::push_back(T const& item)
{
    if (m_size == m_capacity)
    {
        reserve(m_capacity > 0 ? m_capacity * 2 : 5);
    }
    m_data[m_size++] = item;
}

template<class T>
void DynArray<T>::pop_back()
{
    if (m_size)
    {
        --m_size;
        if (m_size < m_capacity / 4)
        {
            reserve(m_capacity / 2);
        }
    }
}

template<class T>
void DynArray<T>::clear()
{
    m_size = 0;
    m_capacity = 0;
    delete [] m_data;
    m_data = nullptr;
}

template<class T>
T& DynArray<T>::operator[](size_t idx)
{
    if (idx >= m_size)
    {
        std::cout << "DynArray: Invalid index: " << idx << std::endl;
        exit(1);
    }
    return m_data[idx];
}

template<class T>
T const& DynArray<T>::operator[](size_t idx) const
{
    DynArray<T>* nonConstThis = const_cast<DynArray<T>*>(this);
    return (*nonConstThis)[idx];
}
