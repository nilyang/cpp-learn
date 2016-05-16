#pragma once
#ifndef __NILYANG_SHAPE__
#include<iostream>

//ÐÎ×´£¨Ðé£©»ùÀà
class IShape
{
public:
    
    virtual void Drawing() = 0;
    virtual ~IShape() {}
};

#endif // !__NILYANG_SHAPE__