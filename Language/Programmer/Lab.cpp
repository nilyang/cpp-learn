#include<iostream>
#include<set>
#include<string>
#include<algorithm>

#include"Programer.h"
#include"Lab.h"

//随便来个比较
void Test_Compare()
{
    int result = compare("aaa", "abc");
    if (result == 0) {
        std::cout << "相等\n";
    }
    else if (result > 0) {
        std::cout << "aaa > abc\n";
    }
    else {
        std::cout << "aaa < abc\n";
    }
}

void Test_Programer()
{
    //1.初始化set，按Id倒叙插入set
    std::cout << "\n1.init Programmer's ordered set;\n";
    std::set<Programmer, ProgrammerIdGreater<Programmer>> ProgSet;

    ProgSet.insert(Programmer(5, L"Stanley B.Lippman"));
    ProgSet.insert(Programmer(1, L"Scott Meyers"));
    ProgSet.insert(Programmer(2, L"Martin Fowler"));
    ProgSet.insert(Programmer(6, L"Andrei Alexandrescu"));
    ProgSet.insert(Programmer(3, L"Bill Gates"));
    ProgSet.insert(Programmer(4, L"P.J.Plaught"));
    std::cout << "Init successfully;\n";
    //2.for_each 打印
    std::cout << "\n2.std::for_each print the set;\n";
    PrintProgrammer PrintObj;
    std::for_each(ProgSet.cbegin(), ProgSet.cend(), PrintObj);

    //3.在set中查找Id为3,Name为"Bill Gates"的对象
    std::cout << "\n3.find the object which Id=3 and Name=\"Bill Gates\"\n";
    Programmer objOrigin(3, L"Bill Gates");
    FindProgramer FindObj(objOrigin);
    auto result = std::find_if(ProgSet.cbegin(), ProgSet.cend(), FindObj);
    Programmer retObj;
    if (result != ProgSet.cend()) {
        retObj = static_cast<Programmer>(*result);
        std::wcout << L"Yes Find it, " << retObj;
    }
    else {
        std::wcout << L"Not found!\n";
        return;
    }

    //4.找到2中的对象，修改对象名字，并通过for_each打印set，查看是否修改成功了。
    std::wstring newName = L"David Vandevoorde";

    std::wcout << L"\n4.Rename to 'David Vandevoorde' "
        << L"result: "
        << retObj.setName(L"David Vandevoorde");

    std::cout << "\n4.1 Use std::for_each print set elements:\n\n";

    std::for_each(ProgSet.cbegin(), ProgSet.cend(), PrintObj);

    std::cout << "\nThere is nothing changed at all!\n";

    //4.2. 使用另外一种方式来修改试试，写查找并修改set元素的仿函数来试试

    //std::wcout << L"\n4.2 Find and rename to 'David Vandevoorde' in set:\n";
    //FindAndModifyProgrammer findAndModifyObj(objOrigin, newName);
    //auto result2 = std::find_if(ProgSet.cbegin(), ProgSet.cend(), findAndModifyObj);
    //if (result2 != ProgSet.cend())
    //{
    //    std::wcout << L"\n4.3 found --> " << static_cast<Programmer>(*result2);
    //}

    //std::for_each(ProgSet.cbegin(), ProgSet.cend(), PrintObj);

    //std::cout << "\nAgain!!There is nothing changed at all too!\n";

    //5.重新定义一个新set
    std::wcout << L"\n5.make a new set set2\n";

    std::cout << "\n5.1.make set2;\n";
    std::set<Programmer, ProgrammerNameComparer<Programmer>> set2;
    std::for_each(set2.cbegin(), set2.cend(), PrintObj);

    std::cout << "\n\n";

}