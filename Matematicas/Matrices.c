#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int ma[100][100];


void coeficientes(int ecu, int inc);
void imprime_m(int ecu, int inc);
void pivote1(int n);
void main()
{
	int i=0,j=0,a=0,b=1,p=0,p1=0;
	int	ecuaciones=0,incognitas=0;
	int ma1[100],ma2[100];
	int m=0,n=0,s=0;

	printf("Numero de ecuaciones: ");
	scanf("%i",&ecuaciones);
	printf("Numero de incognitas: ");
	scanf("%i",&incognitas);
	coeficientes(ecuaciones,incognitas);
	imprime_m(ecuaciones,incognitas);


	i=1;
	for(p=1;p<=ecuaciones;p++)
	{
		if(ma[p][i]!=0)
		{
			p1=p;
			p=ecuaciones;
		}
		if(p==ecuaciones&&ma[p][i]==0)
		{
			printf("No existe solucion unica\n");
		}
	}
	if(p1!=i)
	{
		for(a=1;a<=(incognitas+1);a++)
		{
			ma1[a]=ma[p1][a];
			ma2[a]=ma[i][a];
		}
		for(a=1;a<=(incognitas+1);a++)
		{
			ma[p1][a]=ma2[a];
			ma[i][a]=ma1[a];
		}
		imprime_m(ecuaciones,incognitas);
	}
	j=i+1;
	for(i=1;i<=ecuaciones;i++)
	{
	ma1[i]=ma[j][i]/ma[i][i];
	a=1;
	for(j=i+1;j<(incognitas+2);j++)
	{
		m=ma[j][a];
		n=ma1[i];
		s=ma[i][a];
		s=n*m;
		n=s-m;
		//ma2[j][a]=ma[j][a]-(ma1[i]*ma[i][a]);
		a++;
	}
	j++;
	}
		if(ma[i][i]==0)
		{
			printf("No existe solucion unica");
		}
    //incognitas=(ma[i][i+1])/ma[i][i];
	imprime_m(ecuaciones,incognitas);

		system("pause");
	return;
}
void coeficientes(int ecu, int inc)
{
	int i=0,j=0,a=1,b=1;

	for(i=1;i<100;i++)
	{
		for(j=1;j<100;j++)
		{
			ma[i][j]=0;
		}
	}
	system("cls");
	for(i=1;i<(ecu+1);i++)
	{
		printf("\t\t---Ecuacion %i---\n",a);
		for(j=1;j<=(inc+1);j++)
		{
			if(j==(inc+1))
			{
				printf("Solucion del sistema: ");
				scanf("%i",&ma[i][j]);
			}
			else
			{
				printf("Valor del coeficiente de X%i: ",b);
				scanf("%i",&ma[i][j]);
				b++;
			}
		}
		a++;
		b=1;
	}
	return;
}
void imprime_m(int ecu, int inc)
{
	int i=0,j=0,a=1,b=1;

	for(i=1;i<=ecu;i++)
	{
		if(i==1)
			printf("\n");
		printf("  |");
		for(j=1;j<=(inc+1);j++)
		{
			printf("    %i",ma[i][j]);
		}
		printf("    |");
		printf("\n");
	}
	return;
}
