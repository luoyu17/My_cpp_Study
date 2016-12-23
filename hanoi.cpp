#include <iostream>

using namespace std;

typedef enum {X,Y,Z} HANOI;
void Welcomeinfo();
unsigned int Getnum();
void MoveHanoi(unsigned int n,HANOI from,HANOI temp,HANOI to);
void MovePlate(unsigned int n,HANOI from,HANOI to);
char ConvertHanoiToChar(HANOI x);


int main()
{
	unsigned int n;
	Welcomeinfo();
	n = Getnum();
	MoveHanoi(n,X,Y,Z);
	return 0;
}


void Welcomeinfo()
{
	cout<<"This programe shows the moving process of Hanoi game. \n";
}

unsigned int Getnum()
{
	unsigned int t;
	cout<<"Please input number of plate:";
	cin>>t;
	return t;
}
char ConvertHanoiToChar(HANOI x)
{
	switch(x)
	{
		case X: return 'X';
		case Y: return 'Y';
		case Z: return 'Z';
		default: return '\0';
	}
}
void MovePlate(unsigned int n,HANOI from,HANOI to)
{
	char fc,tc;
	fc = ConvertHanoiToChar(from);
	tc = ConvertHanoiToChar(to);
	cout << n <<":"<< fc <<"-->"<< tc << endl;
}
void MoveHanoi(unsigned int n,HANOI from,HANOI temp,HANOI to)
{
	if (n==1)
		MovePlate(n,from,to);
	else{
		MoveHanoi(n-1,from,to,temp);
		MovePlate(n,from,to);
		MoveHanoi(n-1,temp,from,to);
	}
}