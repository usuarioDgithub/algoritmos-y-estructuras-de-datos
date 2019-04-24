#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

 typedef struct Nodo {
    int dato;
    struct Nodo *der;
    struct Nodo *izq;
    struct Nodo *padre;
}Nodo;

void menu();
Nodo *crearNodo(int,Nodo *);
void insertarNodo(Nodo **arbol,int n,Nodo *padre);
void mostrarArbol(Nodo *arbol,int cont);
bool busquedaNodo(Nodo *arbol,int n);
void preOrden(Nodo *arbol);
void inOrden(Nodo *arbol);
void posOrden(Nodo *arbol);
void preEliminacion(Nodo *arbol,int n);
void eliminarNodo(Nodo *arbol);
Nodo *minimo(Nodo *arbol);
void remplazarNodo(Nodo *arbol,Nodo *nuevo);
void destruirNodo(Nodo *arbol);

Nodo *arbol = NULL;

int main(void)
{

    menu();


}
void menu()
{
    int dato;
    int opcion;
    int contador=0;
    do
        {
        printf("MENU\n");
        printf("1. Insertar un nuevo nodo\n");
        printf("2. Mostrar Arbol\n");
        printf("3. Buscar nodo en el arbol\n");
        printf("4. Recorrer Arbol Pre-Orden\n");
        printf("5. Recorrer Arbol In-Orden\n");
        printf("6. Recorrer Arbol Post-Orden\n");
        printf("7. Eliminar Nodo\n");
        printf("8. Salir\n");
        printf("Opcion: ");
        scanf("%d",&opcion);

        switch(opcion){
            case 1: printf("Numero a insertar: ");
                    scanf("%d",&dato);
                    insertarNodo(&arbol,dato,NULL);
                    printf("\n");

                    break;
            case 2: printf("Mostrar el arbol\n\n");
                    mostrarArbol(arbol,contador);
                    printf("\n");
                    system("pause");
                    break;
            case 3: printf("Busqueda de nodo en el arbol \n\n");
                    printf("Valor a buscar: ");
                    scanf("%d",&dato);
                    if(busquedaNodo(arbol,dato))
                        printf("\n[%d] se ha encontrado en el arbol \n",dato);
                    else
                        printf("No se ha encontrado en el arbol\n");

                    system("pause");
                    break;

            case 4: printf("\nArbol en PRE ORDEN\n");
                    preOrden(arbol);
                    system("pause");
                    break;

             case 5: printf("\nArbol en IN ORDEN\n");
                    inOrden(arbol);
                    system("pause");
                    break;

             case 6: printf("\nArbol en POST ORDEN\n");
                    posOrden(arbol);
                    system("pause");
                    break;
            case 7: printf("\n Nodo a eliminar: ");
                    scanf("%d",&dato);
                    preEliminacion(arbol,dato);
                    system("pause");
                    break;

            default: printf("\nOpcion no valida \n");
                    break;
        }
        system("cls");
    }while(opcion!=8);

}

Nodo *crearNodo(int n,Nodo *padre)
{
    Nodo *nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->padre = padre;

    return nuevo_nodo;
}

void insertarNodo(Nodo **arbol,int n,Nodo *padre)
{
    if((*arbol)==NULL) //Si arbol esta vacio creas un nuevo nodo (raiz)
    {
        Nodo *nuevo_nodo = crearNodo(n,padre);
        (*arbol) = nuevo_nodo;
    }
    else    // si el arbol no esta vacio
    {
        int raiz = (*arbol) ->dato;  //valor de la raiz para comparar
        if(n < raiz) //si N es menor que raiz, se inserta en la izquierda
            insertarNodo(&(*arbol)->izq,n,*arbol);

        else //Si n es mayor que la raiz entonces se inserta en la derecha
            insertarNodo(&(*arbol)->der,n,*arbol);

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
            printf("   ");
        printf("%d\n",arbol->dato);
        mostrarArbol(arbol->izq,cont+1);
    }
}

