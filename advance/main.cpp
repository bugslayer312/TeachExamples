#include <iostream>

#include "Shape.h"
#include "Graphics.h"

int main()
{
    Graphics g(80, 30);
    
    Smile s(15, 12, 10);
    s.Draw(&g);
    
    
    return 0;
}