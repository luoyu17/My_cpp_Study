

struct DYNINTS;

typedef struct DYNINTS* P_DYNINTS;


P_DYNINTS DynGenerate(unsigned int capcity);

void DynDelete(P_DYNINTS arr);

void DynSetValue(P_DYNINTS arr,const int a[],unsigned int count);

void DynGetValue(P_DYNINTS arr,int a[],unsigned int count);

int DynGetCount(P_DYNINTS arr);

bool DynGetModified(P_DYNINTS arr);

void DynPrint(P_DYNINTS arr);