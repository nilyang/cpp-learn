#pragma once
#ifndef __NILYANG_CIRCLE__
#include"IShape.h"
class Circle: public IShape
{
    std::string shapeName_;
public:
    Circle(std::string name= "Circle") :shapeName_(name) {}
    
    virtual void Drawing() override
    {
        std::cout << "Drawing : " << shapeName_ << std::endl;
    }
};

#endif // !__NILYANG_CIRCLE__