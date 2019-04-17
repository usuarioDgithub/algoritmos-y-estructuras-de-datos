#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Nodo{    //estructura Nodo que tiene un valor y un apuntador al siguiente nodo
    int dato;
    struct Nodo *siguiente;

};
typedef struct Nodo nodo;       //comando para definir el tipo de dato "nodo"

//Prototipos de funcion

nodo *crearcola(nodo *cola);
int colaVacia(nodo *cola);
nodo *topecola(nodo *cola);
nodo *push(int dato,nodo *cola,nodo *inicio);
int pop(nodo *cola,nodo *inicio);
void imprimircola(nodo *cola);

int main(){

    nodo *cola;     //declarar un apuntador a nodo
    nodo *inicio;
    int opcion;     //variable para interactuar con el menu
    int valor;      //variable para la funcion push donde se agrega un valor

    //cola=crearcola(cola); //iniciar la cola apuntando a 0, es decir una cola vacia
    //inicio=crearcola(inicio);

    do      //MENU DE OPCIONES
    {
        system("cls");      //borrar pantalla

        printf("MENU\n");

        printf("[1] Insertar a la cola un dato\n");
        printf("[2] sacar dato de la cola \n");
        printf("[3] mostrar tope de cola\n");
        printf("[4] imprimir cola\n");
        printf("[5] salir\n");
        printf("opcion: ");

        scanf("%d",&opcion);

        switch (opcion)
        {
        case 1:
            system("cls");
            printf("Valor para insertar: ");
            scanf("%d",&valor);
            cola= push(valor,cola,inicio);

            break;
        case 2:
            system("cls");

            printf("Se elimino [%d] el elemento de la cola\n\n",pop(cola,inicio));
            break;
        case 3:

            printf("El tope de la cola es: %d\n\n",topecola(cola)->dato);
            break;
        case 4:
            system("cls");
            imprimircola(inicio);
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


nodo *crearcola(nodo *cola){
return cola=NULL;        //para crear una cola se iguala el nodo a null
}

int colaVacia(nodo *cola)
{
    if (cola == NULL)       //si un apuntador de estructura es igual a null
    return 1;       //singifica que no hay ningun elemento, y que la cola esta vacia

    return 0;       //regresar 0 en caso de que la cola NO este vacia
}

nodo *topecola(nodo *cola)
{
    return cola;

}

nodo *push(int valor, nodo *cola,nodo *inicio){

    nodo *nodoNuevo;        //crear apuntador a nodo auxiliar

    nodoNuevo = (nodo*)malloc(sizeof(nodo)); //darle tamaño especifico a nodo

    nodoNuevo->dato = valor;


    if (1==colaVacia(cola))  //si se creo el nodo correctamente entonces
    {
        /*
        nodoNuevo->dato=valor;      //asignar el valor del parametro al nodo nuevo
        cola->siguiente=nodoNuevo;  //el nodo apunta al tope de cola anterior
        cola=nodoNuevo;             //el nuevo tope de cola es el nuevo nodo creado
        inicio = nodoNuevo;

*/
        inicio=cola=nodoNuevo;
    }
    else{
            /*
        nodoNuevo->dato=valor;      //asignar el valor del parametro al nodo nuevo
        nodoNuevo->siguiente=cola;  //el nodo apunta al tope de cola anterior
        cola=nodoNuevo;             //el nuevo tope de cola es el nuevo nodo creado
        */
        cola->siguiente=nodoNuevo;
        cola=nodoNuevo;
    }

    return cola;            //regresar la cola
}

int pop(nodo *cola,nodo *inicio)       //funcion para sacar elemento de la cola
{
    nodo *auxiliar;
    auxiliar = (nodo*)malloc(sizeof(nodo));
    int rest=-1;

    if(0==colaVacia(cola))
    {
        auxiliar=inicio->siguiente;
        rest=inicio->dato;
        free(inicio);
        inicio=auxiliar;
        /*
        auxiliar=inicio;
        rest=auxiliar->dato;
        inicio=inicio->siguiente;
        free(auxiliar);
        */
    }
    return rest;
}


void imprimircola(nodo *cola)
{
    nodo *auxiliar;     //se crea nodo auxiliar para no alterar el tope de cola

    auxiliar=cola;      //se iguala el nodod auxiliar a la cola enviada

    printf("cola  %d\n",cuenta);

    while(auxiliar!=NULL)       //mientras existan nodos entonces
    {
        printf("\n[%d]\n ",auxiliar->dato);    //imprime el valor del nodo
        auxiliar=auxiliar->siguiente;       //recorre la cola
    }
}