bool busquedaNodo(Nodo *arbol,int n)
{
    if(arbol==NULL)     //Si arbol esta vacio regresas falso
        return false;
    else if(arbol->dato == n)   //Regresa TRUE si se encuentra 'n' en el arbol
        return true;
    else if(n <arbol->dato)     //Si n es mas chico que la raiz, busca por la izquierda
        return busquedaNodo(arbol->izq,n);
    else                        //Si n es mas grande que la raiz, se busca por la derecha
        return busquedaNodo(arbol->der,n);
}

void preOrden(Nodo *arbol)
{
    if(arbol==NULL) //Si el arbol esta vacio, retornar
        return;
    else{
        printf("%d-",arbol->dato);
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}


void inOrden(Nodo *arbol)
{
    if(arbol == NULL) //si arbol esta vacio
        return;
    else{
        inOrden(arbol->izq);  //imprime el lado izquierdo
        printf("%d - ",arbol->dato); //imprime la raiz
        inOrden(arbol->der); //imprime la parte de la derecha

    }
}

void posOrden(Nodo *arbol)
{
    if(arbol==NULL) //si arbol esta vacio
        return;
    else
    {
        posOrden(arbol->izq); //imprime desde la izquierda
        posOrden(arbol->der); //imprime desde la derecha
        printf("%d- ",arbol->dato); //imprime la raiz
    }

}

void preEliminacion(Nodo *arbol,int n)
{
    if(arbol==NULL) //Si arbol esta vacio return
        return;
    else if(n < arbol->dato)    //Buscar por izquierda si es menor
        preEliminacion(arbol->izq,n);
    else if(n > arbol->dato)    //Buscar por derecha si es menor
        preEliminacion(arbol->der,n);
    else
        eliminarNodo(arbol);
}

void eliminarNodo(Nodo *nodo_eliminado)
{
    if(nodo_eliminado->izq && nodo_eliminado->der) //nodo con 2 hijos
    {
        Nodo *menor = minimo(nodo_eliminado->der); //encontrar el nodo mas a la izq posible
        nodo_eliminado->dato = menor->dato;  //intercambiar el valor de los nodos
        eliminarNodo(menor); //eliminar el nodo menor en su vieja posicion
    }
    else if(nodo_eliminado->izq) //si el arbol tiene solo nodo izquierdo
    {
        remplazarNodo(nodo_eliminado,nodo_eliminado->izq);
        destruirNodo(nodo_eliminado);
    }
    else if(nodo_eliminado,nodo_eliminado->der)
    {
        remplazarNodo(nodo_eliminado,nodo_eliminado->der);
        destruirNodo(nodo_eliminado);

    }
    else
    {//Nodo sin hijos (nodo hoja)
        remplazarNodo(nodo_eliminado,NULL); //remplazar nodo hoja por NULL
        destruirNodo(nodo_eliminado);       //liberar espacio
    }
}

void remplazarNodo(Nodo *arbol, Nodo * nuevo)
{
    if(arbol->padre) //asignar nuevo hijo
    {
        if(arbol->dato == arbol->padre->izq->dato) //verificar que
            arbol->padre->izq = nuevo;
        else if(arbol->dato == arbol->padre->der->dato)
            arbol->padre->der = nuevo;
    }
    if(nuevo) //acceder nuevo padre
        nuevo->padre = arbol->padre;
}

Nodo *minimo(Nodo *arbol)
{
    if(arbol==NULL) //si esta vacio return NULL
        return NULL;
    if(arbol->izq)  //Si tiene hijo izq, seguir a la izquierda
        return minimo(arbol->izq);
    else            //sino tiene hijo izq retornar el nodo actual
        return arbol;
}
void destruirNodo(Nodo *nodo) //Vaciar los enlaces a otros nodos
{
    nodo->der==NULL;
    nodo->izq==NULL;
    free(nodo);  //liberar memoria del nodo
}
