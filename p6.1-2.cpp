#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void Randomize();
int GanerateRNum(int low,int high);
void GenerateIntegers(int a[],int n,int lower,int upper);
void SwapIntegers(int a[],int i,int j);
void PrintIntegers(int a[],int n );
void Sort_1(int a[],int n);
bool Serch(int a[],int n,int key);


int main()
{
	// 测试程序

	int arr[8];
	GenerateIntegers(arr,8,1,20);
	PrintIntegers(arr,8 );
	Sort_1( arr,8);
	PrintIntegers(arr,8 );
	cout<<Serch(arr,8,5);
	return 0;
}

void Sort_1( int a[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int i = 0; i < n; ++i)
		{
			if (a[i]>a[i+1])
			{
				SwapIntegers(a,i,i+1);
			}
		}
	}	
}



bool Serch(int a[],int n,int key)
{
	for (int i = 0; i < n; ++i)
		{	
			if ( key==a[i] )
			{
				return true;
			}
		}
	return false;
}



void GenerateIntegers(int a[],int n,int lower,int upper)
{
	Randomize();
	for (int i = 0; i < n; ++i)
	{
		a[i] = GanerateRNum(lower,upper);
	}
}

void SwapIntegers(int a[],int i,int j)
{
	int t;
	t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void PrintIntegers(int a[],int n )
{
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void Randomize()
{
	srand( (int)time(NULL) );
}


int GanerateRNum(int low,int high)
{
	double d;
	if (low > high)
	{
		cout<<"Please make sure low <= high.\n";
		exit(1);
	}
	d = (double)rand() / ( (double)RAND_MAX+1.0);

	return (low + (int)(d*(high-low+1)));
}