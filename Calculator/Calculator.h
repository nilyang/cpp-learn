#pragma once
#ifndef __NILYANG_CALCULATOR__

template<typename T>
struct ReturnLimit
{
    typedef T ReturnType;
    ReturnType Limit;
};

template<>
struct ReturnLimit<int>
{
    typedef int ReturnType;
    ReturnType Limit=100;
};

template<>
struct ReturnLimit<long>
{
    typedef long ReturnType;
    ReturnType Limit = 1000L;
};

template<>
struct ReturnLimit<float>
{
    typedef float ReturnType;
    ReturnType Limit = 999.99F;
};

template<>
struct ReturnLimit<double>
{
    typedef double ReturnType;
    ReturnType Limit = 888.8888888;
};


template<typename T>
struct Calculator : ReturnLimit<T>
{
    ReturnType GetLimit()
    {
        return Limit;
    }
};


#endif // !__NILYANG_CALCULATOR__