#pragma once
#ifndef __NILYANG_SHAPE__
#include<iostream>
#include<string>
//��״���飩����
class IShape
{
public:
    
    virtual void Drawing() = 0;
    virtual ~IShape() {}
};

#endif // !__NILYANG_SHAPE__