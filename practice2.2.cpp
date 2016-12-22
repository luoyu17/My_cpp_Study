/////////////////////////////////////////////////////////////////////////
//http://www.xuetangx.com/courses/course-v1:TsinghuaX+20740084X+sp/about
//practice 2.2
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
using namespace std;

typedef enum {SUN,MON,TUE,WED,THU,FRI,SAT} WEEKDAY;

int main()
{
	int date;
	const WEEKDAY date1 = SUN;
	WEEKDAY wday;

	cout<<"This programe will print a calender of 2017-1.\n";
	cout<<"2017-1\n";
	cout<<"---------------------\n";
	cout<<" Mo Tu We Th Fr Sa Su\n";
	cout<<"---------------------\n";
	cout<<"                    1\n";
	for (int date = 2; date <= 31; ++date)
	{
		wday = (WEEKDAY)((date+(int)date1-1)%7);
		if (wday == SUN)
		{
			cout<<setw(3)<<date<<endl;
		}
		else
			cout<<setw(3)<<date;
	}
	cout<<endl<<"---------------------\n";

	return 0;
}