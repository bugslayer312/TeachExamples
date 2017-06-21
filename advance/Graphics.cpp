#include "Graphics.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>
#include <utility>

Graphics::Graphics(size_t width, size_t height) : m_width(width), m_height(height)
{
    m_data = new char[m_width * m_height];
    memset(m_data, ' ', m_width * m_height);
}

Graphics::~Graphics()
{
    for (size_t i = 0; i < m_height; ++i)
    {
        for (size_t j = 0; j < m_width; ++j)
        {
            std::cout << m_data[i * m_width + j];
        }
        std::cout << std::endl;
    }
    delete[] m_data;
}

void Graphics::SetPixel(int x, int y)
{
    m_data[(y - 1) * m_width + x - 1] = '#';
}

void Graphics::DrawLine(int x1, int y1, int x2, int y2)
{
    if (y1 == y2)
    {
        if (y1 > 0 && y1 <= m_height)
        {
            if (x1 > x2)
            {
                std::swap(x1, x2);
            }
            for (int x = std::max(1, x1); x <= std::min(x2, static_cast<int>(m_width)); ++x)
            {
                m_data[(y1 - 1) * m_width + x - 1] = '#';
            }
        }
    }
    else if (x1 == x2)
    {
        if (x1 > 0 && x1 <= m_height)
        {
            if (y1 > y2)
            {
                std::swap(y1, y2);
            }
            for (int y = std::max(1, y1); y <= std::min(y2, static_cast<int>(m_height)); ++y)
            {
                m_data[(y - 1) * m_width + x1 - 1] = '#';
            }
        }
    }
    else
    {
        if (y2 < y1)
        {
            std::swap(y1, y2);
            std::swap(x1, x2);
        }
        double k = static_cast<double>(y2 - y1) / (x2 - x1);
        for (int iy = std::max(1, y1); iy <= std::min(y2, static_cast<int>(m_height)); ++iy)
        {
            double x_ = x1 + (iy - y1) / k;
            double y_ = iy;
            int x, y;
            x = static_cast<int>(x_);
            y = static_cast<int>(y_);
            do
            {
                m_data[(y - 1) * m_width + x - 1] = '#';
                x_ -= 1.0;
                y_ = y1 + k * (x_ - x1);
                x = static_cast<int>(x_);
                y = static_cast<int>(y_);
            } while (fabs(y_ - iy) < 0.5 && x > 0 && x <= m_width);
            x = static_cast<int>(x_);
            y = static_cast<int>(y_);
            do
            {
                m_data[(y - 1) * m_width + x - 1] = '#';
                x_ += 1.0;
                y_ = y1 + k * (x_ - x1);
                x = static_cast<int>(x_);
                y = static_cast<int>(y_);
            } while (fabs(y_ - iy) < 0.5 && x > 0 && x <= m_width);
        }
    }
}

void Graphics::DrawRectangle(int x, int y, int width, int height)
{
    int x2 = x + width;
    int y2 = y + height;
    for (int ix = std::max(1, x); ix <= std::min(x2, static_cast<int>(m_width)); ++ix)
    {
        if (y > 0 && y <= m_height)
        {
            m_data[(y - 1) * m_width + ix - 1] = '#';
        }
        if (y2 > 0 && y2 <= m_height)
        {
            m_data[(y2 - 1) * m_width + ix - 1] = '#';
        }
    }
    for (int iy = std::max(1, y); iy <= std::min(y2, static_cast<int>(m_height)); ++iy)
    {
        if (x > 0)
        {
            m_data[(iy - 1) * m_width + x - 1] = '#';
        }
        if (x2 > 0)
        {
            m_data[(iy - 1) * m_width + x2 - 1] = '#';
        }
    }
}

void Graphics::DrawEllipse(int x, int y, int width, int height)
{
    double a = ceil(width / 2.0);
    double b = ceil(height / 2.0);

    double cx = x + a;
    double cy = y + b;

    for (int h = 0; h <= b; ++h)
    {
        double _h = h;
        double _w = round(sqrt(a * a * (1.0 - _h * _h / (b * b))));
        int w1 = static_cast<int>(_w);
        while (fabs(_h - h) < 0.5)
        {
            w1 = static_cast<int>(_w);
            _w -= 1.0;
            _h = sqrt(b * b * (1.0 - _w * _w / (a * a)));
        }

        _h = h;
        _w = round(sqrt(a * a * (1.0 - _h * _h / (b * b))));
        int w2 = static_cast<int>(_w);
        while (fabs(_h - h) < 0.5)
        {
            w2 = static_cast<int>(_w);
            _w += 1.0;
            _h = sqrt(b * b * (1.0 - _w * _w / (a * a)));
        }

        int ys[] = { static_cast<int>(cy - h), static_cast<int>(cy + h) };
        for (int w = w1; w <= w2; ++w)
        {
            int xs[] = { static_cast<int>(cx - w), static_cast<int>(cx + w) };
            for (int i = 0; i < 2; ++i)
            {
                int yy = ys[i];
                if (yy > 0 && yy <= m_height)
                {
                    for (int j = 0; j < 2; ++j)
                    {
                        if (xs[j] > 0 && xs[j] <= m_width)
                        {
                            m_data[(yy - 1) * m_width + xs[j] - 1] = '#';
                        }
                    }
                }
            }
        }
    }
}