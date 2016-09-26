#pragma once
#ifndef __NILYANG_IPROGRESS__

class IObserver
{
public:
    virtual ~IObserver() {}
    virtual void Update()=0;
};
#endif // !__NILYANG_IPROGRESS__