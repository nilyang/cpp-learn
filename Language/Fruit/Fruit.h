#pragma once
#ifndef __NILYANG_FRUIT__
#define __NILYANG_FRUIT__

class Fruit {
    int no;
    double weight;
    char key;
public:
    Fruit(int _no=0,double _wt=0,char _k='F')
        :no(_no),weight(_wt),key(_k)
    {
        std::cout << __FUNCTION__ << "'s ctor, this's address = " << this <<"\n";
    }
    
    virtual ~Fruit()
    {
        std::cout << __FUNCTION__ << "'s dtor " << "\n";
    }

    void print()
    {
        std::cout << "no's address = " << &no << "\n";
        std::cout << "weight's address = " << &weight << "\n";
        std::cout << "key's address = " << static_cast<void *>(&key) << "\n";
    }
    virtual void process() 
    {
        print();  
    }
    
};

class Apple : public Fruit {
    int size;
    char type;
public:
    Apple(int _no=0,double _wt=0,char _key='F',
          int _size=0,char _type='A')
        :Fruit(_no,_wt,_key),size(_size),type(_type)
    {
        
        std::cout << __FUNCTION__ << "'s ctor , this's address = " << this << "\n";
        
    }
    virtual ~Apple()
    {
        std::cout << __FUNCTION__ << "'s dtor" << "\n";
    }

    void print()
    {
        std::cout << "size's address = " << &size << "\n";
        std::cout << "type's address = " << static_cast<void *>(&type) << "\n";
    }

    void save() { }
    
    virtual void process() 
    { 
        Fruit::process();
        print();
    }
};


void * FruitAllocate(size_t size)
{
    return malloc(size);
}
void FruitFree(void *ptr)
{
   return free(ptr);
}

//重载全局new和delete
inline void *
::operator new(size_t size)
{
    void * addr = FruitAllocate(size);
    std::cout << "fuit malloc size = " << size << ",address = "<< addr<< "\n";
    return addr;
}

inline void 
::operator delete(void *ptr)
{
    std::cout << "fuit free\n";
    std::cout << "delete address = " << ptr << "\n";
    return FruitFree(ptr);
}


#endif