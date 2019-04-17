#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Nodo{
    int dato;
    struct Nodo *siguiente;
};

typedef struct Nodo nodo;

nodo *crearPila(nodo *pila);
int pilaVacia(nodo *pila);
nodo *topePila(nodo *pila);
nodo *push(int dato,nodo *pila);
nodo *pop(nodo *pila);
void imprimirPila(nodo *pila);

int main(){

    nodo *pila;
    int opcion;
    int valor;

    pila=crearPila(pila);

    do
    {
        system("cls");

        printf("MENU\n");

        printf("[1] Insertar a la pila un dato\n");
        printf("[2] sacar dato de la pila \n");
        printf("[3] mostrar tope de pila\n");
        printf("[4] imprimir pila\n");
        printf("[5] salir\n");
        printf("opcion: ");

        scanf("%d",&opcion);

        switch (opcion)
        {
        case 1:
            system("cls");
            printf("Valor para insertar: ");
            scanf("%d",&valor);
            pila= push(valor,pila);

            break;
        case 2:
            system("cls");

            pila=pop(pila);

            printf("Se elimino el elemento del tope de pila\n\n");
            break;
        case 3:

            printf("El tope de la pila es: %d\n\n",topePila(pila)->dato);
            break;
        case 4:
            system("cls");
            imprimirPila(pila);
            break;
        case 5:
            printf("Saliendo...");
            break;

        }
        printf("Presione cualquier tecla para continuar.");
        getch();

    }while(opcion!=5);

return 0;
}


nodo *crearPila(nodo *pila){
return pila=NULL;
}

int pilaVacia(nodo *pila){
if (pila == NULL)
    return 1;

return 0;
}
nodo *topePila(nodo *pila){
return pila;

}

nodo *push(int valor, nodo *pila){

    nodo *nodoNuevo;

    nodoNuevo = (nodo*)malloc(sizeof(nodo));

    if (nodoNuevo!=NULL)
    {
        nodoNuevo->dato=valor;
        nodoNuevo->siguiente=pila;
        pila=nodoNuevo;
    }

    return pila;
}

nodo *pop(nodo *pila)
{
    nodo *auxiliar;

    if(!pilaVacia(pila))
    {
        auxiliar=pila;
        pila=pila->siguiente;
        free(auxiliar);
    }

    return pila;
}


void imprimirPila(nodo *pila)
{
    nodo *auxiliar;

    auxiliar=pila;

    printf("PILA \n");

    while(auxiliar!=NULL)
    {
        printf("[%d]\n",auxiliar->dato);
        auxiliar=auxiliar->siguiente;
    }

}
