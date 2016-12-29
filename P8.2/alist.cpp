#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>
#include "alist.h"

using namespace std;

struct NODE
{
	ADT data;
	PNODE next;
};

struct LIST
{
	unsigned int count;
	PNODE head,tail;
};


PLIST LICreate()
{
	PLIST p = new LIST;
	p->count = 0;
	p->head = NULL;
	p->tail = NULL;
	return p;
}

void LIAppend(PLIST list,ADT object)
{
	PNODE t = new NODE;
	if (!list || !object)
	{
		cout<<"LIAppend:Pramater illegal."<<endl;
		exit(1);
	}
	t->data = object;
	t->next = NULL;
	if (!list->head)
	{
		list->head = t;
		list->tail = t;
	}
	else
	{
		list->tail->next = t;
		list->tail = t;
	}
	list->count++;
}

void LIInsert(PLIST list,ADT object,unsigned int position)
{
	if (!list || !object)
	{
		cout<<"LIInsert:Pramater illegal."<<endl;
		exit(1);
	}
	if (position < list->count)
	{
		PNODE t = new NODE;
		t->data = object;
		t->next = NULL;
		if (position == 0)
		{
			t->next = list->head;
			list->head = t;
		}
		else
		{
			PNODE u = list->head;
			for (int i = 0; i < position-1; ++i)
			{
				u = u->next;
			}
			t->next = u->next;
			u->next = t;			
		}
		list->count++;
	}
	else
	{
		LIAppend(list,object);
	}
}

void LIClear(PLIST list,DESTROY_OBJECT destroy)
{
	if (!list)
	{
		cout<<"LIClear:Pramater illlegal."<<endl;
		exit(1);
	}
	while(list->head)
	{
		PNODE t = list->head;
		list->head = t->next;
		if (destroy)
		{
			(*destroy)(t->data);
		}
		delete t;
		list->count--;
	}
	list->tail = NULL;
}

void LIDestroy(PLIST list,DESTROY_OBJECT destroy)
{
	if (!list)
	{
		cout<<"LIDestroy:Pramater illlegal."<<endl;
		exit(1);
	}
	else
	{
		LIClear(list,destroy);
		delete list;
	}
}

void LIDelete(PLIST list,unsigned int position,DESTROY_OBJECT destroy)
{
	if (!list)
	{
		cout<<"LIDelete:Pramater illegal."<<endl;
		exit(1);
	}
	if (list->count == 0)
	{
		return;
	}
	if (position == 0)
	{
		PNODE t = list->head;
		list->head = t->next;
		if (!t->next)
		{
			list->tail = NULL;
		}
		if (destroy)
		{
			(*destroy)(t->data);
		}
		delete t;
		list->count--;
	}
	else if (position < list->count)
	{
		PNODE u = list->head,t;
		for (int i = 0; i < position-1; ++i)
		{
			u = u->next;
		}
		t = u->next;
		u->next = t->next;
		if (!t->next)
		{
			list->tail =u;
		}
		destroy;
		delete t;
		list->count--;
	}
}

void LITraverse(PLIST list,MANIPULATE_OBJECT manipulate,ADT tag)
{
	PNODE t = list->head;
	if (!list)
	{
		cout<<"LITraverse:Pramater illegal."<<endl;
		exit(1);
	}

	while( t )
	{
		if (manipulate)
		{
			(*manipulate)(t->data,tag);
		}
		t = t->next;
	}
}

bool LISerch(PLIST list,ADT object,COMPARE_OBJECT compare)
{
	PNODE t = list->head;

	if (!list)
	{
		cout<<"LISerch:Pramater illegal."<<endl;
		exit(1);
	}
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

unsigned int LIGetCount(PLIST list)
{
	if (!list)
	{
		cout<<"LIGetCount:Pramater illegal."<<endl;
		exit(1);
	}
	return list->count;
}

bool LIIsEmpty(PLIST list)
{
	if (!list)
	{
		cout<<"LIIsEmpty:Pramater illegal."<<endl;
		exit(1);
	}
	if (list->count == 0)
		return true;
	else
		return false;
}