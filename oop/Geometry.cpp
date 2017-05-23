#include "Geometry.h"

#include <iostream>

// Point

// without using initialization list
/*
Point::Point()
{
    m_x = m_y = 0;
}

Point::Point(int x, int y)
{
    m_x = x;
    m_y = y;
}
*/

// using initialization list
Point::Point() :
    m_x(0),
    m_y(0)
{
}

Point::Point(int x, int y) :
    m_x(x),
    m_y(y)
{
}

int Point::GetX()
{
    return m_x;
}

int Point::GetY()
{
    return m_y;
}

void Point::Init(int x, int y)
{
    m_x = x;
    m_y = y;
}

void Point::Read()
{
    std::cout << "Enter point coordinates: x y\n";
    std::cin >> m_x >> m_y;
}

void Point::Print()
{
    std::cout << m_x << ", " << m_y << "\n";
}

void Point::Move(int x, int y)
{
    m_x += x;
    m_y += y;
}

// Size

// without using initialization list
/*
Size::Size()
{
    m_width = m_heigh = 0;
}

Size::Size(int width, int height)
{
    m_width = width;
    m_heigh = height;
}
*/

// using initialization list
Size::Size() :
    m_width(0),
    m_heigh(0)
{
}

Size::Size(int width, int height) :
    m_width(width),
    m_heigh(height)
{
}

int Size::GetWidth()
{
    return m_width;
}

int Size::GetHeight()
{
    return m_heigh;
}

void Size::Init(int width, int height)
{
    m_width = width;
    m_heigh = height;
}

void Size::Read()
{
    std::cout << "Enter width height\n";
    std::cin >> m_width >> m_heigh;
}

void Size::Print()
{
    std::cout << m_width << ", " << m_heigh << "\n";
}

void Size::Scale(float xscale, float yscale)
{
    m_width *= xscale;
    m_heigh *= yscale;
}

bool Size::IsEmpty()
{
    return m_width == 0 || m_heigh == 0;
}

// Rectangle

// without using initialization list
/*
Rectangle::Rectangle()
{
    m_origin.Init(0, 0);
    m_size.Init(0, 0);
}

Rectangle::Rectangle(int x, int y, int width, int height)
{
    m_origin.Init(x, y);
    m_size.Init(width, height);
}

Rectangle::Rectangle(Point const& origin, Size const& size)
{
    m_origin = origin;
    m_size = size;
}
*/

// using initialization list

Rectangle::Rectangle() :
    m_origin(),
    m_size()
{
}

Rectangle::Rectangle(int x, int y, int width, int height) :
    m_origin(x, y),
    m_size(width, height)
{
}

Rectangle::Rectangle(Point const& origin, Size const& size) :
    m_origin(origin),
    m_size(size)
{
}

// delegating constructors: calling constructor from constructor

Rectangle::Rectangle(int width, int height) :
    Rectangle(0, 0, width, height)
{
}

Point Rectangle::GetOrigin()
{
    return m_origin;
}

Size Rectangle::GetSize()
{
    return m_size;
}

int Rectangle::GetLeft()
{
    return m_origin.GetX();
}

int Rectangle::GetRight()
{
    return m_origin.GetX() + m_size.GetWidth();
}

int Rectangle::GetTop()
{
    return m_origin.GetY() + m_size.GetHeight();
}

int Rectangle::GetBottom()
{
    return m_origin.GetY();
}

void Rectangle::Init(int x, int y, int width, int height)
{
    m_origin.Init(x, y);
    m_size.Init(width, height);
}

void Rectangle::Init(Point const& origin, Size const& size)
{
    m_origin = origin;
    m_size = size;
}

void Rectangle::Move(int x, int y)
{
    m_origin.Move(x, y);
}

bool Rectangle::IsEmpty()
{
    return m_size.IsEmpty();
}

bool Rectangle::Contains(Point& p)
{
    return GetLeft() <= p.GetX() && p.GetX() <= GetRight() && GetBottom() <= p.GetY() && p.GetY() <= GetTop();
}

Rectangle Rectangle::IntersectWith(Rectangle& r)
{
    Rectangle result;
    result.Init(0, 0, 0, 0);
    int left = GetLeft();
    if (r.GetLeft() > left)
    {
        left = r.GetLeft();
    }
    int right = GetRight();
    if (r.GetRight() < right)
    {
        right = r.GetRight();
    }
    int bottom = GetBottom();
    if (r.GetBottom() > bottom)
    {
        bottom = r.GetBottom();
    }
    int top = GetTop();
    if (r.GetTop() < top)
    {
        top = r.GetTop();
    }
    if (right > left && top > bottom)
    {
        result.Init(left, bottom, right - left, top - bottom);
    }
    return result;
}

void Rectangle::Read()
{
    m_origin.Read();
    m_size.Read();
}

void Rectangle::Print()
{
    std::cout << "x: " << m_origin.GetX() << "y: " << m_origin.GetY() <<
        "width: " << m_size.GetWidth() << "height: " << m_size.GetHeight() << std::endl;
}
