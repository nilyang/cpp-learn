#pragma once
#ifndef __NILYANG_PROGRAMER__
#define __NILYANG_PROGRAMER__

#include<iostream>
#include<string>

//类模板/函数模板

struct Programmer
{
    Programmer(const int id=0, std::wstring name=L"\0")
        :Id(id), Name(name)
    {}

    void Print() const
    {
        std::wcout << L"[" << Id << L"]:" << Name << std::endl;
    }

    //比较Id
    bool operator< (const Programmer &right) const
    {
        return Id < right.Id;
    }

    //比较名字
    bool operator> (const Programmer & right) const
    {
        return Name > right.Name;
    }

    bool operator== (const Programmer &right) const 
    {
        return Id == right.Id && Name==right.Name;
    }

    bool operator!= (const Programmer & right) const
    {
        return !(*this==right);
    }

    Programmer& setName(std::wstring name)
    {
        Name = name;
        return *this;
    }

    int Id;
    std::wstring Name;
};

inline
std::wostream & operator<<(std::wostream &wos, const Programmer & obj)
{
    return wos << L"[" << obj.Id << L"]:" << obj.Name << "\n";
}


//初始化set用的，按照指定顺序插入set的仿函数
template<typename T>
struct ProgrammerIdGreater
{
    bool operator()(const T& left, const T& right) const
    {
        //按ID降序
        return right < left ;
    }
};

//按名字升序
template<typename T>
struct ProgrammerNameComparer
{
    bool operator()(const T& left, const T& right) const
    {
        return right > left;
    }
};

//for_each打印使用的仿函数
struct PrintProgrammer
{
    void operator()(const Programmer& obj) const
    {
        obj.Print();
    }
};

//find_if元素查找比较用的仿函数
struct FindProgramer
{
    FindProgramer(Programmer &obj)
        :givenObj(obj)
    {}

    bool operator()(const Programmer& obj) const
    {
        return givenObj == obj;
    }

    Programmer givenObj;
};


//find_if使用的仿函数，用来测试是否可以在查找时修改set元素
//该functor只是一个测试是否可以修改的探索
//发现find_if算法根本不允许在查找时修改正在进行查找比较的集合元素 ：-（
struct FindAndModifyProgrammer
{
    FindAndModifyProgrammer(Programmer &obj, std::wstring _newName)
        :givenObj(obj), newName(_newName)
    {}

    //此处尝试使用&，传递引用来修改obj，但编译器无法通过，
    //所以确定的是，无法在find_if算法里面修改
    //原始对象的内容
    bool operator()(const Programmer &obj) const
    {
        bool is_found = (givenObj == obj);
        if (is_found) {
            //obj.setName(givenObj.Name);//算法不允许修改
            obj.Print();
        }

        return is_found;
    }

    std::wstring newName;
    Programmer givenObj;
};

#endif // __NILYANG_PROGRAMER__
