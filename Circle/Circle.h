#pragma once
#ifndef __NILYANG_CIRCLE
#define __NILYANG_CIRCLE

#include <iostream>

//前置声明
class Shape;
class Point;
class Rectangle;
class Circle;

//输出<<重载
inline std::ostream& operator << (std::ostream& os, const Point& p);
inline std::ostream& operator << (std::ostream& os, const Rectangle& rct);
inline std::ostream& operator << (std::ostream& os, const Circle& c);

class Shape
{
	int no;
public:
	Shape(int num=0):no(num) {}
	virtual int getArea() = 0;
	virtual ~Shape(){}
};

class Point
{
	int x;
	int y;
public:
	Point(int _x, int _y)
		:x(_x), y(_y)
	{
		std::cout << "Point default constructor\n";
	}
	~Point()
	{
		std::cout << "Point destructor\n";
	}

	int getX() const { return x; }
	int getY() const { return y; }
	
};

class Rectangle : public Shape
{
	int width;
	int height;
	Point leftUp;
public:
	Rectangle(int no=0,int w=0,int h=0,int x=0,int y=0)
		:Shape(no),leftUp(x,y),width(w),height(h)
	{}
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	const Point& getPoint() const { return leftUp; }
	virtual int getArea() const
	{
		return width * height;
	}
};
class Circle : public Shape
{
	Point center;
	int radius;
public:
	Circle(int no=0,int r=0, int x=0, int y=0)
		:Shape(no), center(Point(x,y)), radius(r)
	{}
	int getRadius() const { return radius; }
	const Point& getCenter() const { return center; }

	double getArea(double pi=3.14159) const 
	{
		return pi * radius * radius;
	}

	virtual int getArea() const 
	{
		return ;
	}
};



inline std::ostream &
operator<<(std::ostream & os, const Rectangle& rct)
{
	return std::cout << "with:" << rct.getWidth() << ", height:" << rct.getHeight()
		<< "," << rct.getPoint() << "\n";
}

inline std::ostream &
operator<<(std::ostream & os, const Point & p)
{
	return std::cout << "Point:(" << p.getX() << "," << p.getY() << ")";
}

inline std::ostream &
operator << (std::ostream & os, const Circle & c)
{
	return std::cout << "radius:" << c.getRadius() 
					 << ", center:" << c.getCenter() 
					 << ",Area:"<< c.getArea();
}

#endif
