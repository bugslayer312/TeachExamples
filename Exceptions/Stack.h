#pragma once

#include <exception>
#include <string>

// всегда выбираем базовым классом для исключений std::exception
class StackException : public std::exception
{
public:
    StackException() : std::exception()
    {
    }
    char const* what() const noexcept override
    {
        return "Stack exception";
    }
};

class StackIsFullException : public StackException
{
    std::size_t m_maxSize = 0;
public:
    StackIsFullException(std::size_t maxSize) : StackException(),
        m_maxSize(maxSize)
    {
    }
    
    char const* what() const noexcept override
    {
        return (std::string("Stack is full. Max size = ") + std::to_string(m_maxSize)).c_str();
    }
};

class StackIsEmptyException : public StackException
{
public:
    StackIsEmptyException() : StackException()
    {
    }
    
    char const* what() const noexcept override
    {
        return "Stack is empty";
    }
};

template<class T, std::size_t MaxSize>
class Stack
{
    T m_data[MaxSize];
    std::size_t m_count = 0;
    
    void CheckIsEmpty()
    {
        if (m_count == 0)
        {
            // здесь выбрасывается исключение
            throw StackIsEmptyException();
        }
    }
    
public:
    void Push(T const& value)
    {
        if (m_count == MaxSize)
        {
            // здесь выбрасывается исключение
            throw StackIsFullException(MaxSize);
        }
        m_data[m_count++] = value;
    }
    
    T& Pop()
    {
        CheckIsEmpty();
        return m_data[--m_count];
    }
    
    T& Top()
    {
        CheckIsEmpty();
        return m_data[m_count - 1];
    }
    
    std::size_t GetCount() const
    {
        return m_count;
    }
    
    bool IsEmpty() const
    {
        return m_count == 0;
    }
};