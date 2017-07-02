#pragma once

#include "IGraphics.h"

#include <cstddef>

class ConsoleGraphics : public IGraphics
{
    size_t m_width;
    size_t m_height;
    
    char* m_data = nullptr;
    
public:
    ConsoleGraphics(size_t width, size_t height);
    ~ConsoleGraphics() override;
    
    void SetPixel(int x, int y) override;
    void DrawLine(int x1, int y1, int x2, int y2) override;
    void DrawRectangle(int x, int y, int width, int height) override;
    void DrawEllipse(int x, int y, int width, int height) override;
};