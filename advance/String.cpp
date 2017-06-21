#include "String.h"

#include <cstring>
#include <iostream>


String::String()
{
    std::cout << "String default constructor\n";
}

String::String(char const* str)
{
    std::cout << "String constructor with param\n";
    if (str)
    {
        m_str = new char[strlen(str) + 1];
        strcpy(m_str, str);
    }
}

String::String(String const& string)
{
    std::cout << "String copy constructor\n";
    m_str = new char[string.GetLength() + 1];
    strcpy(m_str, string.m_str ? string.m_str : "");
}

String::String(String&& rhs)
{
    std::cout << "String move constructor\n";
    m_str = rhs.m_str;
    rhs.m_str = nullptr;
}

String::~String()
{
    std::cout << "String destructor\n";
}

String& String::operator=(String const& rhs)
{
    if (this != &rhs)
    {
        delete[] m_str;
        if (rhs.m_str != nullptr)
        {
            m_str = new char[rhs.GetLength() + 1];
            strcpy(m_str, rhs.m_str);
        }
        else
        {
            m_str = nullptr;
        }
    }
    return *this;
}

String& String::operator=(String&& rhs)
{
    if (this != &rhs)
    {
        delete[] m_str;
        m_str = rhs.m_str;
        rhs.m_str = nullptr;
    }
    return *this;
}

size_t String::GetLength() const
{
    return m_str != nullptr ? strlen(m_str) : 0;
}

char const* String::GetCString() const
{
    return m_str;
}

String String::operator+(String const& rhs)
{
    size_t length1 = GetLength();
    size_t length2 = rhs.GetLength();
    size_t newLength = length1 + length2;
    String result;
    result.m_str = new char[newLength + 1];
    if (length1)
    {
        memcpy(result.m_str, m_str, length1);
    }
    if (length2)
    {
        memcpy(result.m_str + length1, rhs.m_str, length2);
    }
    result.m_str[newLength] = '\0';
    return result;
}

bool String::operator==(String const& rhs) const
{
    return strcmp(m_str ? m_str : "", rhs.m_str ? rhs.m_str : "") == 0;
}

bool String::operator!=(String const& rhs) const
{
    return !(*this == rhs);
}

bool String::operator<(String const& rhs) const
{
    return strcmp(m_str ? m_str : "", rhs.m_str ? rhs.m_str : "") < 0;
}

bool String::operator>(String const& rhs) const
{
    return strcmp(m_str ? m_str : "", rhs.m_str ? rhs.m_str : "") > 0;
}

char& String::operator[](int idx)
{
    if (idx < 0 || idx >= GetLength())
    {
        std::cout << "String: invalid index\n";
        exit(-1);
    }
    return m_str[idx];
}

char String::operator[](int idx) const
{
    String* this_ = const_cast<String*>(this);
    return (*this)[idx];
}

String::operator char*()
{
    return m_str;
}

String::operator bool() const
{
    return GetLength() > 0;
}

std::ostream& operator<<(std::ostream& stream, String const& string)
{
    stream << (string.GetCString() ? string.GetCString() : "");
    return stream;
}

std::istream& operator>>(std::istream& stream, String& string)
{
    char buffer[1024];
    stream >> buffer;
    String tmp(buffer);
    delete[] string.m_str;
    string.m_str = tmp.m_str;
    tmp.m_str = nullptr;
    return stream;
}