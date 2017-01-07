


typedef void* ADT; typedef const void* CADT;

typedef struct NODE* PNODE;

// 函数指针类型
typedef int (*COMPARE_OBJECT)(CADT e1, CADT e2);
typedef void (*DESTROY_OBJECT)(ADT e);
typedef void (*MANIPULATE_OBJECT)(ADT e, ADT tag);


//类定义
class Alist
{
public:

	Alist();
	void LIDestroy(DESTROY_OBJECT destroy);
	void LIAppend(ADT object);
	void LIInsert(ADT object,unsigned int position);
	void LIDelete(unsigned int position,DESTROY_OBJECT destroy);
	void LIClear(DESTROY_OBJECT destroy);
	void LITraverse(MANIPULATE_OBJECT manipulate,ADT tag);
	bool LISerch(ADT object,COMPARE_OBJECT compare);
	unsigned int LIGetCount();
	bool LIIsEmpty();
private:
	unsigned int count;
	PNODE head,tail;
};
