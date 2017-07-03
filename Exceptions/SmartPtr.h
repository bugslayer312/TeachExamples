#pragma once

template<class T>
class SmartPtr
{
    T* m_ptr = nullptr;
    
public:
    SmartPtr() = default;
    SmartPtr(T* ptr): m_ptr(ptr)
    {
    }
    
    ~SmartPtr()
    {
        delete m_ptr;
    }
    
    T& operator*()
    {
        return *m_ptr;
    }
    
    T* operator->()
    {
        return m_ptr;
    }
    
    operator T*()
    {
        return m_ptr;
    }
    
    void Reset()
    {
        delete m_ptr;
        m_ptr = nullptr;
    }
    
    void Attach(T* ptr)
    {
        Reset();
        m_ptr = ptr;
    }
}