#include <iostream>
#include "dynarray_oop.h"

using namespace std;

int main(int argc, char const *argv[])
{
	/* 测试程序 */
	int a[6] = {2,3,4,5,6,7},b[6];
	
	Dynarray arr(6);
	arr.DynSetValue(a,6);
	arr.DynPrint();

	cout<<endl<<arr.DynGetModified();
	cout<<endl<<arr.DynGetCount()<<endl;

	arr.DynGetValue(b,6);
	for (int i = 0; i < 6; ++i)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}