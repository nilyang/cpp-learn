#pragma once
#ifndef __NILYANG_DRAWINGSYSTEM__

#include"IShape.h"
#include"IShapeFactory.h"

class DrawingSystem
{
    IShapeFactory * factory; 
public:
    DrawingSystem(IShapeFactory* _factory)
    {
        if (_factory != nullptr) {
            factory = _factory;
        }
    }

    ~DrawingSystem()
    {
        if (factory != nullptr) {
            delete factory;
        }
    }

    void DoDrawing()
    {
        IShape* pShape = factory->CreateShape(); 
        pShape->Drawing();
        delete pShape;
    }
};
#endif // !__NILYANG_DRAWINGSYSTEM__