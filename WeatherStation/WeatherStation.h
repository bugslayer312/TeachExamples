#pragma once

#include "IObserver.h"

#include <vector>

// метеостанция

class WeatherStation
{
private:
    // хранимые данные: температура и влажность
    double m_temperature = 0;
    double m_humidity = 0;
    
    // подписчики (наблюдатели), которые следят за обновлениями данных
    std::vector<IObserver*> m_observers;
    
    // уведомить подписчиков
    void NotifyObservers();
    
public:
    WeatherStation() = default;
    
    void Set(double temperature, double humidity);
    double GetTemperature() const;
    double GetHumidity() const;
    
    // добавить подписчика
    void AddObserver(IObserver* observer);
    // удалить подписчика
    void RemoveObserver(IObserver* observer);
};