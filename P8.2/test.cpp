#include <iostream>
#include "alist.h"

using namespace std;


int main(int argc, char const *argv[])
{
	
	// 测试程序，待补完

	PLIST t = LICreate();
	int a[2] = {1,2},b[2] = {3,4};
	cout<<LIIsEmpty(t)<<endl;
	LIAppend(t,a);
	int n = LIGetCount(t);
	cout<<n<<endl;
	LIInsert(t,b,1);
	n = LIGetCount(t);
	cout<<n<<endl;
	cout<<LIIsEmpty(t)<<endl;

	return 0;
}