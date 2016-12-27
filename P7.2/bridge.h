



struct CARD
{
	char suit;
	char intgers;
};//未进行信息隐藏，后面改正
void InitializeCards(CARD a[],int SumOfCards);

void RandShuffle(CARD packs[],int SumOfCards);

void DistrubuteCard(CARD plyer[],CARD packs[],int first,int count);

void PrintCards(CARD a[],int count);
