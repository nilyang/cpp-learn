#pragma once
#ifndef __NILYANG_WEEKONE__
#include<string>
class Form
{
    //base class
};

class TextBox
{
    std::string text;
public:
    const std::string& GetText() const
    {
        return text;
    }

    void SetText(const std::string & txt)
    {
        text = txt;
    }
};

class ProgressBar
{
    //
    int progress;
public:
    void IncrProgress(int prg)
    {
        progress += prg;
    }

    int GetProgress() const
    {
        return progress;
    }

    void Update()
    {

    }
};

class MainForm : public Form
{
    TextBox* txtFilePath;
    TextBox* txtFileNumber;
    ProgressBar* progressBar;
public:
    void Button1_Click()
    {
        //TODO 收集文件路径
    }
};

class FileSpliter
{
    std::string filePath;
    int fileNumber;
public:
    void Split()
    {
        //分割算法策略
    }
};

#endif // !__NILYANG_WEEKONE__