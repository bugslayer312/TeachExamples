#include "BaseOrders.h"
#include "Suppliments.h"
#include "Discount.h"

#include <iostream>

enum SupplimentType
{
    BaconSup,
    OnionSup,
    ChocolateSup,
    JamSup
};

// добавить добавку к заказу

IOrder* AddSuppliment(IOrder* order, SupplimentType type, int count = 1)
{
    switch (type) {
        case BaconSup:
            return new Bacon(order, count);
        case OnionSup:
            return new Onion(order, count);
        case ChocolateSup:
            return new Chocolate(order, count);
        case JamSup:
            return new Jam(order, count);
    }
    return order;
}

// применить скидку к заказу

IOrder* ApplyDiscount(IOrder* order)
{
    return new Discount(order);
}

// напечатать чек

void PrintOrder(IOrder* order)
{
    std::cout << order->GetName() << std::endl;
    std::cout << "Cost: " << order->GetCost() << " BYN" << std::endl << std::endl;
}

int main()
{
    // формируем первый заказ
    IOrder* order1 = new PancakeWithCheeseAndTomatoes();
    order1 = AddSuppliment(order1, BaconSup, 2);
    order1 = AddSuppliment(order1, OnionSup);
    order1 = ApplyDiscount(order1);
    
    // формируем второй заказ
    IOrder* order2 = new PancakeWithBanana();
    order2 = AddSuppliment(order2, ChocolateSup);
    order2 = AddSuppliment(order2, JamSup);
    order2 = ApplyDiscount(order2);
    
    // печатаем чеки
    PrintOrder(order1);
    PrintOrder(order2);
    delete order1;
    delete order2;
    
    return 0;
}