#include <iostream>
#include <iomanip>

#include "guess.h"
#include "random.h"
#define NBUG

using namespace std;

const int lowest_price = 10;
const int highest_price = 30;
const int guess_count = 6;
int sum_bout_count = 0;

static int InitializeBout();

static bool PlayBout(int actual_price,int lower_price,int higher_price,int chance_left);

static bool Again();

static int GetPrice(int lower_price,int higher_price,int chance_left);

static int CheckPrice(int lower_price,int higher_price,int guess_price);

static int JudgePrice(int actual_price,int guess_price);



// 游戏欢迎信息
void PrintWelcomeInfo()
{
	cout<<"The programe lists a product with price between "
	<<lowest_price<<" and "<<highest_price<<" Yuan.\n";
	cout<<"You should give a price,if the price you give is correct,you WIN!\n";
	cout<<"You have "<<guess_count<<" chances to win your bonus...\n";
}
// 初始化游戏
void InitializeGame()
{
	Randomize();
}
// 游戏进程
double PlayGame()
{
	int actual_price, higher_price = highest_price,lower_price = lowest_price;
	int chance_left = guess_count;
	int prevailed_bout_count = 0;

	while(true)
	{
		actual_price = InitializeBout();
		#ifndef NBUG
		cout<<"Debgging:actual_price is"<<actual_price<<endl;
		#endif
		if ( PlayBout(actual_price,lower_price,higher_price,chance_left) )
		{
			prevailed_bout_count++;
		}
		if (!Again())
		{
			break;
		}
	}

	return (double)prevailed_bout_count/(double)sum_bout_count;
}
// 游戏结束信息
void PrintGameOverInfo(double prevailed_ratio)
{
	cout<<"\nprevailed ratio:"<<prevailed_ratio*100<<"%.\n";
	if (prevailed_ratio >= 0.8)
	{
		cout<<"You Luckyyyyyyyyyyyy!\n\n";
	}
	else if (prevailed_ratio >= 0.5)
	{
		cout<<"Not bad";
	}
	else
		cout<<"Wish you luck!";
}

static int InitializeBout()
{
	
	return GenerateRandomNum(lowest_price,highest_price);
}

static bool PlayBout(int actual_price,int lower_price,int higher_price,int chance_left)
{
	int guess_price,judge_result;

	// 猜测循环
	while( chance_left>0 )
	{
		// 获取价格
		guess_price = GetPrice(lower_price,higher_price,chance_left);
		// 检查输入价格是否合法
		guess_price = CheckPrice(lower_price,higher_price,guess_price);
		chance_left--;
		// 判断猜测结果并返回值
		judge_result = JudgePrice(actual_price,guess_price);
		switch( judge_result )
		{
			case 1:
			if (chance_left > 0 )
			{
				cout<<"Wrong,Please,try again\n";
				// 预留降低难度接口
				// cout<<"\nHigher.\n";
				// higher_price = guess_price-1;
			}
			else
			{
				cout<<"\nYou lose this bout,The actual price is "<<actual_price<<endl;
				return false;
			}
			break;
			case -1:
			if (chance_left > 0 )
			{
				cout<<"Wrong,Please try again\n";
				// 预留降低难度接口
				// cout<<"\nLower.\n";
				// lower_price = guess_price+1;
			}
			else
			{
				cout<<"\nYou lose this bout,The actual price is "<<actual_price<<endl;
				return false;
			}
			break;
			default:
			cout<<"You WINNNNNNNNN!\n";
			sum_bout_count++;
			return true;
		}
		// 计数总的猜测次数
		sum_bout_count++;
	}

	return false;
}

// 询问是否再来一次
static bool Again()
{
	int t;
	cout<<"Play a new game(\'0\'to stop,other numbers to play again)?";
	cin>>t;
	#ifndef NBUG
		cout<<"Debgging:t==0 is"<<(t!=0)<<endl;
	#endif
	return t!=0;
}

// 获取价格接口
static int GetPrice(int lower_price,int higher_price,int chance_left)
{
	int t;
	cout<<"The actual price is in ["<<lower_price<<","<<higher_price<<"].";
	cout<<"Chances left "<<chance_left<<"\nyour guess is:";
	cin>>t;
	return t;
}
// 检查输入价格是否合法
static int CheckPrice(int lower_price,int higher_price,int guess_price)
{
	int t = guess_price;
	while(t<lower_price || t>higher_price)
	{
		cout<<"Please chose one in ["<<lower_price<<","<<higher_price<<"]."<<endl;
		cout<<"Please try again.";
		cin>>t;
	}
	return t;
}
// 判断价格是否正确
static int JudgePrice(int actual_price,int guess_price)
{
	int t = guess_price - actual_price;
	if( t>0 )
		return 1;
	else if( t<0 )
		return -1;
	else
		return 0;
}