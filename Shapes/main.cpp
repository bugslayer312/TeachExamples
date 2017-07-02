#include "ConsoleGraphics.h"
#include "HtmlGraphics.h"
#include "Shapes.h"

#include <list>

void PrintShapes(std::list<IShape*> const& shapes, IGraphics* graphics)
{
    for(IShape* shape : shapes)
    {
        shape->Draw(graphics);
    }
}

int main()
{
    ConsoleGraphics cg(80, 30);
    HtmlGraphics hg("shapes.html");
    std::list<IShape*> shapes;
    
    Triangle t1(1, 1, 10, 1, 6, 8);
    t1.Move(0, 3);
    shapes.push_back(&t1);
    Triangle t2(1, 8, 10, 8, 6, 1);
    shapes.push_back(&t2);
    Smile sm(10, 10, 9);
    Smile sm1(sm);
    sm1.Move(20, 0);
    shapes.push_back(&sm);
    shapes.push_back(&sm1);
    Rectangle r(1, 1, 40, 20);
    shapes.push_back(&r);
    
    PrintShapes(shapes, &cg);
    PrintShapes(shapes, &hg);
    
    return 0;
}