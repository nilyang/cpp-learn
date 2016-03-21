#include<iostream>
#include "Circle.h"
#include <random>
#include <ctime>


Shape * createElement(int n,Shape *pShape)
{
	return pShape;
}

void Test_Circle()
{
	srand((unsigned)time(nullptr));
	const int n = 20;
	Shape *pShape[n];
	for (int i = 0; i < n; i++)
	{
		if (i < 10) {
			Rectangle rct(i,rand());
		}
		else {

		}
	}

	delete pShape;
}

int main(int argc, char** argv) {


	system("pause");

	return 0;
}

