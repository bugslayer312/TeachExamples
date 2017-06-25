#include <iostream>

#include "Shape.h"
#include "Graphics.h"
#include "HtmlGraphics.h"

int main()
{
    Graphics g(80, 30);
    
    Smile s(15, 12, 10);
    s.Draw(&g);
    
    HtmlGraphics hg("graphics.html");
    hg.SetPixel(10, 10);
    hg.SetPixel(20, 20);
    
    hg.DrawLine(11, 10, 21, 20);
    
    hg.DrawRectangle(5, 5, 15, 10);
    hg.DrawEllipse(5, 5, 15, 10);
    return 0;
}