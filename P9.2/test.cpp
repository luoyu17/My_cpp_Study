#include <iostream>
#include "alist_oop.h"

using namespace std;


int main(int argc, char const *argv[])
{
	
	// 测试程序，待补完

	Alist list; 
	int a[2] = {1,2},b[2] = {3,4};

	cout<<list.LIIsEmpty()<<endl;

	list.LIAppend(a);

	int n = list.LIGetCount();
	cout<<n<<endl;

	list.LIInsert(b,1);
	n = list.LIGetCount();
	cout<<n<<endl;

	cout<<list.LIIsEmpty()<<endl;

	return 0;
}