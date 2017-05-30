#pragma once

#include <iosfwd>

class String
{
private:
    char* m_str = nullptr;
    
public:
    String();
    String(char const* str);
    String(String const& string);
    
    String& operator=(String const& rhs);
    
    size_t GetLength() const;
    char const* GetCString() const;
    
    String operator+(String const& rhs);
    bool operator==(String const& rhs) const;
    bool operator!=(String const& rhs) const;
    bool operator<(String const& rhs) const;
    bool operator>(String const& rhs) const;
    
    char& operator[](int idx);
    char operator[](int idx) const;
    
    operator char*();
    operator bool() const;
    
    friend std::istream& operator>>(std::istream& stream, String& string);
};

std::ostream& operator<<(std::ostream& stream, String const& string);
std::istream& operator>>(std::istream& stream, String& string);