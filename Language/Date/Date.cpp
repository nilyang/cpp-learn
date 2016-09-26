#include <iostream>
#include "Date.h"

using namespace std;

//���ַ�ʽ��ӡ�����ַ�ʽ����
void print_dates(const array<Date, DateCounts>* arrDates, bool use_overload,bool use_for_iter=false)
{
	if (use_for_iter) {
		for (Date d : *arrDates) {
			if (use_overload)
				cout << d;//����<<���
			else
				d.print();//print���
		}
	}
	else {
		for (int i = 0; i < DateCounts; i++) {
			if (use_overload)
				(*arrDates)[i].print(); //print���
			else
				cout << (*arrDates)[i]; //����<<���
		}
	}
	
}

int main(int argc, char** argv) {
	


	auto arrDates = new array<Date, DateCounts> ;


	cout << "\n--------[���ϸ�ģʽ]����Date����------------\n";
	CreatePoints(arrDates,false);

	print_dates(arrDates,false);//Date::print()

	cout << "\n--------[���ϸ�ģʽ]��Date��������------------\n";
	Sort(arrDates,1);//std sort
	print_dates(arrDates, false);//Date::print()

	
	cout << "\n--------[�ϸ�ģʽ]����Date����------------\n";
	CreatePoints(arrDates, true);//�ϸ�ģʽ��У�����ں����꣩
	
	print_dates(arrDates, true);//����<<���
	cout << "\n--------[�ϸ�ģʽ]��Date��������------------\n";
	
	Sort(arrDates, 2);//ð��
	print_dates(arrDates, true, true);//����<<���

	//�ͷ��ڴ�
	delete[]arrDates;

	system("pause");

	return 0;
}
