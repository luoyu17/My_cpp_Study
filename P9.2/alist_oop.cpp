#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>
#include "alist_oop.h"

using namespace std;



struct NODE
{
	ADT data;
	PNODE next;
};

Alist::Alist()
{
	count = 0;
	head = NULL;
	tail = NULL;
}


void Alist::LIAppend(ADT object)
{
	PNODE t = new NODE;
	if (!object)
	{
		cout<<"LIAppend:Pramater illegal."<<endl;
		exit(1);
	}
	t->data = object;
	t->next = NULL;
	if (!head)
	{
		head = t;
		tail = t;
	}
	else
	{
		tail->next = t;
		tail = t;
	}
	count++;
}

void Alist::LIInsert(ADT object,unsigned int position)
{
	if (!object)
	{
		cout<<"LIInsert:Pramater illegal."<<endl;
		exit(1);
	}
	if (position < count)
	{
		PNODE t = new NODE;
		t->data = object;
		t->next = NULL;
		if (position == 0)
		{
			t->next = head;
			head = t;
		}
		else
		{
			PNODE u = head;
			for (int i = 0; i < position-1; ++i)
			{
				u = u->next;
			}
			t->next = u->next;
			u->next = t;			
		}
		count++;
	}
	else
	{
		this->LIAppend(object);
	}
}

void Alist::LIClear(DESTROY_OBJECT destroy)
{
	while(head)
	{
		PNODE t = head;
		head = t->next;
		if (destroy)
		{
			(*destroy)(t->data);
		}
		delete t;
		count--;
	}
	tail = NULL;
}


void Alist::LIDelete(unsigned int position,DESTROY_OBJECT destroy)
{
	if (count == 0)
	{
		return;
	}
	if (position == 0)
	{
		PNODE t = head;
		head = t->next;
		if (!t->next)
		{
			tail = NULL;
		}
		if (destroy)
		{
			(*destroy)(t->data);
		}
		delete t;
		count--;
	}
	else if (position < count)
	{
		PNODE u = head,t;
		for (int i = 0; i < position-1; ++i)
		{
			u = u->next;
		}
		t = u->next;
		u->next = t->next;
		if (!t->next)
		{
			tail =u;
		}
		destroy;
		delete t;
		count--;
	}
}

void Alist::LITraverse(MANIPULATE_OBJECT manipulate,ADT tag)
{
	PNODE t = head;
	while( t )
	{
		if (manipulate)
		{
			(*manipulate)(t->data,tag);
		}
		t = t->next;
	}
}

bool Alist::LISerch(ADT object,COMPARE_OBJECT compare)
{
	PNODE t = head;

	while( t )
	{
		if ((*compare)(t->data,object) == 0)
		{
			return true;
		}
		t = t->next;
	}
	return false;
}

unsigned int Alist::LIGetCount()
{
	return count;
}

bool Alist::LIIsEmpty()
{
	if (count == 0)
		return true;
	else
		return false;
}