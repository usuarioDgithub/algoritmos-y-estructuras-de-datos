#include<stdio.h>
#define N 4

void capturaMatriz(int[][N]);
int determinante(int[][N]);
void imrpimirMatriz(int[][N]);
int cofactor(mat)
int main(void){

    int mat[N][N];
    capturaMatriz(mat);
    printf("Matriz original    determinante: %d\n",determinante(mat));
    imprimirMatriz(mat);



getch(0);

}

void capturaMatriz(int mat[][N]){   //doble ciclo para capturar cada elemento de la matriz
     for(int i=0;i<N;i++)           //recorrer los renglones
         for(int j=0;j<N;j++){      //recorrer las columnas
        printf("\nCAPTURA [%d][%d]:",i,j);      //capturar cada elemento en su posicion i,j
        scanf("%d",&mat[i][j]);
    }
}

void imprimirMatriz(int mat[][N]){
     for(int i=0;i<N;i++){              //doble ciclo para recorrer toda la matriz e imprimir cada elemento
        printf("\n");
     for(int j=0;j<N;j++)
    printf("\t[%d]",mat[i][j]);
     }
}

int determinante(int mat[][N]){
        int det = 0.0;

        for (int j=0;j < N ; j++)
                det = det + mat[0][j] * cofactor(mat,N,0,j);
            return det;
}

int cofactor(int mat[][N]){
    int aux[N][N];
    int n = N-1;

    for(){
        for(){

        }
    }

//DETERMINANTE DE UNA MATRIZ DE CUALQUIER ORDEN EN C++ METODO DE COFACTORES
}
