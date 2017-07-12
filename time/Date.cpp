#include "Date.h"

#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

Date::Date(std::uint8_t day, std::uint8_t month, std::uint16_t year) :
Day(day), Month(month), Year(year)
{
}

Date::Date(TimePoint const& tp)
{
    std::time_t t = std::chrono::system_clock::to_time_t(tp);
    tm* _tm = std::localtime(&t);
    Day = _tm->tm_mday;
    Month = _tm->tm_mon + 1;
    Year = _tm->tm_year + 1900;
}

Date::Date(std::string dateString)
{
    std::string::size_type pos = dateString.find(DateDelimiter);
    if (pos == std::string::npos)
    {
        throw StreamException("Error read date");
    }
    Day = std::stoi(dateString, nullptr, 10);
    dateString.replace(0, pos + 1, "");
    pos = dateString.find(DateDelimiter);
    if (pos == std::string::npos)
    {
        throw StreamException("Error read date");
    }
    Month = std::stoi(dateString, nullptr, 10);
    dateString.replace(0, pos + 1, "");
    Year = std::stoi(dateString, nullptr, 10);
}

TimePoint Date::ToTimePoint()
{
    tm _tm;
    memset(&_tm, 0, sizeof(_tm));
    _tm.tm_mday = Day;
    _tm.tm_mon = Month - 1;
    _tm.tm_year = Year - 1900;
    std::time_t t = mktime(&_tm);
    return std::chrono::system_clock::from_time_t(t);
}

std::string Date::ToString()
{
    std::ostringstream os;
    os << std::setfill('0') << std::setw(2) << static_cast<int>(Day) << DateDelimiter <<
    std::setfill('0') << std::setw(2) << static_cast<int>(Month) << DateDelimiter << Year;
    return os.str();
}

Date Date::Now()
{
    return Date(std::chrono::system_clock::now());
}
