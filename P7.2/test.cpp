#include "bridge.h"


const int SumOfCards = 52;

int main(int argc, char const *argv[])
{
	// 测试程序
	CARD poker[SumOfCards],plyer1[13];
	
	InitializeCards(poker,SumOfCards);
	PrintCards(poker,SumOfCards);

	RandShuffle(poker,SumOfCards);
	PrintCards(poker,SumOfCards);

	DistrubuteCard(plyer1,poker,0,13);
	PrintCards(plyer1,13);

	return 0;
}