#include "HtmlGraphics.h"
#include <stdio.h>

int SvgWidth = 1000;
int SvgHeight = 800;

char const* const Stroke = "stroke=\"black\" stroke-width=\"3\"";
char const* const Style = "style=\"stroke:rgb(0,0,0);stroke-width:3\"";
int const Scale = 10;

void HtmlGraphics::BeginHtml()
{
    m_file << "<!DOCTYPE html>" << std::endl;
    m_file << "<html>" << std::endl;
    m_file << "\t<body>" << std::endl;
    m_file << "\t\t<svg height=\"" << SvgHeight << "\" width=\"" << SvgWidth << "\">" << std::endl;
}

void HtmlGraphics::EndHtml()
{
    m_file << "\t\t</svg>" << std::endl;
    m_file << "\t</body>" << std::endl;
    m_file << "</html>" << std::endl;
}

HtmlGraphics::HtmlGraphics(std::string filename)
{
    remove(filename.c_str());
    m_file.open(filename);
    BeginHtml();
}

HtmlGraphics::~HtmlGraphics()
{
    EndHtml();
    m_file.close();
}

void HtmlGraphics::SetPixel(int x, int y)
{
    x *= Scale;
    y *= Scale;
    
    m_file << "\t\t\t<path d=\"M " << x-2 << " " << y << " L " << x+2 << " " << y << "\" " << Stroke << " />" << std::endl;
}

void HtmlGraphics::DrawLine(int x1, int y1, int x2, int y2)
{
    x1 *= Scale;
    y1 *= Scale;
    x2 *= Scale;
    y2 *= Scale;
    m_file << "\t\t\t<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2 <<
    "\" " << Stroke << " />" << std::endl;
}

void HtmlGraphics::DrawRectangle(int x, int y, int width, int height)
{
    x *= Scale;
    y *= Scale;
    width *= Scale;
    height *= Scale;
    m_file << "\t\t\t<rect x=\"" << x << "\" y=\"" << y << "\" width=\"" <<
    width << "\" height=\"" << height << "\" " << Stroke << " fill=\"none\" />" << std::endl;
}

void HtmlGraphics::DrawEllipse(int x, int y, int width, int height)
{
    x *= Scale;
    y *= Scale;
    width *= Scale;
    height *= Scale;
    m_file << "\t\t\t<ellipse cx=\"" << x + width/2 << "\" cy=\"" << y + height/2 <<
    "\" rx=\"" << width/2 << "\" ry=\"" << height/2 << "\" " << Stroke << " fill=\"none\" />" << std::endl;
}