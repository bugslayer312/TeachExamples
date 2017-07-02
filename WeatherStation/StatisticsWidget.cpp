#include "StatisticsWidget.h"

#include <iostream>

void StatisticsWidget::Display()
{
    std::cout << "Average: temp=" << m_averageTemperature << ", humidity=" << m_averageHumidity << std::endl;
    std::cout << "Min: temp=" << m_minTemperature << ", humidity=" << m_minHumidity << std::endl;
    std::cout << "Max: temp=" << m_maxTemperature << ", humidity=" << m_maxHumidity << std::endl;
}

void StatisticsWidget::Update(double temperature, double humidity)
{
    m_averageTemperature = (m_averageTemperature * m_measureCount + temperature) / (m_measureCount + 1);
    m_averageHumidity = (m_averageHumidity * m_measureCount + humidity) / (m_measureCount + 1);
    if (m_measureCount > 0)
    {
        if (temperature < m_minTemperature)
        {
            m_minTemperature = temperature;
        }
        else if (temperature > m_maxTemperature)
        {
            m_maxTemperature = temperature;
        }
        if (humidity < m_minHumidity)
        {
            m_minHumidity = humidity;
        }
        else if (humidity > m_maxHumidity)
        {
            m_maxHumidity = humidity;
        }
    }
    else
    {
        m_minTemperature = m_maxTemperature = temperature;
        m_minHumidity = m_maxHumidity = humidity;
    }
    ++m_measureCount;
    Display();
}