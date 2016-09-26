#pragma once
#ifndef __NILYANG_LINE__
#include "IShape.h"
#include "IShapeFactory.h"
class Line: public IShape
{
public:
    virtual void Drawing()
    {
        std::cout << "Drawing Line " << std::endl;
    }

};

class LineFactory : public IShapeFactory
{
public:
    virtual IShape* CreateShape()
    {
        IShape* pShape = new Line();
        return pShape;
    }
};
#endif // !__NILYANG_LINE__