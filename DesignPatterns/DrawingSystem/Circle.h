#pragma once
#ifndef __NILYANG_CIRCLE__
#include"IShape.h"
#include"IShapeFactory.h"
class Circle: public IShape
{
public:
    virtual void Drawing()
    {
        std::cout << "Drawing Circle " << std::endl;
    }
};

class CircleFactory :public IShapeFactory
{
public:
    virtual IShape* CreateShape()
    {
        IShape* pShape = new Circle();
        return pShape;
    }
};
#endif // !__NILYANG_CIRCLE__