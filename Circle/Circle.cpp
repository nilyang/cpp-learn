#include<iostream>
#include "Circle.h"
#include <random>
#include <ctime>

void Test_Circle()
{
	srand((unsigned)time(nullptr));

	const int n = 20;

  int half = int(n / 2);

	Shape *pShape[n];

	for (int i = 0; i < n; i++)
	{
		int x = rand() % 10;
		int y = rand() % 10;
		if (i < half ) {
			int width = rand() % 9 + 1;
			int height = rand() % 9 + 1;
			pShape[i] = new Rectangle(i, width, height, x, y);
 		}
		else {
			int r = rand() % 9 + 1;
			pShape[i] = new Circle(i, r, x, y);
		}
		std::cout << *pShape[i] ;
	}

  //delete element which area less than 50
	Shape *newShape[];
	for (int i = 0; i < n; i++ )
	{
		if (pShape[i] != nullptr) {
			delete pShape[i];
		}
	}

}

int main(int argc, char** argv) {

	Test_Circle();

	system("pause");

	return 0;
}
