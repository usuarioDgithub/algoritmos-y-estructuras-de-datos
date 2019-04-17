#include <stdio.h>
#define N 5                       //definir el tamaño de N

struct pila                    //Declaras una estructura que sera la pila
{
    int stk[N];             //Declarar el arreglo donde se guardan N datos
    int tope;               //Variable que tiene la estructura donde se guarda el tope de pila
};
typedef struct pila Pila;       //Para definir el tipo de dato de la estructura pila como Pila
Pila stack;                      //

void push(void);
int  pop(void);
void imprimir(void);

void main ()
{
    int salida;
    int opcion = 1;
    stack.tope = -1;

    printf ("Funciones de la Pila \n");
    while (opcion)
    {
        printf ("------------------------------------------\n");
        printf ("      1    -->    PUSH               \n");
        printf ("      2    -->    POP               \n");
        printf ("      3    -->    Mostrar               \n");
        printf ("      4    -->    EXIT           \n");
        printf ("------------------------------------------\n");

        printf ("Elige una opcion\n");
        scanf    ("%d", &salida);
        switch (salida)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            imprimir();
            break;
        case 4:
            return;
        }
        fflush (stdin);
        printf ("Desea continuar? (0 o 1 para salir o seguir)?\n");
        scanf    ("%d", &opcion);
    }
}

void push ()
{
    int num;
    if (stack.tope == ( N - 1))
    {
        printf ("Pila esta llena\n");
        return;
    }
    else
    {
        printf ("Elige el valor para agregar a la pila \n");
        scanf ("%d", &num);
        stack.tope = stack.tope + 1;
        stack.stk[stack.tope] = num;
    }
    return;
}

int pop ()
{
    int num;
    if (stack.tope == - 1)
    {
        printf ("Stack is Empty\n");
        return (stack.tope);
    }
    else
    {
        num = stack.stk[stack.tope];
        printf ("Se hizo pop al elemento = %dn", stack.stk[stack.tope]);
        stack.tope = stack.tope - 1;
    }
    return(num);
}
/*  Function to display the status of the stack */
void imprimir ()
{
    int i;
    if (stack.tope == -1)
    {
        printf ("La pila esta vacia\n");
        return;
    }
    else
    {

        for (i = stack.tope; i >= 0; i--)
        {
            printf ("%d\n", stack.stk[i]);
        }
    }
    printf ("\n");
}
