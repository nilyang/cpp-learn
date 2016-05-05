#pragma once
#ifndef __NILYANG_MAINFORM__
#include<algorithm>

#include "Form.h"
#include "TextBox.h"

#include "ProgressBar.h" //Observer
#include "FileSpliter.h" //Subject

class MainForm : public Form
{
    TextBox* txtFilePath;
    TextBox* txtFileNumber;
public:
    ~MainForm();

    void Button1_Click()
    {
        CaptureInput();
        Splitor();
    }

    //ģ���û�����
    void CaptureInput();

    //���÷ָ����ָ��ļ�
    void Splitor();

};

inline MainForm::~MainForm()
{
    if (txtFilePath != nullptr) {
        delete txtFilePath;
        txtFilePath = nullptr;
    }

    if (txtFileNumber != nullptr) {
        delete txtFileNumber;
        txtFileNumber = nullptr;
    }
}


inline void MainForm::CaptureInput()
{
    if (txtFilePath != nullptr) {
        delete txtFilePath;
    }
    if (txtFileNumber != nullptr) {
        delete txtFileNumber;
    }
    txtFilePath = new TextBox("file.log");
    txtFileNumber = new TextBox("10");
}

inline void MainForm::Splitor()
{
    FileSpliter *spliter = new SplitorA(txtFilePath->GetValue(), txtFileNumber->GetNumber());
    spliter->Aattach(new ProgressBar());
    spliter->DoSplit();
    delete spliter;
}



#endif // !__NILYANG_MAINFORM__