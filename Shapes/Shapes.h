#pragma once

#include "IShape.h"

class Circle : public IShape
{
protected:
    int m_cx = 0;
    int m_cy = 0;
    int m_radius = 0;
public:
    Circle() = default;
    Circle(int cx, int cy, int radius);
    void Draw(IGraphics* g) override;
    void Move(int x, int y) override;
    void SaveToStream(std::ostream& stream) override;
    void LoadFromStream(std::istream& stream) override;
    
    void Init(int cx, int cy, int radius);
};

class Smile : public Circle
{
    Circle m_leftEye;
    Circle m_rightEye;
public:
    Smile() = default;
    Smile(int cx, int cy, int radius);
    void Draw(IGraphics* g) override;
    void Move(int x, int y) override;
    void SaveToStream(std::ostream& stream) override;
    void LoadFromStream(std::istream& stream) override;
};

class Rectangle : public IShape
{
    int m_x = 0;
    int m_y = 0;
    int m_width = 0;
    int m_height = 0;
public:
    Rectangle() = default;
    Rectangle(int x, int y, int width, int height);
    void Draw(IGraphics* g) override;
    void Move(int x, int y) override;
    void SaveToStream(std::ostream& stream) override;
    void LoadFromStream(std::istream& stream) override;
};

class Triangle : public IShape
{
    int m_x1 = 0;
    int m_y1 = 0;
    int m_x2 = 0;
    int m_y2 = 0;
    int m_x3 = 0;
    int m_y3 = 0;
public:
    Triangle() = default;
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
    void Draw(IGraphics* g) override;
    void Move(int x, int y) override;
    void SaveToStream(std::ostream& stream) override;
    void LoadFromStream(std::istream& stream) override;
};