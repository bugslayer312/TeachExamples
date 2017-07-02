#include "Suppliments.h"

Suppliment::Suppliment(IOrder* decoratee, std::string name, double cost, int count):
    m_decoratee(decoratee),
    m_name(name),
    m_cost(cost),
    m_count(count)
{
}

Suppliment::~Suppliment()
{
    delete m_decoratee;
}

double Suppliment::GetCost() const
{
    return m_decoratee->GetCost() + m_cost * m_count;
}

std::string Suppliment::GetName() const
{
    std::string result = m_decoratee->GetName() + ", " + m_name;
    if (m_count > 1)
    {
        result += "*" + std::to_string(m_count);
    }
    return result;
}

Bacon::Bacon(IOrder* decoratee, int count):
    Suppliment(decoratee, "bacon", 0.8, count)
{
}

Onion::Onion(IOrder* decoratee, int count):
    Suppliment(decoratee, "onion", 0.3, count)
{
}

Chocolate::Chocolate(IOrder* decoratee, int count):
    Suppliment(decoratee, "chocolate", 0.7, count)
{
}

Jam::Jam(IOrder* decoratee, int count):
    Suppliment(decoratee, "jam", 0.5, count)
{
}