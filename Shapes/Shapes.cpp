#include "Shapes.h"
#include <iostream>

Circle::Circle(int cx, int cy, int radius) :
m_cx(cx),
m_cy(cy),
m_radius(radius)
{
}

void Circle::Init(int cx, int cy, int radius)
{
    m_cx = cx;
    m_cy = cy;
    m_radius = radius;
}

void Circle::Draw(IGraphics* g)
{
    g->DrawEllipse(m_cx - m_radius, m_cy - m_radius, m_radius * 2, m_radius * 2);
}

void Circle::Move(int x, int y)
{
    m_cx += x;
    m_cy += y;
}

void Circle::SaveToStream(std::ostream& stream)
{
    int id = StreamIdCircle;
    stream.write(reinterpret_cast<char*>(&id), sizeof(id));
    int size = sizeof(m_cx) + sizeof(m_cy) + sizeof(m_radius);
    stream.write(reinterpret_cast<char*>(&size), sizeof(size));
    stream.write(reinterpret_cast<char*>(&m_cx), sizeof(m_cx));
    stream.write(reinterpret_cast<char*>(&m_cy), sizeof(m_cy));
    stream.write(reinterpret_cast<char*>(&m_radius), sizeof(m_radius));
}

void Circle::LoadFromStream(std::istream& stream)
{
    int id;
    stream.read(reinterpret_cast<char*>(&id), sizeof(id));
    if (id != StreamIdCircle)
    {
        throw ShapeStreamReadException("Circle");
    }
    int size;
    stream.read(reinterpret_cast<char*>(&size), sizeof(size));
    if (size != sizeof(m_cx) + sizeof(m_cy) + sizeof(m_radius))
    {
        throw ShapeStreamReadException("Circle");
    }
    stream.read(reinterpret_cast<char*>(&m_cx), sizeof(m_cx));
    stream.read(reinterpret_cast<char*>(&m_cy), sizeof(m_cy));
    stream.read(reinterpret_cast<char*>(&m_radius), sizeof(m_radius));
}

Smile::Smile(int cx, int cy, int radius):
Circle(cx, cy, radius),
m_leftEye(cx - radius/2, cy - radius/2, radius / 5),
m_rightEye(cx + radius/2, cy - radius/2, radius / 5)
{
}

void Smile::Draw(IGraphics* g)
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

void Smile::SaveToStream(std::ostream& stream)
{
    int id = StreamIdSmile;
    stream.write(reinterpret_cast<char*>(&id), sizeof(id));
    int size = 3 * sizeof(int);
    stream.write(reinterpret_cast<char*>(&size), sizeof(size));
    stream.write(reinterpret_cast<char*>(&m_cx), sizeof(m_cx));
    stream.write(reinterpret_cast<char*>(&m_cy), sizeof(m_cy));
    stream.write(reinterpret_cast<char*>(&m_radius), sizeof(m_radius));
}

void Smile::LoadFromStream(std::istream& stream)
{
    int id;
    stream.read(reinterpret_cast<char*>(&id), sizeof(id));
    if (id != StreamIdSmile)
    {
        throw ShapeStreamReadException("Smile");
    }
    int size;
    stream.read(reinterpret_cast<char*>(&size), sizeof(size));
    if (size != 3 * sizeof(int))
    {
        throw ShapeStreamReadException("Smile");
    }
    stream.read(reinterpret_cast<char*>(&m_cx), sizeof(m_cx));
    stream.read(reinterpret_cast<char*>(&m_cy), sizeof(m_cy));
    stream.read(reinterpret_cast<char*>(&m_radius), sizeof(m_radius));
    m_leftEye.Init(m_cx - m_radius/2, m_cy - m_radius/2, m_radius / 5);
    m_rightEye.Init(m_cx + m_radius/2, m_cy - m_radius/2, m_radius / 5);
}

Rectangle::Rectangle(int x, int y, int width, int height):
m_x(x), m_y(y), m_width(width), m_height(height)
{
}

void Rectangle::Draw(IGraphics* g)
{
    g->DrawRectangle(m_x, m_y, m_width, m_height);
}

void Rectangle::Move(int x, int y)
{
    m_x += x;
    m_y += y;
}

void Rectangle::SaveToStream(std::ostream& stream)
{
    int id = StreamIdRectangle;
    stream.write(reinterpret_cast<char*>(&id), sizeof(id));
    int size = 4 * sizeof(int);
    stream.write(reinterpret_cast<char*>(&size), sizeof(size));
    stream.write(reinterpret_cast<char*>(&m_x), sizeof(m_x));
    stream.write(reinterpret_cast<char*>(&m_y), sizeof(m_y));
    stream.write(reinterpret_cast<char*>(&m_width), sizeof(m_width));
    stream.write(reinterpret_cast<char*>(&m_height), sizeof(m_height));
}

void Rectangle::LoadFromStream(std::istream& stream)
{
    int id;
    stream.read(reinterpret_cast<char*>(&id), sizeof(id));
    if (id != StreamIdRectangle)
    {
        throw ShapeStreamReadException("Rectangle");
    }
    int size;
    stream.read(reinterpret_cast<char*>(&size), sizeof(size));
    if (size != 4 * sizeof(int))
    {
        throw ShapeStreamReadException("Rectangle");
    }
    stream.read(reinterpret_cast<char*>(&m_x), sizeof(m_x));
    stream.read(reinterpret_cast<char*>(&m_y), sizeof(m_y));
    stream.read(reinterpret_cast<char*>(&m_width), sizeof(m_width));
    stream.read(reinterpret_cast<char*>(&m_height), sizeof(m_height));
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3):
m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2), m_x3(x3), m_y3(y3)
{
}

void Triangle::Draw(IGraphics* g)
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

void Triangle::SaveToStream(std::ostream& stream)
{
    int id = StreamIdTriangle;
    stream.write(reinterpret_cast<char*>(&id), sizeof(id));
    int size = 6 * sizeof(int);
    stream.write(reinterpret_cast<char*>(&size), sizeof(size));
    stream.write(reinterpret_cast<char*>(&m_x1), sizeof(m_x1));
    stream.write(reinterpret_cast<char*>(&m_y1), sizeof(m_y1));
    stream.write(reinterpret_cast<char*>(&m_x2), sizeof(m_x2));
    stream.write(reinterpret_cast<char*>(&m_y2), sizeof(m_y2));
    stream.write(reinterpret_cast<char*>(&m_x3), sizeof(m_x3));
    stream.write(reinterpret_cast<char*>(&m_y3), sizeof(m_y3));
}

void Triangle::LoadFromStream(std::istream& stream)
{
    int id;
    stream.read(reinterpret_cast<char*>(&id), sizeof(id));
    if (id != StreamIdTriangle)
    {
        throw ShapeStreamReadException("Triangle");
    }
    int size;
    stream.read(reinterpret_cast<char*>(&size), sizeof(size));
    if (size != 6 * sizeof(int))
    {
        throw ShapeStreamReadException("Triangle");
    }
    stream.read(reinterpret_cast<char*>(&m_x1), sizeof(m_x1));
    stream.read(reinterpret_cast<char*>(&m_y1), sizeof(m_y1));
    stream.read(reinterpret_cast<char*>(&m_x2), sizeof(m_x2));
    stream.read(reinterpret_cast<char*>(&m_y2), sizeof(m_y2));
    stream.read(reinterpret_cast<char*>(&m_x3), sizeof(m_x3));
    stream.read(reinterpret_cast<char*>(&m_y3), sizeof(m_y3));
}