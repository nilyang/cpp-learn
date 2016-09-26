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
        if (i < half) {
            int width = rand() % 9 + 1;
            int height = rand() % 9 + 1;
            pShape[i] = new Rectangle(i, width, height, x, y);
        }
        else {
            int r = rand() % 9 + 1;
            pShape[i] = new Circle(i, r, x, y);
        }
        pShape[i]->print();
    }

    //delete element which area less than 50
   
    int m = n;

    for (int i = 0, j = 0; i < n; i++)
    {
        if (!pShape[i]) {
            continue;
        }

        if (pShape[i]->getArea() < 50) {
            delete pShape[i];
            pShape[i] = nullptr;
            --m;
        }
    }
     
    std::cout << "n=" << n << ", m=" << m << "\n";

    Shape **newShape = new Shape*[m];

    for (int i = 0, j = 0; i < n; i++, j++) {
        if (pShape[i] && j < m) {
            newShape[j] = pShape[i]->clone();
        }
    }

    //for (int i = 0; i < m; i++) {
    //    if (newShape && newShape[i]) {
    //        newShape[i]->print();//无法通过编译……，不知为什么，求解答
    //    }
    //}

    for (int i = 0; i < n; i++)
    {
        if (pShape[i] != nullptr) {
            delete pShape[i];
            pShape[i] = nullptr;
        }
    }

    //for (int i = 0; i < m; i++)
    //{
    //    if (newShape[i] != nullptr) {
    //        delete newShape[i];
    //    }
    //}


    delete[] newShape;
    newShape = nullptr;
}

int main(int argc, char** argv) {

    Test_Circle();
    int m = 30;
    //Shape **a = new Shape*[m];
    //Shape **a = {};

    system("pause");

    return 0;
}
