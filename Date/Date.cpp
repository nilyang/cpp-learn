#include <iostream>
#include "Date.h"

using namespace std;

//疑问：这里不需要改变内容，但是const又不能加，该怎么办？
void print_dates(array<Date, DateCounts>& arrDates, bool use_overload)
{
	for (int i = 0; i < DateCounts; i++) {
		if (use_overload)
			cout << arrDates[i] ; //重载<<输出
		else
			arrDates[i].print(); //print输出
	}
}

int main(int argc, char** argv) {
	


	array<Date, DateCounts> arrDates;


	cout << "\n--------[非严格模式]生成Date数组------------\n";
	arrDates = CreatePoints(false);

	print_dates(arrDates,false);//Date::print()

	cout << "\n--------[非严格模式]对Date数组排序------------\n";
	arrDates = Sort(arrDates);
	print_dates(arrDates, false);//Date::print()


	cout << "\n--------[严格模式]生成Date数组------------\n";
	arrDates = CreatePoints(true);
	
	print_dates(arrDates, true);//重载<<输出
	cout << "\n--------[严格模式]对Date数组排序------------\n";
	
	arrDates = Sort(arrDates);
	print_dates(arrDates, true);//重载<<输出




	system("pause");

	return 0;
}

