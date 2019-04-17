#include<stdio.h>
#include<stdlib.h>

int perros(int,int);
int gatos(int,int);

void main()
{
    int menu;
    int anios;
    int hembras;


    do
    {
    printf("\nElige una opcion\n");
    printf("\n 1)Perros");
    printf("\n 2)Gatos");
    printf("\nopcion: ");
    scanf("%d",&menu);

        switch(menu)
        {
        case 1:
            printf("\ncantidad de anios: ");
            scanf("%d",&anios);
            printf("\ncantidad de perros por hembra : ");
            scanf("%d",&hembras);

            printf("\nPerros:%d En %d años\n\n",perros(anios,hembras),anios);
            break;

        case 2:
            printf("\ncantidad de anios: ");
            scanf("%d",&anios);
            printf("\ncantidad de felinos por hembra : ");
            scanf("%d",&hembras);

            printf("gatos: %d",gatos(anios,hembras));
            break;

        default:
            printf("\nopcion no valida");
            break;
        }
    }while(menu!=3);

}

int perros(int anios,int perro)
{
    //Caso base
    if(anios==1)
        return perro;

    //Caso recursivo
    return perro + perro/2* perros(anios-1,perro);

}

int gatos(int anios,int gato)
{
    //Caso base
    if(anios==1)
        return gato;

    //Caso recursivo
    return gato + gato*.75 * gatos(anios-1,gato);
}
