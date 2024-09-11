#include <stdio.h>


int main()
{
    int numeros[5] = {1, 2, 3, 4, 5};

    int * ptr = &numeros;

    for (int i = 0; i < 5; i++)
    {
        printf("Numero: %d\n", *(ptr + i));
    }


    return 0;
}
