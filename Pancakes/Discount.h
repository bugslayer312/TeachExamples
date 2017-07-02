#pragma once

#include "IOrder.h"

// класс-скидка
// Если сумма заказа больше 3 рублей, делаем 10% скидку

class Discount : public IOrder
{
protected:
    // декорируемый объект
    IOrder* m_decoratee = nullptr;
    
public:
    Discount(IOrder* order);
    ~Discount() override;

    double GetCost() const override;
    std::string GetName() const override;
};