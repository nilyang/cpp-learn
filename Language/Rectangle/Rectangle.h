#pragma once
#ifndef __NILYANG_RECTANGLE
#define __NILYANG_RECTANGLE

#include<iostream>

//ǰ������
class Shape;
class Point;
class Rectangle;

//���<<����
inline std::ostream& operator << (std::ostream& os,const Rectangle& rct);

inline std::ostream& operator << (std::ostream& os, const Point& p);
class Shape
{
public:
	Shape(int num=0):no(num)
	{
		std::cout << "Shape default constructor\n";
	}
	//������
	virtual ~Shape()
	{
		std::cout << "Shape constructor\n";
	}
private:
	int no;
};

//Pointû��ָ���Ա�����追������͹��츳ֵ����������Ҳ����Ҫ
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
	int width; //��
	int height;//��
	Point* leftUp;//���ϽǶ���λ��
public:
	Rectangle(int _width=0, int _height=0, int x=0, int y=0)
		:Shape(),width(_width>0?_width:0)
		,height(_height>0?_height:0)
		,leftUp{new Point(x>0?x:0,y>0?y:0)}
	{
		std::cout << "Rectangle default constructor\n";
	}
	Rectangle(const Rectangle& other);//��������
	Rectangle& operator=(const Rectangle& other);//���츳ֵ

	int getWidth() const { return width; }
	int getHeight() const { return height; }
	Point& getPoint() const { return *leftUp; }

	~Rectangle();//����
};

//�������죬���ȵ��û���Ĺ��캯�������ڶ���
inline 
Rectangle::Rectangle(const Rectangle & other):Shape(other)
{
	std::cout << "Rectangle copy constructor\n"; 
	if (this != &other) {
		height = other.height;
		width = other.width;
		if (other.leftUp) {
			leftUp = new Point(*other.leftUp);//Ĭ�Ͽ�������
		}
		else {
			leftUp = nullptr;
		}
	}
}

//��������
inline Rectangle & 
Rectangle::operator=(const Rectangle & other)
{
	std::cout << "Rectangle asignment constructor\n";
	
	if (this == &other) {
		return *this;
	}

	this->height = other.height;
	this->width = other.width;

	if (other.leftUp) {
		this->leftUp = new Point(*other.leftUp);//Ĭ�Ͽ�������
	}
	else {
		this->leftUp = nullptr;
	}

	return *this;
}

//�������������ȵ���Rectangle�������������ٵ��û��������~Shape()
inline 
Rectangle::~Rectangle()
{
	std::cout << "Rectangle destructor\n";
	
	delete leftUp;
}


#endif // !__NILYANG_RECTANGLE