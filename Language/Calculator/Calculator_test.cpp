#include<iostream>
#include<iomanip>
#include"Calculator.h"

using namespace NILYANG;

void Test_Calculator()
{
    //����
    std::cout << "1. �������\n";
    std::cout << "int limit: " << Calculator<int>().GetLimit() << std::endl;
    std::cout << "long limit: " << Calculator<long>().GetLimit() << std::endl;
    std::cout << "\n";

    //�����Ϳ����������
    std::cout << "2. �������̶��������\n"<< std::fixed ;

    Calculator<float> CalFloat;
    Calculator<double> CalDouble;

    std::cout << "float limit: " << std::setprecision(CalFloat.getPrecision()) 
                                 << CalFloat.GetLimit() << std::endl;
    std::cout << "double limit: " <<  std::setprecision(CalDouble.getPrecision())
                                  << CalDouble.GetLimit() << std::endl;
    std::cout << "\n";

    //ָ���������
    std::cout << "3. ������Ĭ�Ͼ������\n"<< std::defaultfloat ;

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