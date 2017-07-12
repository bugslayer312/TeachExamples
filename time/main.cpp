#include "Date.h"

#include <ctime>
#include <chrono>
#include <iostream>
#include <string>

using namespace std::chrono;

int const SecondsPerHour = 60 * 60;
int const SecondsPerDay = 24 * SecondsPerHour;

void WorkWithTimeInCStyle()
{
    std::time_t current = std::time(nullptr);
    std::cout << current << " seconds since Epoch\n";
    tm* _tm = localtime(&current);
    std::cout << "local time: " << asctime(_tm);
    _tm = gmtime(&current);
    std::cout << "absolute time: " << asctime(_tm);
    std::cout << "today is " << _tm->tm_wday << "th day of week" << std::endl;
    
    std::time_t currentPlusWeek = current + 7 * SecondsPerDay;
    std::cout << "local time: " << ctime(&currentPlusWeek);
    
    std::time_t epoch = 0;
    std::cout << "epoch absolute time: " << asctime(gmtime(&epoch));
}

std::string AsString(system_clock::time_point& tp)
{
    std::time_t t = system_clock::to_time_t(tp);
    std::string s = std::ctime(&t);
    s.pop_back();
    return s;
}

void WorkWithTimeInCppStyle()
{
    system_clock::time_point tp = system_clock::now();
    std::time_t t = system_clock::to_time_t(tp);
    
    std::cout << "local time: " << std::ctime(&t);
    
    duration<long, std::ratio<1, 2>> halfSeconds(10);
    
    tp += halfSeconds;
    std::cout << AsString(tp) << std::endl;
    
    duration<long, std::ratio<60 * 60>> _hours(5);
    tp += _hours;
    std::cout << AsString(tp) << std::endl;
    
    std::chrono::seconds sec(5000);
    int h = sec / std::chrono::hours(1);
    sec -= h * std::chrono::hours(1);
    int m = sec / std::chrono::minutes(1);
    sec -= m * std::chrono::minutes(1);
    
    std::cout << "5000 sec = " << h << " hours, " << m << " minutes, " << sec.count() << " seconds\n";
    
    std::cout << _hours.count() << " hours = " << std::chrono::minutes(_hours).count() << " minutes\n";
    
    sec = std::chrono::hours(3);
    std::cout << sec.count() << " seconds\n";
    sec += std::chrono::minutes(5);
    
    std::chrono::hours hh = std::chrono::duration_cast<std::chrono::hours>(sec);
    std::cout << hh.count() << " hours\n";
    std::chrono::minutes mm = std::chrono::duration_cast<std::chrono::minutes>(sec);
    std::cout << mm.count() << " minutes\n";
    
    std::cout << (std::chrono::hours(1) < std::chrono::minutes(61)) << std::endl;
}

int main()
{
    // WorkWithTimeInCStyle();
    // WorkWithTimeInCppStyle();
    
    Date dt = Date::Now();
    
    std::cout << dt.ToString() << std::endl;
    
    Date dt1(dt.ToTimePoint() + std::chrono::days(5));
    Date dt2(dt1.ToString());
    
    std::cout << dt2.ToString() << std::endl;
    
    Date dt3(1, 1, 2018);
    TimePoint tp = dt3.ToTimePoint();
    std::cout << AsString(tp) << std::endl;
    
}