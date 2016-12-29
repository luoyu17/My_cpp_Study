


typedef void* ADT; typedef const void* CADT;
typedef struct NODE* PNODE;
typedef struct LIST* PLIST;

// 函数指针类型
typedef int (*COMPARE_OBJECT)(CADT e1, CADT e2);
typedef void (*DESTROY_OBJECT)(ADT e);
typedef void (*MANIPULATE_OBJECT)(ADT e, ADT tag);
// 操作函数接口
PLIST LICreate();
void LIDestroy(PLIST list,DESTROY_OBJECT destroy);
void LIAppend(PLIST list,ADT object);
void LIInsert(PLIST list,ADT object,unsigned int position);
void LIDelete(PLIST list,unsigned int position,DESTROY_OBJECT destroy);
void LIClear(PLIST list,DESTROY_OBJECT destroy);
void LITraverse(PLIST list,MANIPULATE_OBJECT manipulate,ADT tag);
bool LISerch(PLIST list,ADT object,COMPARE_OBJECT compare);
unsigned int LIGetCount(PLIST list);
bool LIIsEmpty(PLIST list);
