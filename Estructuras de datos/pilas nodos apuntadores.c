#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Nodo{    //estructura Nodo que tiene un valor y un apuntador al siguiente nodo
    int dato;
    struct Nodo *siguiente;
};

typedef struct Nodo nodo;       //comando para definir el tipo de dato "nodo"

//Prototipos de funcion

nodo *crearPila(nodo *pila);
int pilaVacia(nodo *pila);
nodo *topePila(nodo *pila);
nodo *push(int dato,nodo *pila);
nodo *pop(nodo *pila);
void imprimirPila(nodo *pila);

int main(){

    nodo *pila;     //declarar un apuntador a nodo
    int opcion;     //variable para interactuar con el menu
    int valor;      //variable para la funcion push donde se agrega un valor

    pila=crearPila(pila); //iniciar la pila apuntando a 0, es decir una pila vacia

    do      //MENU DE OPCIONES
    {
        system("cls");      //borrar pantalla

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
return pila=NULL;        //para crear una pila se iguala el nodo a null
}

int pilaVacia(nodo *pila)
{
    if (pila == NULL)       //si un apuntador de estructura es igual a null
    return 1;       //singifica que no hay ningun elemento, y que la pila esta vacia

    return 0;       //regresar 0 en caso de que la pila NO este vacia
}

nodo *topePila(nodo *pila)
{
    return pila;

}

nodo *push(int valor, nodo *pila){

    nodo *nodoNuevo;        //crear apuntador a nodo auxiliar

    nodoNuevo = (nodo*)malloc(sizeof(nodo)); //darle tamaño especifico a nodo

    if (nodoNuevo!=NULL)  //si se creo el nodo correctamente entonces
    {
        nodoNuevo->dato=valor;      //asignar el valor del parametro al nodo nuevo
        nodoNuevo->siguiente=pila;  //el nodo apunta al tope de pila anterior
        pila=nodoNuevo;             //el nuevo tope de pila es el nuevo nodo creado
    }

    return pila;            //regresar la pila
}

nodo *pop(nodo *pila)       //funcion para sacar elemento de la pila
{
    nodo *auxiliar;         //nodo auxiliar

    if(!pilaVacia(pila))    //si la pila NO esta vacia entonces:
    {
        auxiliar=pila;           //guardar la pila actual en el nodo auxiliar
        pila=pila->siguiente;   //el nuevo tope de pila sera el nodo que estaba en siguiente
        free(auxiliar);         //liberar la memoria que apuntaba el tope de pila anterior
    }

    return pila;                //regresar la pila
}


void imprimirPila(nodo *pila)
{
    nodo *auxiliar;     //se crea nodo auxiliar para no alterar el tope de pila

    auxiliar=pila;      //se iguala el nodod auxiliar a la pila enviada

    printf("PILA \n");

    while(auxiliar!=NULL)       //mientras existan nodos entonces
    {
        printf("[%d]\n",auxiliar->dato);    //imprime el valor del nodo
        auxiliar=auxiliar->siguiente;       //recorre la pila
    }

}
