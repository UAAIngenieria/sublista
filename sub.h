typedef struct sublista{
    int num;
    struct sublista *sig;
}TSub;

typedef struct lista{
    int num;
    struct lista * sig;
    struct TSub * sub;
}TList;

// Funciones auxiliares
TList * newNodo(TList contenido);
TSub * newSubNodo(TSub contenido);
TList scanNodo();
TSub scanSubNodo();

// Funciones principales
void insertOrdList(TList **L, TList *nodo);
void insertOrdSub(TSub **sL, TSub *sNodo);
void printListAndSub(TList *L);
void printSub(TSub *sL);
void delSub(TSub **sL);
void delListAndSub(TList **L);
