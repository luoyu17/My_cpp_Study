#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
typedef enum
{
	C2=1,C3,C4,C5,C6,C7,C8,C9,C10,CJ,CQ,CK,CA,
	D2,D3,D4,D5,D6,D7,D8,D9,D10,DJ,DQ,DK,DA,
	H2,H3,H4,H5,H6,H7,H8,H9,H10,HJ,HQ,HK,HA,
	S2,S3,S4,S5,S6,S7,S8,S9,S10,SJ,SQ,SK,SA,
} POKER;
void PrintIntegers(int a[],int n );
void GanerateNRcardArr(int a[],int count);
void Randomize();
int GanerateRNum(int low,int high);
void DistrubuteCard(int a[],int b[],int first,int count);
int ConvertPokerToNum(POKER x);
void ConvertPlayerArrToCount(int a[],int n);
int SumOfArr(int a[],int count);

int main()
{
	int card[52];
	int player_1[13],player_2[13],player_3[13],player_4[13];
	
	GanerateNRcardArr(card,52);
	DistrubuteCard(player_1,card,0,13);
	DistrubuteCard(player_2,card,13,13);
	DistrubuteCard(player_3,card,26,13);
	DistrubuteCard(player_4,card,39,13);

	ConvertPlayerArrToCount(player_1,13);
	ConvertPlayerArrToCount(player_2,13);
	ConvertPlayerArrToCount(player_3,13);
	ConvertPlayerArrToCount(player_4,13);


	cout<<"Sum of player_1 counts is:"<<SumOfArr(player_1,13)<<endl;
	cout<<"Sum of player_2 counts is:"<<SumOfArr(player_2,13)<<endl;
	cout<<"Sum of player_3 counts is:"<<SumOfArr(player_3,13)<<endl;
	cout<<"Sum of player_4 counts is:"<<SumOfArr(player_4,13)<<endl;

	return 0;
}


int SumOfArr(int a[],int count)
{
	int sum = 0;
	for (int i = 0; i < count; ++i)
	{
		sum += a[i];
	}
	return sum;
}

void ConvertPlayerArrToCount(int a[],int n)
{
	POKER temp;
	for (int i = 0; i < n; ++i)
	{
		temp =(POKER)a[i];
		a[i] = ConvertPokerToNum(temp);
	}
}

int ConvertPokerToNum(POKER x)
{
	if ( x<=9 || ( x>13 && x<=22) || (x>26 && x<=35) ||(x>39 && x<=48) )
		return 0;
	if ( x==10 || x==23 || x==36 || x==49)
		return 1;
	if ( x==11 || x==24 || x==37 || x==50)
		return 2;
	if ( x==12 || x==25 || x==38 || x==51)
		return 3;
	if ( x==13 || x==26 || x==39 || x==52)
		return 4;
}

void DistrubuteCard(int a[],int b[],int first,int count)
{
	for (int i = 0; i < count; ++i)
	{
		a[i] = b[first];
		++first;
	}
}

void GanerateNRcardArr(int a[],int count)
{
	int n = 1,temp;
	Randomize();
	a[0] = GanerateRNum(1,52);
	while( n < count )
	{
		temp = GanerateRNum(1,52);
		for (int i = 0; i < n; ++i)
		{	
			if ( temp==a[i] )
			{
				temp = GanerateRNum(1,52);
				i = 0;
			}
		}
		a[n] = temp;
		++n;
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

void PrintIntegers(int a[],int n )
{
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}