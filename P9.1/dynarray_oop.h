


class Dynarray
{
public:
	Dynarray();
	Dynarray(unsigned int capcity);
	Dynarray(const Dynarray& that);
	~Dynarray();

	void DynSetValue(const int a[],unsigned int count);

	void DynGetValue(int a[],unsigned int count);

	int DynGetCount();

	bool DynGetModified();

	void DynPrint();
private:
	unsigned int capcity; /*最多包含元素数*/
	unsigned int count;   /*程序运行某个时刻元素个数*/
	int* item;            /*元素指针*/
	bool modified;        /*数组是否被改变*/
};
