#pragma once

class IGraphics
{
public:
    virtual ~IGraphics() = default;
    
    virtual void SetPixel(int x, int y) = 0;
    virtual void DrawLine(int x1, int y1, int x2, int y2) = 0;
    virtual void DrawRectangle(int x, int y, int width, int height) = 0;
    virtual void DrawEllipse(int x, int y, int width, int height) = 0;
};