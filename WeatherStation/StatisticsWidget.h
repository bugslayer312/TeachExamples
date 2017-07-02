#pragma once

#include "IObserver.h"

class StatisticsWidget : public IObserver
{
    // средние величины
    double m_averageTemperature = 0;
    double m_averageHumidity = 0;
    // минимум
    double m_minTemperature = 0;
    double m_minHumidity = 0;
    // максимум
    double m_maxTemperature = 0;
    double m_maxHumidity = 0;
    // количество измерений
    int m_measureCount = 0;
    
    void Display();
public:
    void Update(double temperature, double humidity) override;
};