#include<iostream>
#include<string>
#include<vector>
#include"Vector.h"

using std::string;
using std::vector;

void Vector_Test()
{
    vector<int> v1 { 0, 0, 30, 20, 0, 0, 0, 0, 10, 0 };
    int equal_to{ 0 }, n{ 2 };
    std::cout << v1.size() << "\n";
    vector<int> v2;
    v2 = my_not_equal_to(v1, equal_to);
    std::cout << "\n====v2====\n";
    for (vector<int>::iterator it = v2.begin(); it < v2.end();it++)
    {
        std::cout << *it<< "\n";
    }
}

int main()
{
    Vector_Test();
    system("pause");
    return 0;
}