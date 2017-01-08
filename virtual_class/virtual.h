

class Account
{
public:
	Account(double d):_banlance(d){}
	double GetBalance() const;
	virtual void PrintBalance() const = 0;
	virtual ~Account(){};
protected:
	double _banlance;	
};


class CheckingAccount:public Account
{
public:
	CheckingAccount(double d):Account(d){}
	virtual void PrintBalance() const;
};

class SavingAccount:public Account
{
public:
	SavingAccount(double d):Account(d){}
	virtual void PrintBalance() const;
};