#pragma once
#ifndef __NILYANG_PROGRAMER__
#define __NILYANG_PROGRAMER__

#include<iostream>
#include<string>

//��ģ��/����ģ��

struct Programmer
{
    Programmer(const int id=0, std::wstring name=L"\0")
        :Id(id), Name(name)
    {}

    void Print() const
    {
        std::wcout << L"[" << Id << L"]:" << Name << std::endl;
    }

    //�Ƚ�Id
    bool operator< (const Programmer &right) const
    {
        return Id < right.Id;
    }

    //�Ƚ�����
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


//��ʼ��set�õģ�����ָ��˳�����set�ķº���
template<typename T>
struct ProgrammerIdGreater:public std::binary_function<T, T, bool>
{
    bool operator()(const T& left, const T& right) const
    {
        //��ID����
        return right < left ;
    }
};

//����������
template<typename T>
struct ProgrammerNameComparer:public std::binary_function<T, T, bool>
{
    bool operator()(const T& left, const T& right) const
    {
        return right > left;
    }
};

//for_each��ӡʹ�õķº���
struct PrintProgrammer
{
    void operator()(const Programmer& obj) const
    {
        obj.Print();
    }
};

//find_ifԪ�ز��ұȽ��õķº���
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


//find_ifʹ�õķº��������������Ƿ�����ڲ���ʱ�޸�setԪ��
//��functorֻ��һ�������Ƿ�����޸ĵ�̽��
//����find_if�㷨�����������ڲ���ʱ�޸����ڽ��в��ұȽϵļ���Ԫ�� ��-��
struct FindAndModifyProgrammer
{
    FindAndModifyProgrammer(Programmer &obj, std::wstring _newName)
        :givenObj(obj), newName(_newName)
    {}

    //�˴�����ʹ��&�������������޸�obj�����������޷�ͨ����
    //����ȷ�����ǣ��޷���find_if�㷨�����޸�
    //ԭʼ���������
    bool operator()(const Programmer &obj) const
    {
        bool is_found = (givenObj == obj);
        if (is_found) {
            //obj.setName(givenObj.Name);//�㷨�������޸�
            obj.Print();
        }

        return is_found;
    }

    std::wstring newName;
    Programmer givenObj;
};

#endif // __NILYANG_PROGRAMER__