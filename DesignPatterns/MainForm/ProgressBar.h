#pragma once

#ifndef __NILYANG_PROGRESSBAR__

class ProgressBar: public IObserver
{
    int progress;
public:
    ProgressBar(){}
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
    }

};

#endif // !__NILYANG_PROGRESSBAR__
