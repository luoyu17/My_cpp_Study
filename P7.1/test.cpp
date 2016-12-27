#include <iostream>
#include "rational.h"
using namespace std;



int main(int argc, char const *argv[])
{
	// 测试程序
	RATIONAL_NUM a,b,c;
	RATIONAL_NUM *p = &a,*q = &b;

	a = GetRationalNum(2,4);
	b = GetRationalNum(3,7);
	cout<<a.numerator<<endl;
	cout<<b.denominator<<endl;
	c = Simplify(p);
	cout<<c.numerator<<"/"<<c.denominator<<endl;
	c = Add(p,q);
	cout<<c.numerator<<"/"<<c.denominator<<endl;
	c = Subtract(p,q);
	cout<<c.numerator<<"/"<<c.denominator<<endl;
	c = Multiply(p,q);
	cout<<c.numerator<<"/"<<c.denominator<<endl;
	c = Divide(p,q);
	cout<<c.numerator<<"/"<<c.denominator<<endl;

	return 0;
}