#include <iostream>
using namespace std;

unsigned int RefbinomialCoeff(unsigned int n, unsigned int k);
unsigned int CycbinomialCoeff(unsigned int n, unsigned int k);


int main()
{
	// 测试程序
	unsigned int n =6,k=3;

	cout<<RefbinomialCoeff(n,k)<<endl;

	cout<<CycbinomialCoeff(n,k)<<endl;

	return 0;
}



unsigned int RefbinomialCoeff(unsigned int n, unsigned int k){
	if (k==0 || k==n)
		return 1;
	return  RefbinomialCoeff(n-1, k-1) + RefbinomialCoeff(n-1, k);
}


unsigned int CycbinomialCoeff(unsigned int n, unsigned int k){
	unsigned int i,j,a=1,b=1;
	if (k==0 || k==n)
		return 1;
	for (unsigned int i = n-k+1; i <= n; ++i)
	{
		a*=i;
	}
	for (unsigned int j = 1; j <= k; ++j)
	{
		b*=j;
	}
	return a/b;
}
 

    

  
