#include <iostream>
#include "Rectangle.h"

inline std::ostream&
operator<<(std::ostream &os, const Rectangle& rct)
{
	return std::cout << "with:" << rct.getWidth() << ", height:" << rct.getHeight() 
					 << ", Point:("<< rct.getPoint().getX() << "," 
					 << rct.getPoint().getY() << ")\n";
}
void Test_Rectangle()
{
	Rectangle r1;
	Rectangle r2(r1);
	//构造，拷贝构造
	std::cout << "r1 : "<<r1 << "\nr2: " << r2;
	
	//构造赋值
	Rectangle r3(400, 300, 500, 300);
	r1 = r3;
	std::cout << "r1:" << r1 << "\nr3: " << r3;
	
	//堆内存分配，拷贝构造
	Rectangle *pr4 = new Rectangle(r3);
	std::cout << "pr4: " << pr4 << "\nr4: " << *pr4;
	
	delete pr4;
	std::cout << "destructed pr4:" << pr4 << "\n";
}

int main(int argc, char** argv) {

	Test_Rectangle();

	system("pause");

	return 0;
}
