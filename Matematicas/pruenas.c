#include<stdlib.h>

int main(void){

    int var = 789;

    int *ptr;

    int **ptr2;

    ptr = &var;
    ptr2 = &ptr;

    printf("%d",*ptr);
    printf("%d",**ptr2);


}
