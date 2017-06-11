#pragma once

class Point
{
private:
    int m_x;
    int m_y;
    
public:
    Point();                // default constructor
    Point(int x, int y);    // constructor with parameters
    int GetX() const;
    int GetY() const;
    void Init(int x, int y);
    void Read();
    void Print() const;
    void Move(int x, int y);
};

class Size
{
private:
    int m_width;
    int m_heigh;
    
public:
    Size();                         // default constructor
    Size(int width, int height);    // constructor with parameters
    int GetWidth() const;
    int GetHeight() const;
    void Init(int width, int height);
    void Read();
    void Print() const;
    void Scale(float xscale, float yscale);
    bool IsEmpty() const;
};

class Rectangle
{
private:
    Point m_origin;
    Size m_size;
    
    int GetLeft() const;
    int GetRight() const;
    int GetTop() const;
    int GetBottom() const;
    
public:
    Rectangle();                                        // default constructor
    Rectangle(int x, int y, int width, int height);     // constructor with parameters
    Rectangle(Point const& origin, Size const& size);   // constructor with parameters
    Rectangle(int width, int height);                   // constructor with parameters

    Point const& GetOrigin() const;
    Size const& GetSize() const;
    void Init(int x, int y, int width, int height);
    void Init(Point const& origin, Size const& size);
    void Move(int x, int y);
    bool IsEmpty() const;
    bool Contains(Point& p) const;
    Rectangle IntersectWith(Rectangle const& r) const;
    void Read();
    void Print() const;
};
