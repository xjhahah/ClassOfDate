#include "Date.h"

//���ж�����Ƿ���ȣ���������ж��·��Ƿ���ȣ���������ж��������ܹ��ó�����
inline bool Date::operator>(const Date& d)const
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if(_month==d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}
	return false;
}
inline bool Date::operator==(const Date& d)const
{
	if (_year == d._year && _month == d._month && _day == d._day)
	{
		return true;
	}
	return false;
}
//ʵ���������ַ���֮�����ǾͿ������������ַ���ʵ�ִ��븴�ã��Լ��ٴ���ĳ��ȡ�
inline bool Date::operator<(const Date& d)const
{
	return !(*this >= d);
}
inline bool Date::operator<=(const Date& d)const
{
	return !(*this > d);
}
inline bool Date::operator>=(const Date& d)const
{
	return (*this > d) || (*this == d);
}

inline bool Date::operator!=(const Date& d)const
{
	return !(*this == d);
}

//day + 100
Date Date::operator+(int day)
{
	/*if (day < 0)
	{
		return (*this + (-day));
	}
	Date ret(*this);
	ret._day += day;
	while(ret._day > GetMonthDay(ret._year, ret._month))
	{
		ret._month++;
		if (ret._month == 13)
		{
			ret._year++;
			ret._month = 1;
		}
		ret._day -= GetMonthDay(ret._year, ret._month);
	}*/
	 
	
	//���ǿ��Կ��������� += �����ʱ��������� + �����ʱ��������ƣ��������ǿ��Կ��Ǵ��븴�ã��Լ��ٲ��
	if (day < 0)
	{
		return *this - (-day);
	}
	Date ret(*this);
	ret += day;
	return ret;
	
}
Date& Date::operator+=(int day)
{	
	_day += day;
	int count = 0;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month ++;
		if (_month == 13)
		{
			_year+=1;
			_month = 1;
		}		
		count++;
	}
	return *this;
}
//������+ͬ��    
Date Date::operator-(int day)
{
	Date ret(*this);
	if (day < 0)
	{
		return *this -(-day);
	}	
	ret -= day;
	return ret;
}
Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0 )
	{
		_month -= 1;
		if (_month == 0)
		{
			_year-=1;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
// ++d => d.operator++(&d)
Date& Date::operator++() 
{
	*this += 1;
	return *this;
}
// d++ => d.operator(&d, 0);
Date Date::operator++(int)
{
	Date ret(*this);
	_day += 1;
	return ret;
}
// --d 
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
// d--
Date Date::operator--(int)
{
	Date ret(*this);
	_day -= 1;
	return ret;
}

int Date::operator-(const Date& d)
{
	//�������һ��������ⷨ��Ҳ����򵥵���ⷽ��
	int count = 0;
	Date minDate(*this);
	Date maxDate(d);
	if (minDate > maxDate)
	{
		minDate = d;
		maxDate = *this;
	}
	while (minDate != maxDate)
	{
		count++;
		++minDate;
	}
	return count;
}
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
