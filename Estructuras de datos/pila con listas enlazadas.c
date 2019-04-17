#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int dato;
    struct nodo* next;

}Nodo;

Nodo *primer = NULL;
Nodo *ultimo = NULL;

void agregar(Nodo *nodo){
    nodo->next=NULL;

    if(primer==NULL){
        primer = nodo;
        ultimo = nodo;
    }
        else{
            ultimo->next = nodo;
            ultimo = nodo;
        }
}


int main(void){

    Nodo *primerNodo = malloc(sizeof(Nodo));
    primerNodo->dato = 5;

    Nodo *segundoNodo = malloc(sizeof(Nodo));
    segundoNodo->dato = 7;

    agregar(primerNodo);
    agregar(segundoNodo);

    Nodo *i = primerNodo;
    while(i != NULL){
        printf("%i\n",i->dato);
        i = i->next;
    }

    int opcion;

    while(opcion!=5){

    scanf("%d",&opcion);
    switch(opcion){
        case 1:push();
                break;

        case 2:pop();
                break;

        case 5: printf("Saliendo...");
                break;

        default:printf("Opcion invalida, porfavor repetir");
                break;

    }

    }

    Nodo crearNodo(Nodo *pila,int valor){

       Nodo *nodo = pila


    }


}
