#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo{
    int dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;

}Nodo;

void push(Nodo **fin,int valor);
int pop(Nodo **fin);
void imprimirLista(Nodo *fin);
int topePila(Nodo *fin);
int length(Nodo *fin);

int main (void)
{
    Nodo *inicio=NULL;
    Nodo *fin=NULL;
    int valor;
    int opcion;

                    while(opcion!=6)
                    {
                        system("cls");
                        printf("---MENU DE OPCIONES DE PILA ---\n\n");
                        printf("Opcion [1]: PUSH \n");
                        printf("Opcion [2]: POP\n");
                        printf("Opcion [3]: IMPRIMIR \n");
                        printf("Opcion [4]: MOSTRAR TOPE DE PILA\n");
                        printf("Opcion [5]: SIZE \n");
                        printf("Opcion [6]: SALIDA\n");
                        printf("Opcion: ");
                        scanf("%d",&opcion);

                        switch(opcion)
                        {

                        case 1:

                            system("cls");
                            printf("\n Digite valor para meter a la Pila: ");
                            scanf("%d",&valor);
                            push(&fin,valor);
                            break;

                        case 2:

                              system("cls");
                              printf("\n[%d] Salio de la pila.\n",pop(&fin));
                              break;

                        case 3:

                            system("cls");
                            imprimirLista(fin);
                            break;

                        case 4:

                            system("cls");
                            printf("\nEl tope de lista es [%d]",topePila(fin));
                            break;

                        case 5:

                            system("cls");
                            printf("\nEl tamanio de la lista es %d",length(fin));
                            break;

                        case 6:

                            printf("\n\n Saliendo....");
                            break;

                        default:

                            system("cls");
                            printf("\nOpcion No valida");
                            break;
                        }
                        getch();

                    }

}

void push(Nodo **fin,int valor )
{
    Nodo *aux;
    aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato=valor;
    aux->siguiente=NULL;
    aux->anterior=NULL;

    if((*fin)==NULL)
    {
        (*fin)=aux;
        printf("Primer valor de la pila [%d]\n",(*fin)->dato);
        return;
    }
    else
    {
        aux->anterior =(*fin);
        (*fin)->siguiente = aux;
        (*fin)=aux;
        printf("Se inserto [%d]\n",(*fin)->dato);
    }
}

int pop(Nodo **fin)
{
    if((*fin)==NULL)
    {
        printf("La pila esta vacia");
         return -1;
    }

    int valor = (*fin)->dato;


    Nodo *aux;

    aux=(*fin);
    free((*fin));
    (*fin)=aux->anterior;

    return valor;
}

void imprimirLista(Nodo *lista)
{
    Nodo *aux;

    aux=lista;
    int i=0;

    printf("indice\tValor\n\n");
    while(aux!=NULL)
    {
        printf("%d\t[%d]\n",100-i,aux->dato);
        aux=aux->anterior;
        i++;
    }
}

int topePila(Nodo *fin)
{
    if(fin==NULL)
    {
        printf("\nLa pila esta vacia.");
        return -1;
    }
    return fin->dato;
}

int length(Nodo *lista)
{
     Nodo *aux;
     int tamano=0;
    aux=lista;

    while(aux!=NULL)
    {
        tamano++;
        aux=aux->anterior;
    }
    return tamano;
}
