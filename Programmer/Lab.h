#pragma once
#ifndef __NILYANG__LAB__

#include<string>
#include"Programer.h"

template<class T>
struct customer_allocator {
    typedef T value_type;
    customer_allocator() noexcept {}
    template <class U> customer_allocator(const customer_allocator<U> &) noexcept {}
    T* allocate(std::size_t n)
    {
        return static_cast<T*>(::new(n*sizeof(T)));
    }

    void deallocate(T* p, std::size_t n)
    {
        ::delete(p);
    }
};


//任意长度字符串比较
template<size_t N, size_t M>
int compare(const char(&)[N], const char(&)[M]);


template<size_t N, size_t M>
inline int compare(const char(&a)[N], const char(&b)[M])
{
    return strcmp(a, b);
}




#endif // !__NILYANG__LAB__
