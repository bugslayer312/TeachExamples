#pragma once

class Graphics
{
    size_t m_width;
    size_t m_height;

    char* m_data = nullptr;

public:
    Graphics(size_t width, size_t height);
    ~Graphics();

    void SetPixel(int x, int y);
    void DrawLine(int x1, int y1, int x2, int y2);
    void DrawRectangle(int x, int y, int width, int height);
    void DrawEllipse(int x, int y, int width, int height);
};