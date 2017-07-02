#pragma once

#include "IObserver.h"

class GeneralWidget : public IObserver
{
public:
    void Update(double temperature, double humidity) override;
};