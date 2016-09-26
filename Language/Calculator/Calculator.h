#pragma once
#ifndef __NILYANG_CALCULATOR__

namespace NILYANG {

    //浮点型特化使用到的精度输出控制
    struct Precision
    {
        int _Prec = 0;
        Precision(int prec = 0) :_Prec(prec) {}

        int getPrecision() const
        {
            return _Prec;
        }

        void setPrecision(int Prec)
        {
            if (Prec < 0) {
                std::cout << "Prec error" << std::endl;
                return;
            }

            _Prec = Prec;
        }

    };

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
        ReturnType Limit = 100;
    };

    template<>
    struct ReturnLimit<long>
    {
        typedef long ReturnType;
        ReturnType Limit = 1000L;
    };

    template<>
    struct ReturnLimit<float>:public Precision
    {
        typedef float ReturnType;
        ReturnType Limit = 999.99F;
        ReturnLimit() :Precision(2) { }
    };

    template<>
    struct ReturnLimit<double>:public Precision
    {
        typedef double ReturnType;
        ReturnType Limit = 888.8888888;
        ReturnLimit() :Precision(7) {}
    };


    template<typename T>
    struct Calculator : ReturnLimit<T>
    {
        ReturnType GetLimit()
        {
            return Limit;
        }
    };

}

#endif // !__NILYANG_CALCULATOR__