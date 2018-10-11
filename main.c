/*
*   Ejemplo simple de creación, mostrar y eliminación
*   de una Lista de enteros con una Sublista de enteros
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "sub.h"
int main()
{
    //Encabezados
    TList *L=NULL;
    TList *auxL;
    int menu, submenu, nodoPadre;
    //Menú
    do{
        system("cls");
        printf("Ejemplo de Lista y Sublista de Enteros\n");
        printf(" 1.- Cargar Lista\n 2.- Cargar Sublista\n 3.- Mostrar Lista y Sublistas \n 4.- Eliminar Lista y Sublistas \n\n 0.- Salir\n");
        fflush(stdin); scanf("%d", &menu);
        switch(menu){
            case 1:
                do{
                    system("cls");
                    printf("Insertar en Lista principal\n");
                    insertOrdList(&L, newNodo(scanNodo()));
                    printf("\n1 para seguir cargando, otro para salir");
                     scanf("%d", &submenu);
                }while(submenu==1);
                break;
            case 2:
                do{
                    system("cls");
                    printf("Insertar en SubLista\nPor Favor elija el nodo padre");
                    fflush(stdin); scanf("%d", &nodoPadre);
                    auxL = L;
                    while(auxL!=NULL&&auxL->num!=nodoPadre){
                        auxL=auxL->sig;
                    }
                    if(auxL!=NULL){
                        do{
                            printf("\n");
                            insertOrdSub(&auxL->sub, newSubNodo(scanSubNodo()));
                            printf("\n1 para seguir cargar otro subnodo, otro para salir: ");
                             scanf("%d", &submenu);
                        }while(submenu==1);
                    }else{
                        printf("Nodo padre %d no encontrado", &nodoPadre);
                    }
                    printf("\n1 para seguir cargar subnodo en otro padre, otro para salir");
                    fflush(stdin); scanf("%d", &submenu);
                }while(submenu==1);
                break;
            case 3:
                system("cls");
                printf("Contenido de Lista y Sublistas\n");
                printListAndSub(L);
                system("pause");
                break;
            case 4:
                system("cls");
                printf("Eliminar Lista y Sublistas\n");
                delListAndSub(&L);
                printf("Listo\n");
                system("pause");
                break;
            default:
                break;
        }
    }while(menu!=0);
    return 0;
}
