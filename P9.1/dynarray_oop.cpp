
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "dynarray_oop.h"

using namespace std;

Dynarray::Dynarray()
{
	capcity = 0;
	count = 0;
	item = NULL;
	modified = false;
}

Dynarray::Dynarray(unsigned int capcity):capcity(capcity)
{
	// this->capcity = capcity;
	count = 0;
	item = NULL;
	modified = false;
}

Dynarray::~Dynarray()
{
	delete []item;
	item = NULL;
}

void Dynarray::DynSetValue(const int a[],unsigned int count)
{
	if ( count>(this->capcity) )
	{
		cout<<"Invalid input,please make sure [count] < [capcity].";
		exit(1);
	}
	this->count = count;
	item = new int[count];
	for (int i = 0; i < count; ++i)
	{
		item[i] = a[i];
	}
	modified = true;
}

void Dynarray::DynGetValue(int a[],unsigned int count)
{
	if ( count!=(this->count) )
	{
		cout<<"DynGetValue:Parameter Invalid."<<endl;
		exit(1);
	}

	for (int i = 0; i < count; ++i)
	{
		a[i] = item[i];
	}
}

int Dynarray::DynGetCount()
{
	return count;
}

bool Dynarray::DynGetModified()
{
	
	return modified;
}

void Dynarray::DynPrint()
{
	for (int i = 0; i < count; ++i)
	{
		printf("%d ",item[i] );
	}
}








