#include <iostream>
#include <cmath>
using namespace std;
unsigned int Getgcd(unsigned int x,unsigned int y);
unsigned int Getlcm(unsigned int x,unsigned int y);

int main()
{
	// 测试程序
	unsigned int a,b;
	cout<<"This program can computes GCD and LCM of two numbers.\n";
	cout<<"Plese input a:";
	cin>>a;
	cout<<"Plese input b:";
	cin>>b;
	cout<<"GCD is:"<<Getgcd(a,b)<<endl;
	cout<<"LCM is:"<<Getlcm(a,b);

	return 0;
}

unsigned int Getgcd(unsigned int x,unsigned int y){
	unsigned int t;
	t = x>y?y:x;
	while(x % t != 0 || y % t != 0)
	t--;
	return t;
}

unsigned int Getlcm(unsigned int x,unsigned int y){
	
	unsigned int t;
	t = x>y?x:y;

	for (t <= x*y; ++t;)
	{
		if (t % x == 0 && t % y == 0)
			return t;
	}	
}