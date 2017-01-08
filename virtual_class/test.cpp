#include "virtual.h"

int main(int argc, char const *argv[])
{
	CheckingAccount* c = new CheckingAccount(100.0);
	SavingAccount* s = new SavingAccount(1000.0);

	Account* account = c;
	account->PrintBalance();

	account = s;
	account->PrintBalance();

	delete s;
	delete c;


	return 0;
}
