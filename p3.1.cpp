#include <iostream>
#include <cmath>
using namespace std;

bool Isprime(unsigned int x);

int main()
{
	// 测试程序
	unsigned int n;
	cout<<"This program determine wether a number is prime,1 means prime,0 is not.\n";
	cout<<"Plese input a number:";
	cin>>n;
	cout<<Isprime(n);
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