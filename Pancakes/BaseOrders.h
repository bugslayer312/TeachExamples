#pragma once

#include "IOrder.h"

// основные позиции блинов для заказа

class PancakeWithPotatoAndMushrooms : public IOrder
{
public:
    double GetCost() const override;
    std::string GetName() const override;
};

class PancakeWithCheeseAndTomatoes : public IOrder
{
public:
    double GetCost() const override;
    std::string GetName() const override;
};

class PancakeWithStrawberry : public IOrder
{
public:
    double GetCost() const override;
    std::string GetName() const override;
};

class PancakeWithBanana : public IOrder
{
public:
    double GetCost() const override;
    std::string GetName() const override;
};