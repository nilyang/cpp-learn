#include <iostream>
#include "Fruit.h"

/*

为上述类型 Fruit和Apple 添加 构造函数与 析构函数， 
并在构造函数与析构函数中打印控制台信息，观察构造和析枸调用过程。
然后为Apple类重载::operator new和 ::operator delete，
在控制台打印信息，并观察调用结果。

*/


void Test_Fruit()
{
    std::cout << "---call Test_Fruit():\n";
    std::cout << "pApple: \n";
    
    Apple *pApple = new Apple(1,22,'F',2,'A');
    
    pApple->process();

    std::cout << "delete pApple:\n";
    delete pApple;
    std::cout << "---exit Test_Fruit():\n";
}

int main()
{
    //Fruit *fruit = new Fruit;
    //delete fruit;

    Test_Fruit();

    system("pause");
    return 0;
}