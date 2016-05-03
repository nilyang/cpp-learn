#pragma once

#ifndef __NILYANG_PROGRESSBAR__

#include<iostream>
#include"IObserver.h"
class ProgressBar: public IObserver
{
    int progress;
public:
    ProgressBar():progress(0){}
    virtual ~ProgressBar(){}

    void IncrProgress(int prg)
    {
        this->progress += prg;
    }

    int GetProgress() const
    {
        return this->progress;
    }

    virtual void Update()
    {
        this->IncrProgress(1);
        std::cout << ".";
    }


};

#endif // !__NILYANG_PROGRESSBAR__
