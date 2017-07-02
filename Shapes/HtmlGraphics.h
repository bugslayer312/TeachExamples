#pragma once

#include "IGraphics.h"

#include <string>
#include <fstream>

class HtmlGraphics : public IGraphics
{
    std::ofstream m_file;
    
private:
    void BeginHtml();
    void EndHtml();
public:
    HtmlGraphics(std::string filename);
    ~HtmlGraphics() override;
    
    void SetPixel(int x, int y) override;
    void DrawLine(int x1, int y1, int x2, int y2) override;
    void DrawRectangle(int x, int y, int width, int height) override;
    void DrawEllipse(int x, int y, int width, int height) override;
};