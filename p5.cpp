#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void GanerateNRRNum(int low ,int high, int count);
void Randomize();
int GanerateRNum(int low,int high);

int main(int argc, char const *argv[])
{
	//测试程序
	GanerateNRRNum(1 ,52, 52);
	return 0;
}


void GanerateNRRNum(int low ,int high, int count)
{
	int a[count];
	int n = 1,b;

	Randomize();
	a[0] = GanerateRNum(low,high);

	while( n < count )
	{
		b = GanerateRNum(low,high);
		for (int i = 0; i < n; ++i)
		{	
			if ( b==a[i] )
			{
				b = GanerateRNum(low,high);
				i = 0;
			}
		}
		a[n] = b;
		++n;
	}
	cout<<count<<" NOT repeating numbers the rand function generate as fallows:\n";
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
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