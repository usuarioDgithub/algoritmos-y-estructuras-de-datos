#include<stdio.h>
#include<math.h>

int main()
{
      int count, t, limit;
      float temp, error, a, sum = 0;
      float matrix[10][10], y[10], allowed_error;
      printf("\nNumero De Ecuaciones:\t");
      scanf("%d", &limit);
      printf("Error Permitido (ej:0.0005%):\t");
      scanf("%f", &allowed_error);
      printf("\nPonga los coeficientes \n");
      for(count = 1; count <= limit; count++)
      {
            for(t = 1; t <= limit + 1; t++)
            {
                  printf("Matriz[%d][%d] = ", count, t);
                  scanf("%f", &matrix[count][t]);
            }
      }
      for(count = 1; count <= limit; count++)
      {
            y[count] = 0;
      }
      do
      {
            a = 0;
            for(count = 1; count <= limit; count++)
            {
                  sum = 0;
                  for(t = 1; t <= limit; t++)
                  {
                        if(t != count)
                        {
                              sum = sum + matrix[count][t] * y[t];
                        }
                  }
                  temp = (matrix[count][limit + 1] - sum) / matrix[count][count];
                  error = fabs(y[count] - temp);
                  if(error > a)
                  {
                        a = error;
                  }
                  y[count] = temp;
                  printf("\nY[%d]=\t%f", count, y[count]);
            }
            printf("\n");
      }
      while(a >= allowed_error);
      printf("\n\nSolution\n\n");
      for(count = 1; count <= limit; count++)
      {
            printf("\nY[%d]:\t%f", count, y[count]);
      }
      return 0;
}
