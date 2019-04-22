#include<stdio.h>
#include<stdlib.h>

 typedef struct Nodo {
    int dato;
    struct Nodo *der;
    struct Nodo *izq;
}Nodo;

void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo **arbol,int);
void mostrarArbol(Nodo *arbol,int );


Nodo *arbol = NULL;

int main(void)
{
    menu();


}
void menu()
{
    int dato,opcion;
    do{
        printf("MENU\n");
        printf("1. Insertar un nuevo nodo\n");
        printf("2. Salir\n");
        printf("Opcion: ");
        scanf("%d",&opcion);

        switch(opcion){
            case 1: printf("Numero a insertar: ");
                    scanf("%d",&dato);
                    insertarNodo(&arbol,dato);
                    printf("\n");
                    system("pause");
                    break;

        }
        system("cls");
    }while(opcion != 2);

}

Nodo *crearNodo(int n)
{
    Nodo *nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;

    return nuevo_nodo;
}

void insertarNodo(Nodo **arbol,int n)
{
    if((*arbol)==NULL) //Si arbol esta vacio creas un nuevo nodo (raiz)
    {
        Nodo *nuevo_nodo = crearNodo(n);
        (*arbol) = nuevo_nodo;
    }
    else    // si el arbol no esta vacio
    {
        int raiz = (*arbol) ->dato;  //valor de la raiz para comparar
        if(n < raiz) //si N es menor que raiz, se inserta en la izquierda
            insertarNodo((*arbol)->izq,n);

        else //Si n es mayor que la raiz entonces se inserta en la derecha
            insertarNodo((*arbol)->der,n);

    }
}

void mostrarArbol(Nodo *arbol,int cont)
{
    if(arbol==NULL)
        return;
    else
    {
        mostrarArbol(arbol->der,cont+1);
        for(int i=0;i<cont;i++)
            printf("\n");
        printf("%d",arbol->dato);
        mostrarArbol(arbol->izq,cont+1);
    }
}
