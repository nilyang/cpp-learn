#include<iostream>
#include"Calculator.h"

void Test_Calculator()
{
    
    std::cout << "int limit: " << Calculator<int>().GetLimit() << std::endl;
    std::cout << "long limit: " << Calculator<long>().GetLimit() << std::endl;
    std::cout << "float limit: " << Calculator<float>().GetLimit() << std::endl;
    std::cout << "double limit: " << Calculator<double>().GetLimit() << std::endl;
}

int main()
{
    Test_Calculator();

    system("pause");

    return 0;
}