#include<stdio.h>
#include<stdlib.h>

int sumatoria(int n);
int sumatoriaPares(int n);
void binario(int n);
int MCD(int n,int m);

void main(){

int n=6;
printf("la sumatoria de N=%d es :%d\n",n,sumatoria(n));
printf("la sumatoria de pares N=%d es :%d\n",n,sumatoriaPares(n));
printf("N(decimal) = %d    N(binario)=");
binario(n);

printf("\nEl MCD de %d y %d es: %d",40,60,MCD(40,60));
}

int sumatoria(int n)
{
    //Caso base:Regresa 1 cuando N sea 1
    if(n==1)
        return 1;

    //Caso recursivo regresa N + sumatoria hasta n-1
    return n + sumatoria(n-1);
}

int sumatoriaPares(int n)
{
    //valida que sea un numero par
    if(n%2!=0)  
    {
        printf("\nNo es un numero primo\n");
        return 0;
    }
    //caso base: cuando N sea 2 regresa 2
    if(n==2)
        return 2;
    //caso recursivo regresa el numero par N +
    return n + sumatoriaPares(n-2);

}

void binario(int n)
{
    //salida: cuando n ya sea 0 o menos
    if(n<1)   
        return;
    //casos base
    if(n%2==0)  //si el residuo de N/2 es 0, se imprime un 0
        printf("0");

    else        // el residuo de N/2 es distinto, se imprime 1
        printf("1");

    //caso recursivo: se divide N/2 para saber si apuntar 0 o 1
    binario(n/2);

}

int MCD(int n,int m)
{
    //para validar que el numero mayor sea el primer parametro
    if(n<m)
        return MCD(m,n);
    //caso base cuando el numero mas chico sea 0 entonces regresas n
    else if(m == 0)
        return n;
    //caso recursivo regresa el mas chico y el residuo del mas grande sobre el mas chico.
    else
        return MCD(m,n%m);
}

