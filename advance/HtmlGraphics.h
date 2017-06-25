#pragma once

#include <string>
#include <fstream>

class HtmlGraphics
{
    std::ofstream m_file;

private:
    void BeginHtml();
    void EndHtml();
public:
    HtmlGraphics(std::string filename);
    ~HtmlGraphics();
    
    void SetPixel(int x, int y);
    void DrawLine(int x1, int y1, int x2, int y2);
    void DrawRectangle(int x, int y, int width, int height);
    void DrawEllipse(int x, int y, int width, int height);
};