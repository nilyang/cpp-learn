#pragma once
#ifndef __NILYANG_CIRCLE
#define __NILYANG_CIRCLE

#include <iostream>

//前置声明
class Shape;
class Point;
class Rectangle;
class Circle;
struct ShapeStack;

//输出<<重载
//inline std::ostream& operator << (std::ostream& os, const Point& p);
//inline std::ostream& operator << (std::ostream& os, const Rectangle& rct);
//inline std::ostream& operator << (std::ostream& os, const Circle& c);
//
//inline std::ostream &
//operator<<(std::ostream & os, const Rectangle& rct)
//{
//    return std::cout << "Rectangle: With=" << rct.getWidth()
//        << ", height=" << rct.getHeight()
//        << "," << rct.getPoint()
//        << "\n";
//}
//
//inline std::ostream &
//operator<<(std::ostream & os, const Point & p)
//{
//    return std::cout << "Point:(" << p.getX() << "," << p.getY() << ")" << "\n";
//}
//
//inline std::ostream &
//operator << (std::ostream & os, const Circle & c)
//{
//    return std::cout << "Circle: R=" << c.getRadius()
//        << ", Center=" << c.getCenter()
//        << ", Area=" << c.getArea()
//        << "\n";
//}

//多态
//inline std::ostream& operator << (std::ostream& os, const Shape& base);


//友元测试多态
inline void __print_shape(const Shape * ths);

class Shape
{
    int no;
    int type;
public:
    Shape(int _num = 0, const int _type = 0)
        :no(_num),type(_type) 
    {}
    int getNum() const { return no; }
    int getType() const { return type; }
    virtual int getArea() const = 0;
    virtual Shape *clone() const = 0;
    virtual ~Shape() {}

    void print() const
    {
        __print_shape(this);
    }
    //多态
    friend void __print_shape(const Shape *ths);

};

class Point
{
    int x;
    int y;
public:
    Point(int _x = 0, int _y = 0)
        :x(_x), y(_y)
    {}
    ~Point(){}
    
    int getX() const { return x; }
    int getY() const { return y; }
};

class Rectangle : public Shape
{
    int width;
    int height;
    Point leftUp;
public:
    ~Rectangle() {}
    Rectangle(int no = 0, int w = 0, int h = 0, int x = 0, int y = 0)
        :Shape(no,0), width(w), height(h),leftUp(x,y)
    {}
    Rectangle(const Rectangle& other):Shape(other)
    {
        if (this != &other) {
            this->width = other.width;
            this->height = other.height;
            this->leftUp = other.leftUp;
        }
    }
    Rectangle& operator=(const Rectangle& other)
    {
        if (this == &other) {
            return *this;
        }
        Shape::operator=(other);
        this->width = other.width;
        this->height = other.height;
        this->leftUp = other.leftUp;
    }
    virtual int getArea() const
    {
        return width * height;
    }

    virtual Rectangle* clone() const 
    {
        return new Rectangle(*this);
    }
};
class Circle : public Shape
{
    Point center;
    int radius;
public:
    ~Circle(){}
    Circle(int no = 0, int r = 0, int x = 0, int y = 0)
        :Shape(no,1),center(x, y), radius(r)
    {}

    double getAreaCircle(double pi = 3.14159)  const
    {
        return pi * radius * radius;
    }

    virtual int getArea() const
    {
        return (int)getAreaCircle();
    }

    virtual Circle* clone() const
    {
        return new Circle(*this);
    }

};


inline void __print_shape(const Shape *ths)
{
    const char * s[2] = { "Rectangle", "Circle" };

    std::cout << s[ths->getType()]
              << " : NO=" << ths->getNum()
              << ", Area=" << ths->getArea() << "\n";
}



#endif