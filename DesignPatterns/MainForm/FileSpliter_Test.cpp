#include<iostream>
#include"MainForm.h"

void Test_FileSpliter()
{
    MainForm * MyForm = new MainForm();
    //µã»÷²Ù×÷
    MyForm->Button1_Click();
    delete MyForm;
}

int main()
{

    Test_FileSpliter();
    
    getchar();
    return 0;
}
