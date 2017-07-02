#pragma once

#include "IGraphics.h"

class IShape
{
public:
    ~IShape() = default;
    virtual void Draw(IGraphics* g) = 0;
    virtual void Move(int x, int y) = 0;
};