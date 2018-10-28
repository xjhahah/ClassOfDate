#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year, int month, int day )
		:_year(year)
		,_month(month)
		,_day(day)
	{
		if (year >= 0 && (month > 0 && month < 13) && (day > 0 && day < GetMonthDay(year, month)))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "The Date Is Invalid" << endl;
		}
	}
	inline bool operator>(const Date& d)const;
	inline bool operator<(const Date& d)const;
	inline bool operator<=(const Date& d)const;
	inline bool operator>=(const Date& d)const;
	inline bool operator==(const Date& d)const;
	inline bool operator!=(const Date& d)const;

	 Date operator+(int day);
	 Date& operator+=(int day);
	 Date operator-(int day);
	 Date& operator-=(int day);

	 Date& operator++(); // ++d => d.operator++(&d)
	 Date operator++(int); // d++ => d.operator(&d, 0);
	 Date& operator--(); // --d 
	 Date operator--(int); // d--

	 int operator-(const Date& d);
	 
	 friend ostream& operator<<(ostream& _cout, const Date& d);

private:
	//考虑是不是闰年，2月份天数为29天
	int GetMonthDay(int year, int month)
	{
		int DayOfMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((0 == year % 4 && 0 != year % 100) || (0 == year % 400)))
		{
			return DayOfMonth[month] += 1;
		}
		return DayOfMonth[month];
	}
	int _year;
	int _month;
	int _day;
};
