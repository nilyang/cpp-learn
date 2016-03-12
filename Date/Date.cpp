#include <iostream>
#include "Date.h"

using namespace std;

//两种方式打印，两种方式遍历
void print_dates(const array<Date, DateCounts>* arrDates, bool use_overload,bool use_for_iter=false)
{
	if (use_for_iter) {
		for (Date d : *arrDates) {
			if (use_overload)
				cout << d;//重载<<输出
			else
				d.print();//print输出
		}
	}
	else {
		for (int i = 0; i < DateCounts; i++) {
			if (use_overload)
				(*arrDates)[i].print(); //print输出
			else
				cout << (*arrDates)[i]; //重载<<输出
		}
	}
	
}

int main(int argc, char** argv) {
	


	auto arrDates = new array<Date, DateCounts> ;


	cout << "\n--------[非严格模式]生成Date数组------------\n";
	CreatePoints(arrDates,false);

	print_dates(arrDates,false);//Date::print()

	cout << "\n--------[非严格模式]对Date数组排序------------\n";
	Sort(arrDates,1);//std sort
	print_dates(arrDates, false);//Date::print()

	
	cout << "\n--------[严格模式]生成Date数组------------\n";
	CreatePoints(arrDates, true);//严格模式（校验日期和闰年）
	
	print_dates(arrDates, true);//重载<<输出
	cout << "\n--------[严格模式]对Date数组排序------------\n";
	
	Sort(arrDates, 2);//冒泡
	print_dates(arrDates, true, true);//重载<<输出

	//释放内存
	delete[]arrDates;

	system("pause");

	return 0;
}

