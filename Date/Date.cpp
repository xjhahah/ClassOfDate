#include "Date.h"

//新判断年份是否相等，若相等则判断月份是否相等，若相等则判断天数就能够得出结论
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
//实现上面两种方法之后我们就可以用上面两种方法实现代码复用，以减少代码的长度。
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
	 
	
	//我们可以看到在重载 += 运算符时和重载这个 + 运算符时代码很相似，这是我们可以考虑代码复用，以减少差错
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
//和重载+同理    
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
	//这里给出一个暴力求解法，也是最简单的求解方法
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
