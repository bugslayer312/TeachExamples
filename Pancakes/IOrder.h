#pragma once

#include <string>

// базовый класс - заказ

class IOrder
{
public:
    virtual ~IOrder() = default;
    virtual double GetCost() const = 0;     // стоимость
    virtual std::string GetName() const = 0;// название
};