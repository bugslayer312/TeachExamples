#include "Discount.h"

Discount::Discount(IOrder* order): m_decoratee(order)
{
}

Discount::~Discount()
{
    delete m_decoratee;
}

double Discount::GetCost() const
{
    double cost = m_decoratee->GetCost();
    if (cost >= 3.0)
    {
        cost *= 0.9;
    }
    return cost;
}

std::string Discount::GetName() const
{
    std::string name = m_decoratee->GetName();
    if (m_decoratee->GetCost() >= 3.0)
    {
        name += " (-10% discount)";
    }
    return name;
}