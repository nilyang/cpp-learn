#pragma once
#ifndef __NILYANG_VECTOR__
#include<vector>

//
template<typename T> 
std::vector<T> my_not_equal_to(std::vector<T>& v1,  T equal_to);

template<typename T>
inline std::vector<T> my_not_equal_to(std::vector<T>& v1, T equal_to)
{
    std::vector<T> v2;
    for (std::vector<T>::iterator it = v1.begin(); it < v1.end();it++)
    {
        if (*it != 0) {
            v2.push_back(*it);
        }
    }

    return v2;
}

#endif // !__NILYANG_VECTOR__
