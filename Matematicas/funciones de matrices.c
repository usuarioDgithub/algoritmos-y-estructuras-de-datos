#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void coeficientes(float ma[][100],int ecu, int inc);
void imprime_m(float ma[][100],int ecu, int inc);
void gauss(float ma[][100],int ecu,int inc);
void gaussSeidel(float ma[][100],int ecu,int inc);
void jacobi(float ma[][100],int ecu);
void pivoteMax(float a[][100],int ecu,int inc);
void main()
{

    float ma[100][100];
	int i=0,j=0,a=1,b=1,p=0,p1=0;
	int	ecuaciones=0,incognitas=0;
	int ma1[100],ma2[100];
	int m=0,n=0,s=0;
	int menu;

	printf("Numero de ecuaciones: ");
	scanf("%i",&ecuaciones);
	printf("Numero de incognitas: ");
	scanf("%i",&incognitas);

	system("cls");
	for(i=1;i<(ecuaciones+1);i++)
	{
		printf("\t\t---Ecuacion %i---\n",a);
		for(j=1;j<=(incognitas+1);j++)
		{
			if(j==(incognitas+1))
			{
				printf("Solucion del sistema: ");
				scanf("%f",&ma[i][j]);
			}
			else
			{
				printf("Valor del coeficiente de X%i: ",b);
				scanf("%f",&ma[i][j]);
				b++;
			}
		}
		a++;
		b=1;
	}


	do
    {

        printf("\n\nMENU DE OPCIONES\n\n");

        printf("1) Imprimir Matriz\n");
        printf("2) Eliminacion Gaussiana con sustitucion hacia atras\n");
        printf("3) Metodo Iterativo Gauss Seidel\n");
        printf("4) Metodo Escalonado de Jacobi\n");
        printf("5) Metodo Pivotus maximus\n");
        printf("6) Salir\n");
        printf("Opcion: ");
        scanf("%d",&menu);
        switch(menu)
        {
            case 3: system("cls");
                    gaussSeidel(ma,ecuaciones,incognitas);
                    break;
            case 2: system("cls");
                    gauss(ma,ecuaciones,incognitas);
                    break;
            case 1: system("cls");
                    imprime_m(ma,ecuaciones,incognitas);
                    break;
            case 4: system("cls");
                    jacobi(ma,ecuaciones);
                    break;
            case 5: system("cls");
                    pivoteMax(ma,ecuaciones,incognitas);
                    break;
            case 6:
                    printf("\n\nSaliendo...");
                    break;
            default:
                    printf("\nOpcion no valida.");
                    break;
        }
    }while(menu!=6);

		system("pause");
	return;
}

void imprime_m(float ma[][100],int ecu, int inc)
{
	int i,j,a=1,b=1;

    printf("\n\n----------------------------\n");
    for(i=1;i<=ecu;i++)
    {
        printf("\n");
        for(j=1;j<=inc+1;j++)
        {
            printf("  [%.2f]  ",ma[i][j]);
            if(j==inc)
            printf(" |");
        }
    }
    printf("\n\n------------------------------\n");

	return;
}

void gauss(float ma[][100],int ecu,int inc)
{
    int i,j,k,n;
    float aux[100][100];
    float c,x[10],sum=0.0;

    printf("\nEliminacion Gaussiana con sustitucion hacia atras\n");

    if(ecu!=inc)
    {
        printf("\nNo se puede aplicar el metodo de Gauss al reves sino es una Matriz NxN\n");
        system("pause");
        return;
    }

    n=ecu;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n+1;j++)
            aux[i][j]=ma[i][j];
    }
    imprime_m(aux,ecu,inc);

    for(j=1; j<=n; j++) /* Crear matriz Triangular*/
    {
        for(i=1; i<=n; i++)
        {
            if(i>j)
            {
                c=aux[i][j]/aux[j][j];
                for(k=1; k<=n+1; k++)
                {
                    aux[i][k]=aux[i][k]-c*aux[j][k];
                    imprime_m(aux,ecu,inc);
                }


            }

        }
    }

    x[n]=aux[n][n+1]/aux[n][n];
    /* Regreseion de g*/
    for(i=n-1; i>=1; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
            sum=sum+aux[i][j]*x[j];

        x[i]=(aux[i][n+1]-sum)/aux[i][i];
    }

    printf("\nLa solucion es: \n");
    for(i=1; i<=n; i++)
        printf("\nx%d=%f\t",i,x[i]); /* x1, x2, x3 are the required solutions*/

        imprime_m(aux,ecu,inc);

        system("pause");


}

