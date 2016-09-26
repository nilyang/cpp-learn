#pragma once
#ifndef __NILYANG_COMPLEXSHAPEFACTORY__


#include<algorithm>
#include<string>
#include<list>
#include<memory>
#include"IShape.h"

class ComplexShape :public IShape
{
    std::string shapeName_;
    std::list<IShape*> *container_;
public:
    ComplexShape(std::string name) :
        shapeName_(name),container_{ new std::list<IShape*>() }
    {
        //init
    }
    ~ComplexShape()
    {
        CleanComponents();
    }
    //拷贝构造
    ComplexShape(const ComplexShape & complex)
    {
        if (container_ != nullptr) {
            CleanComponents();
        }

        shapeName_ = complex.shapeName_;
        if (complex.container_ != nullptr) {   
            container_->resize(complex.container_->size());
            std::copy(complex.container_->begin(), complex.container_->end(),
                container_->begin());
        }
        else {
            container_ = nullptr;
        }
    }
    //赋值构造
    ComplexShape operator=(const ComplexShape& complex)
    {
        if (container_ != nullptr) {
            CleanComponents();
        }

        shapeName_ = complex.shapeName_;
        if (complex.container_ != nullptr) {
            container_->resize(complex.container_->size());
            std::copy(complex.container_->begin(), complex.container_->end(),
                container_->begin());
        }
        else {
            container_ = nullptr;
        }
    }

    void CleanComponents()
    {
        std::for_each(container_->begin(), container_->end(), std::default_delete<IShape>());
        if (container_ != nullptr) {
            delete container_;
        }
    }

    //添加图形
    void AddShape(IShape* pShape)
    {
        container_->push_back(pShape);
    }

    //删除图形
    void RemoveShape(IShape* pShape)
    {
        if (container_)
            container_->remove(pShape);
    }

    //公共方法
    virtual void Drawing() override
    {
        //do some current thing..
        std::cout << "\n=====BEGIN COMPLEX Shape: " << shapeName_ << "======" << std::endl;
        //foreach child drawing
        for (auto &e : *container_)
        {
            e->Drawing();
        }
        std::cout << "\n=====END COMPLEX Shape: " << shapeName_ << "======" << std::endl;
    }
};

#endif // !__NILYANG_COMPLEXSHAPEFACTORY__