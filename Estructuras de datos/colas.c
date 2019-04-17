#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Nodo{    //estructura Nodo que tiene un valor y un apuntador al siguiente nodo
    int dato;
    struct Nodo *siguiente;

};
typedef struct Nodo nodo;       //comando para definir el tipo de dato "nodo"

 void push(int valor,nodo **inicio,nodo **fin);
 int pop(nodo **inicio);
 void imprimircola(nodo *fin);

int main(void){

    nodo *inicio;
    nodo *fin;
    int valor;
    int opcion;

    inicio = NULL;
    fin = NULL;

do      //MENU DE OPCIONES
    {
        system("cls");      //borrar pantalla

        printf("MENU\n");

        printf("[1] Insertar a la cola un dato\n");
        printf("[2] Sacar dato de la cola \n");
        printf("[3] imprimir cola\n");
        printf("[5] salir\n");
        printf("opcion: ");

        scanf("%d",&opcion);

        switch (opcion)
        {
        case 1:
            system("cls");
            printf("Valor para insertar: ");
            scanf("%d",&valor);
            push(valor,&inicio,&fin);
            break;
        case 2:
            system("cls");

            printf("Se elimino [%d] el elemento de la cola\n\n",pop(&inicio));
            break;

        case 3:
            system("cls");
            imprimircola(inicio);
            break;
        case 5:
            printf("Saliendo...");
            break;
        default:
            printf("Opcion no valida\n");
            break;

        }
        printf("Presione cualquier tecla para continuar.");
        getch();

    }while(opcion!=5);


}

void push(int valor,nodo **inicio,nodo **fin)
{
    nodo *nodoNuevo;
    nodoNuevo = (nodo*)malloc(sizeof(nodo));
    nodoNuevo->dato=valor;
    nodoNuevo->siguiente=NULL;

    if((*inicio)==NULL)
    {
        (*inicio)=(*fin)=nodoNuevo;
        return;
    }
    else
    {
        (*fin)->siguiente=nodoNuevo;
        (*fin)=nodoNuevo;
    }

}

int pop(nodo **inicio)
{
    nodo *temp;
    int resultado;

    if((*inicio)==NULL)
    {
        printf("No hay Ningun valor en la cola.");
        return -1;
    }
    else
    {
        temp=(*inicio)->siguiente;
        resultado=(*inicio)->dato;
        free(*inicio);
        (*inicio)=temp;
        return resultado;
    }
}

void imprimircola(nodo *fin)
{
    nodo *auxiliar;     //se crea nodo auxiliar para no alterar el tope de cola

    auxiliar=fin;      //se iguala el nodod auxiliar a la cola enviada

    while(auxiliar!=NULL)       //mientras existan nodos entonces
    {
        printf("\n[%d]\n ",auxiliar->dato);    //imprime el valor del nodo
        auxiliar=auxiliar->siguiente;       //recorre la cola
    }
}
