/////////////////////////////////
// 一个猜随机价格游戏
// 练习软件开发流程规范
/////////////////////////////////

#include <iostream>
#include "guess.h"
int main( )
{
	double prevailed_ratio;/*定义一个游戏胜率*/

	PrintWelcomeInfo();/*打印欢迎信息及规则*/

	InitializeGame();/*初始化游戏*/

	prevailed_ratio = PlayGame();/*进行游戏并返回胜率值*/

	PrintGameOverInfo( prevailed_ratio );/*打印结束信息*/

	return 0;
}