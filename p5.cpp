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

void GanerateNRRNum(int low ,int high, int count);
void Randomize();
int GanerateRNum(int low,int high);
string ConvertPOKERToStr(POKER x);
void GaneratePokerCard();


int main(int argc, char const *argv[])
{
	//测试程序
	GanerateNRRNum(1 ,52, 52);
	cout<<endl;
	GaneratePokerCard();
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

void GaneratePokerCard()
{
	int a[52];
	POKER card[52];

	int n = 1,temp;

	Randomize();
	a[0] = GanerateRNum(1,52);

	while( n < 52 )
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
	cout<<"52 cards the rand function generate as fallows:\n";

	for (int i = 0; i < n; ++i)
	{
		card[i] = (POKER)a[i];
		cout<<ConvertPOKERToStr(card[i])<<" ";
	}
}

string ConvertPOKERToStr(POKER x)
{
	switch(x)
	{
		case C2: return "C2";
		case C3: return "C3";
		case C4: return "C4";
		case C5: return "C5";
		case C6: return "C6";
		case C7: return "C7";
		case C8: return "C8";
		case C9: return "C9";
		case C10: return "C10";
		case CJ: return "CJ";
		case CQ: return "CQ";
		case CK: return "CK";
		case CA: return "CA";
		case D2: return "D2";
		case D3: return "D3";
		case D4: return "D4";
		case D5: return "D5";
		case D6: return "D6";
		case D7: return "D7";
		case D8: return "D8";
		case D9: return "D9";
		case D10: return "D10";
		case DJ: return "DJ";
		case DQ: return "DQ";
		case DK: return "DK";
		case DA: return "DA";
		case H2: return "H2";
		case H3: return "H3";
		case H4: return "H4";
		case H5: return "H5";
		case H6: return "H6";
		case H7: return "H7";
		case H8: return "H8";
		case H9: return "H9";
		case H10: return "H10";
		case HJ: return "HJ";
		case HQ: return "HQ";
		case HK: return "HK";
		case HA: return "HA";
		case S2: return "S2";
		case S3: return "S3";
		case S4: return "S4";
		case S5: return "S5";
		case S6: return "S6";
		case S7: return "S7";
		case S8: return "S8";
		case S9: return "S9";
		case S10: return "S10";
		case SJ: return "SJ";
		case SQ: return "SQ";
		case SK: return "SK";
		case SA: return "SA";
		default: return "...";
	}
}
