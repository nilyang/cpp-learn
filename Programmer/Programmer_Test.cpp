#include<iostream>
#include<set>
#include<algorithm>

#include"Programer.h"

void Test_Programer()
{
    //1.��ʼ��set����Id�������set
    std::cout << "\n1.init Programmer's ordered set;\n";
    std::set<Programmer, ProgrammerIdGreater<Programmer>> ProgSet;

    ProgSet.insert(Programmer(5, L"Stanley B.Lippman"));
    ProgSet.insert(Programmer(1, L"Scott Meyers"));
    ProgSet.insert(Programmer(2, L"Martin Fowler"));
    ProgSet.insert(Programmer(6, L"Andrei Alexandrescu"));
    ProgSet.insert(Programmer(3, L"Bill Gates"));
    ProgSet.insert(Programmer(4, L"P.J.Plaught"));
    
    std::cout << "Init successfully;\n";

    //2.for_each ��ӡ
    std::cout << "\n2.std::for_each print the set;\n";
    PrintProgrammer PrintObj;
    std::for_each(ProgSet.cbegin(), ProgSet.cend(), PrintObj);

    //3.��set�в���IdΪ3,NameΪ"Bill Gates"�Ķ���
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

    //4.�ҵ�2�еĶ����޸Ķ������֣���ͨ��for_each��ӡset���鿴�Ƿ��޸ĳɹ��ˡ�
    std::wstring newName = L"David Vandevoorde";

    std::wcout << L"\n4.Rename to 'David Vandevoorde' "
        << L"result: "
        << retObj.setName(L"David Vandevoorde");

    std::cout << "\n4.1 Use std::for_each print set elements:\n\n";

    std::for_each(ProgSet.cbegin(), ProgSet.cend(), PrintObj);

    std::cout << "\nThere is nothing changed at all!\n";

    //4.2. ʹ������һ�ַ�ʽ���޸����ԣ�д���Ҳ��޸�setԪ�صķº���������

    std::wcout << L"\n4.2 Find and rename to 'David Vandevoorde' in set:\n";
    FindAndModifyProgrammer findAndModifyObj(objOrigin, newName);
    auto result2 = std::find_if(ProgSet.cbegin(), ProgSet.cend(), findAndModifyObj);
    if (result2 != ProgSet.cend())
    {
        std::wcout << L"\n4.3 found --> " << static_cast<Programmer>(*result2);
    }

    std::for_each(ProgSet.cbegin(), ProgSet.cend(), PrintObj);

    std::cout << "\nAgain!!There is nothing changed at all toooooo!\n";

    //5.���¶���һ����set�����Ұ�Name��������
    std::wcout << L"\n5.make a new set set2\n";

    std::cout << "\n5.1.make set2 ordered by Name ASC;\n";
    std::set<Programmer, ProgrammerNameComparer<Programmer>> set2;

    for (auto elem : ProgSet)
    {
        set2.insert(elem);
    }
    std::cout << "Make and init set2 successfully!\n";

    //6.��ӡset2��Ԫ�أ������Ƿ�������������
    std::cout << "\n6.std::for_each print set2's elements\n";

    std::for_each(set2.cbegin(), set2.cend(), PrintObj);
    //yes it is
    std::cout << "the elements sorted by name successfully!";
    std::cout << "\n===THE END===\n\n";

}

int main()
{
    Test_Programer();

    system("pause");
    return 0;
}