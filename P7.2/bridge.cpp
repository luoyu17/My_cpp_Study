#include <iostream>
#include <cstdlib>
#include "bridge.h"
#include "random.h"
#define NBUG 

using namespace std;


void InitializeCards(CARD a[],int SumOfCards)
{
	if (SumOfCards!=52)
	{
		cout<<"52 cards please";
		exit(1);
	}
	for (int i = 0; i < 8; ++i)
	{
		a[i].intgers =(char)(i+2+48);
	}
	for (int i = 13; i < 21; ++i)
	{
		a[i].intgers =(char)(i+2+48-13);
	}
	for (int i = 26; i < 34; ++i)
	{
		a[i].intgers =(char)(i+2+48-26);
	}
	for (int i = 39; i < 47; ++i)
	{
		a[i].intgers =(char)(i+2+48-39);
	}
	for (int i = 0; i < 13; ++i)
	{
		a[i].suit = 'C';
	}
	for (int i = 13; i < 26; ++i)
	{
		a[i].suit = 'D';
	}
	for (int i = 26; i < 39; ++i)
	{
		a[i].suit = 'H';
	}
	for (int i = 39; i < 52; ++i)
	{
		a[i].suit = 'S';
	}
	a[8].intgers = a[21].intgers = a[34].intgers = a[47].intgers = 'T';
	a[9].intgers = a[22].intgers = a[35].intgers = a[48].intgers = 'J';
	a[10].intgers = a[23].intgers = a[36].intgers = a[49].intgers = 'Q';
	a[11].intgers = a[24].intgers = a[37].intgers = a[50].intgers = 'K';
	a[12].intgers = a[25].intgers = a[38].intgers = a[51].intgers = 'A';
}

static void GenerateNR52numArr(int a[],int count)
{
	int n = 1,temp;
	Randomize();
	a[0] = GenerateRandomNum(0,51);
	while( n < count )
	{
		temp = GenerateRandomNum(0,51);
		for (int i = 0; i < n; ++i)
		{	
			if ( temp==a[i] )
			{
				temp = GenerateRandomNum(0,51);
				i = 0;
			}
		}
		a[n] = temp;
		++n;
	}
	#ifndef NBUG
	cout<<"Debugging:"<<endl;
	for (int i = 0; i < count; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	#endif
}

void RandShuffle(CARD packs[],int SumOfCards)
{
	int a[SumOfCards];
	CARD temp[SumOfCards];
	GenerateNR52numArr(a,SumOfCards);

	for (int i = 0; i < SumOfCards; ++i)
	{
		temp[i] = packs[a[i]];
	}
	#ifndef NBUG
	cout<<"Debugging:"<<endl;
	PrintCards(temp,52);
	cout<<endl;
	#endif
	for (int i = 0; i < SumOfCards; ++i)
	{
		packs[i] = temp[i];
	}

}


void DistrubuteCard(CARD plyer[],CARD packs[],int first,int count)
{
	for (int i = 0; i < count; ++i)
	{
		plyer[i] = packs[first];
		++first;
	}
}

void PrintCards(CARD a[],int count)
{
	cout<<"[";
	for (int i = 0; i < count; ++i)
	{
		cout<<a[i].suit<<a[i].intgers<<" ";
	}
	cout<<"]"<<endl;
}

