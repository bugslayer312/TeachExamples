#pragma once

#include "IShape.h"

class Circle : public IShape
{
protected:
    int m_cx;
    int m_cy;
    int m_radius;
public:
    Circle(int cx, int cy, int radius);
    virtual void Draw(IGraphics* g) override;
    virtual void Move(int x, int y) override;
};

class Smile : public Circle
{
    Circle m_leftEye;
    Circle m_rightEye;
public:
    Smile(int cx, int cy, int radius);
    virtual void Draw(IGraphics* g) override;
    virtual void Move(int x, int y) override;
};

class Rectangle : public IShape
{
    int m_x;
    int m_y;
    int m_width;
    int m_height;
public:
    Rectangle(int x, int y, int width, int height);
    virtual void Draw(IGraphics* g) override;
    virtual void Move(int x, int y) override;
};

class Triangle : public IShape
{
    int m_x1;
    int m_y1;
    int m_x2;
    int m_y2;
    int m_x3;
    int m_y3;
public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
    virtual void Draw(IGraphics* g) override;
    virtual void Move(int x, int y) override;
};