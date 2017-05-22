#pragma once

class Point
{
private:
    int m_x;
    int m_y;
    
public:
    int GetX();
    int GetY();
    void Init(int x, int y);
    void Read();
    void Print();
    void Move(int x, int y);
};

class Size
{
private:
    int m_width;
    int m_heigh;
    
public:
    int GetWidth();
    int GetHeight();
    void Init(int width, int height);
    void Read();
    void Print();
    void Scale(float xscale, float yscale);
    bool IsEmpty();
};

class Rectangle
{
private:
    Point m_origin;
    Size m_size;
    
    int GetLeft();
    int GetRight();
    int GetTop();
    int GetBottom();
    
public:
    Point GetOrigin();
    Size GetSize();
    void Init(int x, int y, int width, int height);
    void Init(Point const& origin, Size const& size);
    void Move(int x, int y);
    bool IsEmpty();
    bool Contains(Point& p);
    Rectangle IntersectWith(Rectangle& r);
    void Read();
    void Print();
};