#include <iostream>
#include <cstdlib>
#include "rational.h"

using namespace std;

static int Getgcd( int x,int y );

RATIONAL_NUM GetRationalNum(int numerator,int denominator)
{
	if (denominator==0)
	{
		cout<<"Invalid parameter,please ensure denominator is not 0.";
		exit(1);
	}
	RATIONAL_NUM t = {numerator,denominator};
	return t;
}

RATIONAL_NUM Simplify(const RATIONAL_NUM *prational)
{
	int a = (prational -> numerator);
	int b = (prational -> denominator);
	if (b==0)
	{
		cout<<"Invalid parameter,please ensure denominator is not 0.";
		exit(1);
	}
	int gcd = Getgcd(a,b);
	return GetRationalNum(a/gcd,b/gcd);
}

RATIONAL_NUM Add(const RATIONAL_NUM *prational_a,const RATIONAL_NUM *prational_b)
{
	int a = (prational_a -> numerator)*(prational_b -> denominator) + (prational_b -> numerator)*(prational_a -> denominator);
	int b = (prational_a -> denominator)*(prational_b -> denominator);
	RATIONAL_NUM c = GetRationalNum(a,b);
	RATIONAL_NUM *p = &c;
	return Simplify( p );
}

RATIONAL_NUM Subtract(const RATIONAL_NUM *prational_a,const RATIONAL_NUM *prational_b)
{
	int a = (prational_a -> numerator)*(prational_b -> denominator) - (prational_b -> numerator)*(prational_a -> denominator);
	int b = (prational_a -> denominator)*(prational_b -> denominator);
	RATIONAL_NUM c = GetRationalNum(a,b);
	RATIONAL_NUM *p = &c;
	return Simplify( p );
}

RATIONAL_NUM Multiply(const RATIONAL_NUM *prational_a,const RATIONAL_NUM *prational_b)
{
	int a = (prational_a -> numerator)*(prational_b -> numerator);
	int b = (prational_a -> denominator)*(prational_b -> denominator);
	RATIONAL_NUM c = GetRationalNum(a,b);
	RATIONAL_NUM *p = &c;
	return Simplify( p );
}

RATIONAL_NUM Divide(const RATIONAL_NUM *prational_a,const RATIONAL_NUM *prational_b)
{
	int a = (prational_a -> numerator)*(prational_b -> denominator);
	int b = (prational_b -> numerator)*(prational_a -> denominator);
	RATIONAL_NUM c = GetRationalNum(a,b);
	RATIONAL_NUM *p = &c;
	return Simplify( p );
}


static int Getgcd( int x,int y )
{
	int t;
	t = x>y?y:x;
	while(x % t != 0 || y % t != 0)
	t--;
	return t;
}
