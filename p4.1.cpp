#include <iostream>
#include <cmath>
using namespace std;

bool Isprime(unsigned int x);
unsigned int PrimeFac(unsigned int n);

int main()
{
	// 测试程序
	unsigned int a;
	cout<<"This program can prime factorization.\n";
	cout<<"Plese input a number:";
	cin>>a;
	cout<<PrimeFac(a)<<endl;
	return 0;
}

bool Isprime(unsigned int x){
	unsigned int i =3, t =(unsigned int)sqrt(x);

	if(x==2)
		return true;
	if(x % 2==0)
		return false;
	while(i <= t){
		if (x % i == 0)
		return false;
	i+=2;
	}
	return true;
}

unsigned int PrimeFac(unsigned int n){
	if (Isprime(n))
		return n;

	for (int i = 2; i < n; ++i)
	{
		if (Isprime(i) && n%i==0)
		{
			cout<<i<<"*";
			return PrimeFac(n/i);
		}
	}
}