#include "Shape.h"
#include "Graphics.h"

Circle::Circle(int cx, int cy, int radius) :
    m_cx(cx),
    m_cy(cy),
    m_radius(radius)
{
}

void Circle::Draw(Graphics* g)
{
    g->DrawEllipse(m_cx - m_radius, m_cy - m_radius, m_radius * 2, m_radius * 2);
}

void Circle::Move(int x, int y)
{
    m_cx += x;
    m_cy += y;
}

Smile::Smile(int cx, int cy, int radius):
    Circle(cx, cy, radius),
    m_leftEye(cx - radius/2, cy - radius/2, radius / 5),
    m_rightEye(cx + radius/2, cy - radius/2, radius / 5)
{
}

void Smile::Draw(Graphics* g)
{
    Circle::Draw(g);
    m_leftEye.Draw(g);
    m_rightEye.Draw(g);
    g->DrawLine(m_cx - m_radius / 2, m_cy + m_radius / 2,
        m_cx + m_radius / 2, m_cy + m_radius / 2);
    g->SetPixel(m_cx, m_cy);
}

void Smile::Move(int x, int y)
{
    Circle::Move(x, y);
    m_leftEye.Move(x, y);
    m_rightEye.Move(x, y);
}

Rectangle::Rectangle(int x, int y, int width, int height):
    m_x(x), m_y(y), m_width(width), m_height(height)
{
}

void Rectangle::Draw(Graphics* g)
{
    g->DrawRectangle(m_x, m_y, m_width, m_height);
}

void Rectangle::Move(int x, int y)
{
    m_x += x;
    m_y += y;
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3):
    m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2), m_x3(x3), m_y3(y3)
{
}

void Triangle::Draw(Graphics* g)
{
    g->DrawLine(m_x1, m_y1, m_x2, m_y2);
    g->DrawLine(m_x2, m_y2, m_x3, m_y3);
    g->DrawLine(m_x3, m_y3, m_x1, m_y1);
}

void Triangle::Move(int x, int y)
{
    m_x1 += x;
    m_x2 += x;
    m_x3 += x;
    m_y1 += y;
    m_y2 += y;
    m_y3 += y;
}