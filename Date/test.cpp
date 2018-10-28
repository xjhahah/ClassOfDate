#include "Date.h"

void TestDate()
{
	Date d1(2018, 10, 28);
	cout << d1 << endl;
	cout << d1+100 << endl;
	cout << d1.operator+=(10)<< endl;
	cout << d1 + (-100) << endl;
	Date d2(1998, 2, 11);
	cout << d1++ << endl;
	cout << ++d1 << endl;
	cout << d1 - d2 << endl;
}
int main()
{
	TestDate();
	return 0;
}