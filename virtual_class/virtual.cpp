#include <iostream>
#include "virtual.h"

using namespace std;



inline double Account::GetBalance() const
{
	return _banlance;
}


void CheckingAccount::PrintBalance() const
{
	cout<<"Checking account balance:"<<GetBalance()<<endl;
}

void SavingAccount::PrintBalance() const
{
	cout<<"Saving account balance:"<<GetBalance()<<endl;
}