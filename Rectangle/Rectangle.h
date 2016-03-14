#pragma once
#ifndef __NILYANG_RECTANGLE
#define __NILYANG_RECTANGLE

class Shape
{
public:
	Shape(int num=0):no(num)
	{
		std::cout << "Shape constructor\n";
	}
	//虚析构，子类
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
	{}
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
	Rectangle(int _width, int _height, int x, int y)
		:Shape(),width(_width),height(_height),leftUp{new Point(x,y)}
	{}
	Rectangle(const Rectangle& other);//拷贝构造
	Rectangle& operator=(const Rectangle& other);//构造赋值
	~Rectangle();//析构

	
};

//建议，如果两边指针都指着对象的话，直接赋值就可以，不需先删，提高性能

inline Rectangle::Rectangle(const Rectangle & other)
{
	//TODO
}

inline Rectangle & Rectangle::operator=(const Rectangle & other)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

inline Rectangle::~Rectangle()
{
	delete leftUp;
}

#endif // !__NILYANG_RECTANGLE
