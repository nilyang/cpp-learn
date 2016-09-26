#pragma once
#ifndef __NILYANG_SHAPEFACTORY__
#include"IShape.h"
class IShapeFactory
{
public:
    virtual IShape* CreateShape() = 0;
    virtual ~IShapeFactory(){}
};
#endif // !__NILYANG_SHAPEFACTORY__