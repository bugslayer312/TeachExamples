#pragma once

#include "IOrder.h"

// класс-добавка к блинам

class Suppliment : public IOrder
{
protected:

    // декорируемый объект
    IOrder* m_decoratee = nullptr;
    // название добавки
    std::string m_name;
    // стоимость 1 порции добавки
    double m_cost = 0;
    // количество порций
    int m_count = 0;
    
public:
    Suppliment(IOrder* decoratee, std::string name, double cost, int count);
    ~Suppliment();
    double GetCost() const override;
    std::string GetName() const override;
};

// конкретные классы добавок

class Bacon : public Suppliment
{
public:
    Bacon(IOrder* decoratee, int count);
};

class Onion : public Suppliment
{
public:
    Onion(IOrder* decoratee, int count);
};

class Chocolate : public Suppliment
{
public:
    Chocolate(IOrder* decoratee, int count);
};

class Jam : public Suppliment
{
public:
    Jam(IOrder* decoratee, int count);
};