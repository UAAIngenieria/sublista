#include <stdio.h>
#include <stdlib.h>
#include "sub.h"
// Funciones auxiliares
TList * newNodo(TList contenido){
    TList* nodoL = malloc(sizeof(TList));
    *nodoL = contenido;
    nodoL->sub = NULL;
    nodoL->sig = NULL;
}

TSub * newSubNodo(TSub contenido){
    TSub * nodoS = malloc(sizeof(TSub));
    *nodoS = contenido;
    nodoS->sig = NULL;
}
TList scanNodo(){
    TList aux;
    printf("Nuevo Nodo\n\nIngrese un n%cmero entero: ",163);
    fflush(stdin); scanf("%d", &aux.num);
    return aux;
}
TSub scanSubNodo(){
    TSub aux;
    printf("Nuevo SubNodo\n\nIngrese un n%cmero entero: ",163);
    fflush(stdin); scanf("%d", &aux.num);
    return aux;
}
int inSub(TList * sL){}
// Funciones principales
void insertOrdList(TList **L, TList * nodo){
    if(*L == NULL){
        *L = nodo;
    }else{
        if((*L)->num>nodo->num){
            nodo->sig = *L;
            *L = nodo;
        }else{
            TList * aux = *L;
            while((aux->sig!=NULL)&&(aux->sig->num<nodo->num)){
                    aux = aux->sig;
            }
            if(aux->sig==NULL){
                aux->sig = nodo;
            }else{
                nodo->sig = aux->sig;
                aux->sig = nodo;
            }
        }
    }
    return;
}

void insertOrdSub(TSub **sL, TSub * sNodo){
    if(*sL == NULL){
        *sL = sNodo;
    }else{
        if((*sL)->num>sNodo->num){
            sNodo->sig = *sL;
            *sL = sNodo;
        }else{
            TSub * aux = *sL;
            while((aux->sig!=NULL)&&(aux->sig->num<sNodo->num)){
                    aux = aux->sig;
            }
            if(aux->sig==NULL){
                aux->sig = sNodo;
            }else{
                sNodo->sig = aux->sig;
                aux->sig = sNodo;
            }
        }
    }
    return;
}
void printListAndSub(TList *L){
    while(L!=NULL){
        printf("[%d]",L->num);
        if(L->sig!=NULL){
            printf("\n   ");
        }
        printSub(L->sub);
        printf("\n");
        L= L->sig;
    }
    return;
}
void printSub(TSub *sL){
    while(sL!=NULL){
        printf("->[%d]",sL->num);
        sL=sL->sig;
    }
    return;
}
void delSub(TSub **sL){
    TSub * targetS;
    while((*sL)!=NULL){
        targetS = *sL;
        *sL = (*sL)->sig;
        free(targetS);
    }
    return;
}
void delListAndSub(TList **L){
    TList * targetL;
    while((*L)!=NULL){
        targetL = *L;
        if(targetL->sub!=NULL){
            delSub(&targetL->sub);
        }
        *L = (*L)->sig;
        free(targetL);
    }
    return;
}
