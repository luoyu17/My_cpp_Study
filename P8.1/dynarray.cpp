#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "dynarray.h"

using namespace std;

typedef struct DYNINTS* P_DYNINTS;

struct DYNINTS
{
	unsigned int capcity; /*最多包含元素数*/
	unsigned int count;   /*程序运行某个时刻元素个数*/
	int* item;            /*元素指针*/
	bool modified;        /*数组是否被改变*/
};

P_DYNINTS DynGenerate(unsigned int capcity)
{
	P_DYNINTS t = new DYNINTS;
	t->item = NULL;
	t->capcity = capcity;
	t->modified = false;
	return t;
}

void DynDelete(P_DYNINTS arr)
{
	if (arr)
	{
		if (arr->item)
		{
			delete [](arr->item);
		}
		delete arr;
	}
}

void DynSetValue(P_DYNINTS arr,const int a[],unsigned int count)
{
	if ( count>(arr->capcity) )
	{
		cout<<"Invalid input,please make sure [count] < [capcity].";
		exit(1);
	}
	arr->count = count;
	arr->item = new int[count];
	for (int i = 0; i < count; ++i)
	{
		(arr->item)[i] = a[i];
	}
	arr->modified = true;
}

void DynGetValue(P_DYNINTS arr,int a[],unsigned int count)
{
	if ( count!=(arr->count) )
	{
		cout<<"DynGetValue:Parameter Invalid."<<endl;
		exit(1);
	}

	for (int i = 0; i < count; ++i)
	{
		a[i] = (arr->item)[i];
	}
}

int DynGetCount(P_DYNINTS arr)
{
	if (!arr)
	{
		cout<<"DynGetCount:Parameter Invalid."<<endl;
		exit(1);
	}
	return arr->count;
}

bool DynGetModified(P_DYNINTS arr)
{
	if (!arr)
	{
		cout<<"DynGetCount:Parameter Invalid."<<endl;
		exit(1);
	}
	return arr->modified;
}

void DynPrint(P_DYNINTS arr)
{
	if (arr)
	{
		for (int i = 0; i < arr->count; ++i)
		{
			printf("%d ",(arr->item)[i] );
		}
	}
	else
		printf("NULL\n");
}