#include "String.h"

#include <cstring>
#include <iostream>

String::String()
{
    m_str = new char[1];
    m_str[0] = '\0';
}

String::String(char const* str)
{
    size_t length = strlen(str);
    m_str = new char[length + 1];
    strcpy(m_str, str);
}

String::String(String const& string)
{
    String tmp(string.m_str);
    m_str = tmp.m_str;
    tmp.m_str = nullptr;
}

String& String::operator=(String const& rhs)
{
    if (this != &rhs)
    {
        String tmp(rhs.m_str);
        delete[] m_str;
        m_str = tmp.m_str;
        tmp.m_str = nullptr;
    }
    return *this;
}

size_t String::GetLength() const
{
    return strlen(m_str);
}

char const* String::GetCString() const
{
    return m_str;
}

String String::operator+(String const& rhs)
{
    size_t length1 = GetLength();
    size_t length2 = rhs.GetLength();
    String result;
    delete[] result.m_str;
    result.m_str = new char[length1 + length2 + 1];
    memcpy(result.m_str, m_str, length1);
    memcpy(result.m_str + length1, rhs.m_str, length2 + 1);
    return result;
}

bool String::operator==(String const& rhs) const
{
    return strcmp(m_str, rhs.m_str) == 0;
}

bool String::operator!=(String const& rhs) const
{
    return strcmp(m_str, rhs.m_str) != 0;
}

bool String::operator<(String const& rhs) const
{
    return strcmp(m_str, rhs.m_str) < 0;
}

bool String::operator>(String const& rhs) const
{
    return strcmp(m_str, rhs.m_str) > 0;
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
    if (idx < 0 || idx >= GetLength())
    {
        std::cout << "String: invalid index\n";
        exit(-1);
    }
    return m_str[idx];
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
    stream << string.GetCString();
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