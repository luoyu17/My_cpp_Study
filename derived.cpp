#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
	Base(string s):str_a(s){}
	Base(const Base& that){str_a = that.str_a;}
	void Print() const
	{
		cout<<"In Base:"<<str_a<<endl;
	}
protected:
	string str_a;
	
};

class Derived:public Base
{
public:
	Derived(string s1,string s2):Base(s1),str_b(s2){} //Base的构造应写在初始化列表里面
	void Print() const
	{
		cout<<"In Derived:"<<str_a + "" + str_b<<endl;
	}
protected:
	string str_b;
}