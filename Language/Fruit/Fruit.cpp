#include <iostream>
#include "Fruit.h"

/*

Ϊ�������� Fruit��Apple ���� ���캯���� ���������� 
���ڹ��캯�������������д�ӡ����̨��Ϣ���۲칹������۵��ù��̡�
Ȼ��ΪApple������::operator new�� ::operator delete��
�ڿ���̨��ӡ��Ϣ�����۲���ý����

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