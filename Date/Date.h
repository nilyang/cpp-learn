#pragma once
#ifndef __NILYANG_DATE__
#define __NILYANG_DATE__

#include <iostream>
#include <ctime>
#include <array>


using namespace std;

const int DateCounts = 10;
class Date;

array<Date, DateCounts> CreatePoints(const bool strict);
array<Date, DateCounts>& Sort(const array<Date, DateCounts>&);

int getYearMonthDays(const int year, const int month, const bool strict);

ostream & __doDatePrint(ostream&, const Date &);

class Date
{
public:
	Date(int y = 1970, int m = 1, int d = 1)
		:year_(y), month_(m), day_(d)
	{}
	bool operator > (const Date d);
	bool operator < (const Date d);
	bool operator == (const Date d);
	bool operator >= (const Date d);
	void print() {
		cout << year_ << '-' << month_ << '-' << day_ << "\n";
	}

	int year() const { return year_; }
	int month() const { return month_; }
	int day() const { return day_; }

private:
	int year_;
	int month_;
	int day_;

	friend ostream& __doDatePrint(ostream&, const Date &);
};

inline bool
Date::operator>(const Date d)
{
	return this->year_ > d.year_
		|| (this->year_ == d.year_ && this->month_ > d.month_)
		|| (this->year_ == d.year_ && this->month_ == d.month_ && this->day_ > d.day_);
}

inline bool
Date::operator<(const Date d)
{
	return this->year_ < d.year_
		|| (this->year_ == d.year_ && this->month_ < d.month_)
		|| (this->year_ == d.year_ && this->month_ == d.month_ && this->day_ < d.day_);
}

inline bool
Date::operator==(const Date d)
{
	return this->year_ == d.year_ && this->month_ == d.month_ && this->day_ == d.day_;
}

inline bool
Date::operator>=(const Date d)
{
	return *this > d || *this == d;
}


inline ostream&
__doDatePrint(ostream& os, const Date& d)
{       
	//两种方式都行，此处主要是用到friend特性
	return os << d.year_ << '-' << d.month_ << '-' << d.day_ << "\n" ;
	//return os << d.year() << '-' << d.month() << '-' << d.day();
}

inline ostream&
operator << (ostream& os, const Date & d)
{
	return __doDatePrint(os, d);
}


#include <random>

inline int 
getYearMonthDays(const int year,const int month,const bool strict)
{
	int dayLen{ 30 },day;
	if (strict) {
		bool is_leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
		if (month == 2) {
			dayLen = (is_leap ? 29 : 28);
		}
		else if (month <8 && month % 2 == 1 
				|| month > 7 && month % 2 == 0) {
			dayLen = 31;
		}
		else {
			dayLen = 30;
		}
	}

	do {
		day = rand() % dayLen;
	} while (day == 0);

	return day;
}

//strict 是否开启严格时间模式 
//校验日期是否规范，并自动纠正，闰平年计算，大小月计算
//true: 校验生成的年月日是否符合规范
//false: 不校验
inline array<Date, DateCounts> 
CreatePoints(const bool strict)
{
	//随机数种子
	srand((unsigned)time(nullptr));
	array<Date, DateCounts> dates;
	for (int i = 0; i < DateCounts; i++) {
		int year, month, day;
		year = 2016 -(rand() % DateCounts);
		month = rand() % 11+1;
		day = getYearMonthDays(year, month, strict);
		dates[i] = Date(year,month,day);
	}

	return dates;
}

//冒泡排序
inline array<Date, DateCounts> &
Sort(array<Date, DateCounts> & arrDates)
{
	Date tmp;
	for (int i = 0; i < DateCounts; i++) {
		for (int j = 0, len = DateCounts - 1 - i; j < len; j++) {
			if (arrDates[j] > arrDates[j + 1]) {
				tmp = arrDates[j];
				arrDates[j] = arrDates[j+1];
				arrDates[j + 1] = tmp;
			}
		}
	}
	return arrDates;
}

#endif // !__NILYANG_DATE__
