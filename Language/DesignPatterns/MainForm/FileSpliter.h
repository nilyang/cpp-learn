#pragma once
#ifndef __NILYANG_WEEKONE__

#include<string>
#include<algorithm>
#include<chrono>
#include<thread>

#include"ISubject.h"

    
class FileSpliter:public ISubject
{
    std::string filePath;
    int fileNumber;
public:
    virtual ~FileSpliter() = default;
    FileSpliter(const std::string &path, const int num)
    :filePath(path),fileNumber(num)
    {
    }

    void DoSplit()
    {
        //Ĭ�Ϸָ��㷨����
        for (int i = 0; i < fileNumber; i++) {
            Process();
            Notify();
        }
    }

    virtual void Split() = 0;

    //�ָ������
    void Process(int sec = 1000)
    {
        //��������(ģ�⴦�����̺�ʱ)
        Split();
        std::this_thread::sleep_for(std::chrono::milliseconds(sec));//sleep 1s
    }

    int GetFileNumber() const
    {
        return fileNumber;
    }

    const std::string & GetFilePath() const
    {
        return filePath;
    }

};

//�㷨A
class SplitorA:public FileSpliter
{
public:
    SplitorA(const std::string &path, const int num)
        :FileSpliter(path, num)
    {
        std::cout << "Splitor A \n";
    }
    virtual void Split()
    {
        std::cout << "A";
        
    }
};

//�㷨B
class SplitorB :public FileSpliter
{
public:
    SplitorB(const std::string &path, const int num)
        :FileSpliter(path, num)
    {
        std::cout << "Splitor B \n";
    }

    virtual void Split()
    {
        std::cout << "B";
        
    }
};

//�㷨C
class SplitorC :public FileSpliter
{
public:
    SplitorC(const std::string &path, const int num)
        :FileSpliter(path, num)
    {
        std::cout << "Splitor C \n";
    }

    virtual void Split()
    {
        std::cout << "C";
    }
};

#endif // !__NILYANG_WEEKONE__