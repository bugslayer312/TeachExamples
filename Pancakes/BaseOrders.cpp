#include "BaseOrders.h"

double PancakeWithPotatoAndMushrooms::GetCost() const
{
    return 1.2;
}
std::string PancakeWithPotatoAndMushrooms::GetName() const
{
    return "Pancake with potato and mushrooms";
}

double PancakeWithCheeseAndTomatoes::GetCost() const
{
    return 1.8;
}
std::string PancakeWithCheeseAndTomatoes::GetName() const
{
    return "Pancake with cheese and tomatoes";
}

double PancakeWithStrawberry::GetCost() const
{
    return 1.6;
}
std::string PancakeWithStrawberry::GetName() const
{
    return "Pancake with butter";
}

double PancakeWithBanana::GetCost() const
{
    return 1.0;
}
std::string PancakeWithBanana::GetName() const
{
    return "Pancake with banana";
}