void gaussSeidel(float ma[][100],int ecu,int inc)
{
    printf("\n\nMetodo Por Gauss-Seidel\n\n");

      float aux[ecu][inc+1];
      int i, j;

      float temp, error, a, sum = 0;
      float  y[10], error_permitido;
      printf("Error Permitido (ej:0.0005%):\t");
      scanf("%f", &error_permitido);

      for(i=1; i<=ecu; i++)
        for(j=1; j<=inc+1;j++)
            aux[i][j]=ma[i][j];

      for(i = 1; i <= ecu; i++)
            y[i] = 0;

      do
      {
        a = 0;
            for(i = 1; i <= ecu; i++)
            {
                  sum = 0;
                  for(j = 1; j <= ecu; j++)
                  {
                        if(j != i)
                              sum = sum + aux[i][j] * y[j];

                  }
                  temp = (aux[i][ecu + 1] - sum) / aux[i][i];
                  error = fabs(y[i] - temp);
                  if(error > a)
                  {
                        a = error;
                  }
                  y[i] = temp;
                  printf("\nY[%d]=\t%f", i, y[i]);
            }
            printf("\n");
      }while(a >= error_permitido);

      printf("\n\nSolucion:\n\n");
      for(i = 1; i <= ecu; i++)
            printf("\nY[%d]:\t%f", i, y[i]);

}

void jacobi(float ma[][100],int ecu)
{
    float aux[100][100];

    int i,j;
    //entrada
   float XO[100], sum;
   float tol = 0.000001;
   int iter = 100;
   int k = 1;
   int parar = 0;
   //salida
   float x[100];

    for(i=1; i<=ecu; i++)
        for(j=1; j<=ecu+1;j++)
            aux[i][j]=ma[i][j];

    for(i=1;i<ecu+1;i++)XO[i] = 0;

    do{
        printf("\n\niteracion %d",k);
        for(i=1; i<ecu+1; i++)
        printf("\nx%d=%f\t",i,x[i]);

        for(i=1;i<=ecu;i++){
                sum = 0;
            for(j=1;j<=ecu;j++){
                if(i!=j)
                sum+=(aux[i][j]*XO[j]);
            }
            x[i] = (aux[i][ecu+1]-sum)/aux[i][i];

            if(fabs(x[i]- XO[i])<tol)parar=1;
        }

       k++;
       for(i=1;i<=ecu;i++)XO[i] = x[i];
    }while(k<=iter && parar==0);
    printf("\n\Resultado",k);
    for(i=1; i<ecu+1; i++)
        printf("\nx%d=%f\t",i,x[i]);

       system("pause");
}
void pivoteMax(float ma[][100],int ecu,int inc)
{
    float aux[100][100];
    int i,j,k,p,n;
    n=ecu;
    float b[100],x[100],factor,pivot,sum,largo,temp;

    for(i=1; i<=n; i++)
        for(j=1; j<=n+1;j++)
            aux[i][j]=ma[i][j];
    for(i=1;i<=n;i++)b[i]=aux[i][n+1];


    printf("Haciendo eliminacion....................\n");
for(k=1;k<=n-1;k++)
{
                 p=k;
                 largo=abs(aux[k][k]);
                 for(i=k+1;i<=n;i++)
                 {
                 if(abs(aux[i][k])>largo)
                                {
                                largo=abs(aux[i][k]);
                                p=i;
                                }
                 }
                 if(p!=k)
                 {
                                for(j=k;j<=n;j++)
                                {
                                temp=aux[p][i];
                                aux[p][j]=aux[k][j];
                                aux[k][j]=temp;
                                temp=b[p];
                                b[p]=b[k];
                                b[k]=temp;
                                imprime_m(aux,n,n);
                                }
                 }

                for(i=k+1;i<=n;i++)
                {
                factor=aux[i][k]/aux[k][k];
                                for(j=1;j<=n;j++)
                                {
                                aux[i][j]=aux[i][j]-factor*aux[k][j];
                                imprime_m(aux,n,n);
                                }
                b[i]=b[i]-factor*b[k];
                }
}

      x[n]=b[n]/aux[n][n];
      for(k=n-1;k>=1;k--)
      {
      sum=0.00;
      for(j=k+1;j<=n;j++)
      {
      sum=sum+aux[k][j]*x[j];
      }
      x[k]=(b[k]-sum)/aux[k][k];

      }
      printf("Los resultados son:\n");
      for(i=1;i<=n;i++)
      printf("%d.- %.2f\n",i,x[i]);

      system("pause");
      }

