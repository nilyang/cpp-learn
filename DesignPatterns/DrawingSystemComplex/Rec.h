#pragma once
#ifndef __NILYANG_REC__

#include"IShape.h"

class Rec:public IShape
{
    std::string shapeName_;
public:
    Rec(std::string name="Rec") :shapeName_(name) {}
    virtual void Drawing() override
    {
        std::cout << "Drawing Rec : " << shapeName_ << std::endl;
    }
};

#endif // !__NILYANG_REC__