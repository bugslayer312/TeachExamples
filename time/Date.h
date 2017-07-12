#pragma once

#include <exception>
#include <string>
#include <chrono>
#include <cinttypes>

class StreamException : public std::exception
{
    std::string m_error;
public:
    StreamException(std::string const& error):m_error(error)
    {
    }
    
    char const* what() const _NOEXCEPT override
    {
        return m_error.c_str();
    }
};

typedef std::chrono::system_clock::time_point TimePoint;
namespace std
{
    namespace chrono
    {
        typedef duration<long, ratio<3600 * 24> > days;
    }
}

char const DateDelimiter = '/';

struct Date
{
    std::uint8_t Day = 0;
    std::uint8_t Month = 0;
    std::uint16_t Year = 0;
    
    Date(std::uint8_t day, std::uint8_t month, std::uint16_t year);
    Date(TimePoint const& tp);
    Date(std::string dateString);
    
    TimePoint ToTimePoint();
    std::string ToString();
    
    static Date Now();
};