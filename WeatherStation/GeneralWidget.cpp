#include "GeneralWidget.h"

#include <iostream>

void GeneralWidget::Update(double temperature, double humidity)
{
    std::cout << "Current: temp=" << temperature << ", humidity=" << humidity << std::endl;
}