#pragma once

#ifndef __NILYANG_PROGRESSBAR__

class ProgressBar
{
    int progress;
public:
    void IncrProgress(int prg)
    {
        this->progress += prg;
    }

    int GetProgress() const
    {
        return this->progress;
    }

    
};

#endif // !__NILYANG_PROGRESSBAR__
