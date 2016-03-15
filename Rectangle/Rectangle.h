#pragma once
#ifndef __NILYANG_RECTANGLE
#define __NILYANG_RECTANGLE

#include<iostream>

//前置声明
class Shape;
class Point;
class Rectangle;

//输出<<重载
inline std::ostream& operator << (std::ostream& os,const Rectangle& rct);


class Shape
{
public:
	Shape(int num=0):no(num)
	{
		std::cout << "Shape default constructor\n";
	}
	//虚析构
	virtual ~Shape()
	{
		std::cout << "Shape constructor\n";
	}
private:
	int no;
};

//Point没有指针成员，无需拷贝构造和构造赋值函数，析构也不需要
class Point
{
public:
	Point(int _x, int _y)
		:x(_x),y(_y)
	{	
		std::cout << "Point default constructor\n";
	}
	~Point() 
	{
		std::cout << "Point destructor\n";
	}
	//Point(const Point& other);
	int getX() const { return x; }
	int getY() const { return y; }
private:
	int x;
	int y;
};

class Rectangle : public Shape
{
private:
	int width; //宽
	int height;//高
	Point* leftUp;//左上角顶点位置
public:
	Rectangle(int _width=0, int _height=0, int x=0, int y=0)
		:Shape(),width(_width>0?_width:0)
		,height(_height>0?_height:0)
		,leftUp{new Point(x>0?x:0,y>0?y:0)}
	{
		std::cout << "Rectangle default constructor\n";
	}
	Rectangle(const Rectangle& other);//拷贝构造
	Rectangle& operator=(const Rectangle& other);//构造赋值

	int getWidth() const { return width; }
	int getHeight() const { return height; }
	Point& getPoint() const { return *leftUp; }

	~Rectangle();//析构
};

//拷贝构造，会先调用基类的构造函数，由内而外
inline 
Rectangle::Rectangle(const Rectangle & other):Shape()
{
	std::cout << "Rectangle copy constructor\n"; 
	if (this != &other) {
		height = other.height;
		width = other.width;
		leftUp = new Point(*other.leftUp);//默认拷贝构造
	}
}

//拷贝构造
inline Rectangle & 
Rectangle::operator=(const Rectangle & other)
{
	std::cout << "Rectangle asignment constructor\n";
	
	if (this == &other) {
		return *this;
	}

	this->height = other.height;
	this->width = other.width;
	this->leftUp = new Point(*other.leftUp);

	return *this;
}

//析构函数，会先调用Rectangle本身的析构，再调用基类的析构~Shape()
inline 
Rectangle::~Rectangle()
{
	std::cout << "Rectangle destructor\n";
	
	delete leftUp;
}


#endif // !__NILYANG_RECTANGLE
