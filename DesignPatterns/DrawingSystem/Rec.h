#pragma once
#ifndef __NILYANG_REC__
#include"IShape.h"
#include"IShapeFactory.h"
class Rec:public IShape
{
public:
    virtual void Drawing()
    {
        std::cout << "Drawing Rec " << std::endl;
    }

};
class RecFactory : public IShapeFactory
{
public:
    virtual IShape* CreateShape()
    {
        IShape* pShape = new Rec();
        return pShape;
    }
};
#endif // !__NILYANG_REC__