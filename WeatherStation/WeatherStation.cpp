#include "WeatherStation.h"

void WeatherStation::NotifyObservers()
{
    for (IObserver* observer : m_observers)
    {
        observer->Update(m_temperature, m_humidity);
    }
}

void WeatherStation::Set(double temperature, double humidity)
{
    if (m_temperature == temperature && m_humidity == humidity)
    {
        // значения не изменились
        return;
    }
    
    m_temperature = temperature;
    m_humidity = humidity;
    NotifyObservers();
}

double WeatherStation::GetTemperature() const
{
    return m_temperature;
}

double WeatherStation::GetHumidity() const
{
    return m_humidity;
}

void WeatherStation::AddObserver(IObserver* observer)
{
    m_observers.push_back(observer);
}

void WeatherStation::RemoveObserver(IObserver* observer)
{
    for (std::vector<IObserver*>::iterator it = m_observers.begin(); it != m_observers.end(); ++it)
    {
        if (*it == observer)
        {
            m_observers.erase(it);
            return;
        }
    }
}