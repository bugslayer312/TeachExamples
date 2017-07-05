#include "ConsoleGraphics.h"
#include "HtmlGraphics.h"
#include "Shapes.h"
#include "Scene.h"

#include <list>
#include <fstream>

void PrintShapes(std::list<IShape*> const& shapes, IGraphics* graphics)
{
    for(IShape* shape : shapes)
    {
        shape->Draw(graphics);
    }
}

void testPrintShapes()
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
}

void testSaveScene(Scene& scene)
{
    scene.Add(new Triangle(1, 8, 10, 8, 6, 1));
    scene.Add(new Circle(10, 10, 5));
    scene.Add(new Smile(5, 10, 5));
    scene.Add(new Rectangle(1, 1, 20, 10));
    
    std::ofstream ofs("shapes.bin", std::ios::out|std::ios::trunc|std::ios::binary);
    scene.SaveToStream(ofs);
}

void testLoadScene(Scene& scene)
{
    std::ifstream ifs("shapes.bin", std::ios::in|std::ios::binary);
    scene.LoadFromStream(ifs);
    ConsoleGraphics cg(21, 20);
    scene.Print(&cg);
}

int main()
{
    Scene scene;
    testLoadScene(scene);
    
    return 0;
}