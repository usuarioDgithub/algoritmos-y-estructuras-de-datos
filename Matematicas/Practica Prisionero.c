#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct Prisioneros {
    char nombre[15];
    struct Prisioneros * siguiente;

}Prisionero;

void agregarPrisionero(Prisionero **inicio,Prisionero **fin,char *nombre);
void ejecutarPrisioneros(Prisionero **fin,Prisionero **inicio,int k);


int main(void)
{
    Prisionero *inicio,*fin;
    inicio=NULL;
    fin=NULL;
    char *aux;
    int menu;



    while(menu!=2)          //menu donde se sale despues de ejecutar al prisionero
 {
     system("cls");
    printf("1) Agregar Prisionero\n");
    printf("2) Ejecutar Prisionero\n");
     scanf("%d",&menu);

     if(1==menu)                //agregar prisionero al presionar 1
     {
         system("cls");
         printf("\nNombre del Prisionero:  ");
         scanf("%s",aux);
        agregarPrisionero(&inicio,&fin,aux);
     }
     else if(2==menu)           // ejecutar a los prisioneros si se presiona 2
     {
         int k;
         printf("Digite el numero 'K' para la ejecucion");
         scanf("%d",&k);
         ejecutarPrisioneros(&inicio,&fin,k);
         getch();

     }


 }



}

void agregarPrisionero(Prisionero **inicio,Prisionero **fin ,char *n)
{
    Prisionero *auxiliar;
    auxiliar = (Prisionero*)malloc(sizeof(Prisionero));
    strcpy(auxiliar->nombre,n);
    auxiliar->siguiente=NULL;

    if(inicio==NULL)
    {
    (*inicio)=(*fin)=auxiliar;
    return;
    }
    (*fin)->siguiente=auxiliar;
    (*fin)=auxiliar;
    return;
}


void ejecutarPrisioneros(Prisionero **fin,Prisionero **inicio,int k)
{
    if((*inicio)==NULL)         //Si no hay prisioneros en la lista, se acaba el proceso.
        return;
    if((*inicio)->siguiente==NULL)   //Si siguiente de inicio es NULL, significa nomas hay 1 prisionero, y seria el unico en salvarse
    printf("El Sobreviviente que sobrevivio fue nada mas y nada menos que %s",(*inicio)->nombre);

    int i;
    Prisionero *aux;
    aux = (Prisionero*)malloc(sizeof(Prisionero));

    while((*inicio)==(*fin))   //se repitira el ciclo del verdugo hasta que quede solo 1 sobreviviente, es decir inicio y final apunten donde mismo
    {
        while(k-1>i)    //repite k-1 veces el proceso de mover prisioneros
        {
            (*inicio)=aux;                  //se guarda la variable de inicio
            free(*inicio);                  //se libera el inicio de la cola
            (*inicio)=aux->siguiente;       //el nuevo inicio sera el siguiente a inicio (para eso se guarda en aux)
            aux->siguiente=NULL;            //el siguiente de aux, se hace null para ponerlo al final de la lista
            (*fin)->siguiente=aux;         //se agrega el valor que estaba en inicio hacia el final
            (*fin)=aux;                     // el nuevo valor agregado es el nuevo final
            i++;
        }
        printf("El prisionero %s ha muerto tragicamente por el verdugo: \n",(*inicio)->nombre);

    }

    printf("El Sobreviviente que sobrevivio fue nada mas y nada menos que %s",(*inicio)->nombre);

}

