#include<iostream>
#include<iomanip>
#include"Calculator.h"

using namespace NILYANG;

void Test_Calculator()
{
    //整型
    std::cout << "1. 整型输出\n";
    std::cout << "int limit: " << Calculator<int>().GetLimit() << std::endl;
    std::cout << "long limit: " << Calculator<long>().GetLimit() << std::endl;
    std::cout << "\n";

    //浮点型控制输出精度
    std::cout << "2. 浮点数固定精度输出\n"<< std::fixed ;

    Calculator<float> CalFloat;
    Calculator<double> CalDouble;

    std::cout << "float limit: " << std::setprecision(CalFloat.getPrecision()) 
                                 << CalFloat.GetLimit() << std::endl;
    std::cout << "double limit: " <<  std::setprecision(CalDouble.getPrecision())
                                  << CalDouble.GetLimit() << std::endl;
    std::cout << "\n";

    //指定精度输出
    std::cout << "3. 浮点数默认精度输出\n"<< std::defaultfloat ;

    CalFloat.setPrecision(3);
    CalDouble.setPrecision(8);

    std::cout << "float limit: " << std::setprecision(CalFloat.getPrecision())
        << CalFloat.GetLimit() << std::endl;
    std::cout << "double limit: " << std::setprecision(CalDouble.getPrecision())
        << CalDouble.GetLimit() << std::endl;

    std::cout << "\n";
}

int main()
{
    Test_Calculator();

    system("pause");

    return 0;
}