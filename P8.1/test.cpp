#include <iostream>
#include "dynarray.h"

using namespace std;

int main(int argc, char const *argv[])
{
	/* 测试程序 */
	P_DYNINTS p;
	int a[6] = {2,3,4,5,6,7},b[6];
	p = DynGenerate(6);
	DynSetValue(p,a,6);
	DynPrint( p );

	cout<<endl<<DynGetModified(p);
	cout<<endl<<DynGetCount(p)<<endl;

	DynGetValue(p,b,6);
	for (int i = 0; i < 6; ++i)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
