#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
    int n,i,j,k,p;
    float a[5][5],b[5],x[5],factor,pivot,sum,large,temp;

    printf("Tamaño de matriz\n");
    scanf("%d",&n);

    printf("Coeficientes de matriz\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            printf("A[%d][%d] : ", i,j);
            scanf("%f",&a[i][j]);
        }


    printf("Anota los resultados de cada ecuacion \n");

    for(i=1;i<=n;i++)
    {
        printf("A[%d][%d] : ", i,4);
        scanf("%f",&b[i]);
    }


    for(k=1;k<=n-1;k++)
    {
        p=k;
        large=abs(a[k][k]);
        for(i=k+1;i<=n;i++)
        {
            if(abs(a[i][k])>large)
            {
                large=abs(a[i][k]);
                p=i;
            }
        }
        if(p!=k)
        {
            for(j=k;j<=n;j++)
            {
                temp=a[p][i];
                a[p][j]=a[k][j];
                a[k][j]=temp;
                temp=b[p];
                b[p]=b[k];
                b[k]=temp;
            }
        }
    }
    for(i=k+1;i<=n;i++)
    {
        factor=a[i][k]/a[k][k];
        for(j=1;j<=n;j++)
            a[i][j]=a[i][j]-factor*a[k][j];

        b[i]=b[i]-factor*b[k];
    }

        x[n]=b[n]/a[n][n];
        for(k=n-1;k>=1;k--)
        {
            sum=0.00;
            for(j=k+1;j<=n;j++)
                sum=sum+a[k][j]*x[j];
            x[k]=(b[k]-sum)/a[k][k];
        }
        printf("Los resultados son:\n");
        for(i=1;i<=n;i++)
          printf("%d.-%.2f\n",i,x[i]);

        system("pause");
          }
