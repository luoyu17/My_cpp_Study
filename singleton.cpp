#include <iostream>
using namespace std;



class Singleton //单子
{
public:

	static Singleton & Get()
	{
		static Singleton _s; //静态成员函数的静态变量，保证唯一性
		return _s;
	}
	int GetData()
	{
		return ++a;
	}

private: //私有构造与析构，禁止外部调用
	Singleton(){a = 0;}
	Singleton(const Singleton& that);
	Singleton& operator = (const Singleton& that);
	~Singleton(){};
private:
	int a;//验证数据
};


//验证程序
int main(int argc, char const *argv[])
{
	cout<<Singleton::Get().GetData()<<endl;
	cout<<Singleton::Get().GetData()<<endl;
	cout<<Singleton::Get().GetData()<<endl;
	return 0;
}


