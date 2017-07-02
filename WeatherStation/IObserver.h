#pragma once

// интерфейс наблюдателя

class IObserver
{
public:
    virtual ~IObserver() = default;
    
    // температура/влажность изменились. Обновить состояние
    virtual void Update(double temperature, double humidity) = 0;
};