#pragma once

#include "IShape.h"
#include <list>
#include <iosfwd>

class Scene
{
    std::list<IShape*> m_shapes;
    
public:
    ~Scene();
    
    void Add(IShape* shape);
    void Clear();
    void Print(IGraphics* graphics);
    void SaveToStream(std::ostream& stream);
    void LoadFromStream(std::istream& stream);
};