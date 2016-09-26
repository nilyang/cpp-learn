#pragma once
#ifndef __NILYANG_LINE__

#include"IShape.h"
class Line: public IShape
{
    std::string shapeName_;
public:
    Line(std::string name="Line") :shapeName_(name) {}
    virtual void Drawing() override
    {
        std::cout << "Drawing Line : " << shapeName_ << std::endl;
    }

};


#endif // !__NILYANG_LINE__