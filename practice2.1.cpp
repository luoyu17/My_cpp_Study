/////////////////////////////////////////////////////////////////////////
//http://www.xuetangx.com/courses/course-v1:TsinghuaX+20740084X+sp/about
//practice 2.1
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n,m;
	cout<<"This programe will print two triangle,n means rows,m means margin\n";
	cout<<"please input n:\n";
	cin>>n;
	cout<<"please input m:\n";
	cin>>m;
	if (n <= 0||m <= 0)
	{
		cout<<"data error\n";
		return 1;
	}

	for (int i = 1; i <= n; ++i)
	{
		cout<<setw(n-i+1)<<" ";
		for (int j = 1; j <= 2*i-1; ++j)
		{
			cout<<"*";
		}
		cout<<setw(m)<<" ";
		for (int k = 1; k <= 2*n-2*i+1; ++k)
		{
			cout<<"*";
		}
		cout<<endl;
	}	
	
	return 0;
}