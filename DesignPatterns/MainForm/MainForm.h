#pragma once
#ifndef __NILYANG_MAINFORM__
#include "ProgressBar.h"
#include "Form.h"
#include "TextBox.h"
#include "ISubject.h"

#include<algorithm>

class MainForm : public Form , public ISubject
{
    TextBox* txtFilePath;
    TextBox* txtFileNumber;
public:
    void Button1_Click()
    {
        //TODO 收集文件路径
        this->txtFilePath;//获取路径
        this->txtFileNumber;//获取number
        
        IObserver* progressBar = new ProgressBar();
        this->Aattach(progressBar);
        
    }

    void fileReader()
    {
        for (int i = 0, num = txtFileNumber->GetNumber();i<num; i++) {
            //file Read
            //...
            this->Splitor();
            this->Notify();
        }
    }

    void Splitor()
    {

    }
};

#endif // !__NILYANG_MAINFORM__