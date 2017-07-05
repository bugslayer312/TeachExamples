#pragma once

#include "IGraphics.h"
#include <iosfwd>
#include <exception>
#include <string>

class IShape
{
public:
    virtual ~IShape() = default;
    virtual void Draw(IGraphics* g) = 0;
    virtual void Move(int x, int y) = 0;
    virtual void SaveToStream(std::ostream& stream) = 0;
    virtual void LoadFromStream(std::istream& stream) = 0;
};

enum StreamId
{
    StreamIdSceneBegin = 100,
    StreamIdSceneEnd,
    StreamIdCircle,
    StreamIdSmile,
    StreamIdRectangle,
    StreamIdTriangle
};

class ShapeStreamReadException : public std::exception
{
private:
    std::string m_error;
    
public:
    ShapeStreamReadException(std::string const& error): m_error(error)
    {
    }
    char const* what() const noexcept override
    {
        return (std::string("Invalid stream format: ") + m_error).c_str();
    }
};