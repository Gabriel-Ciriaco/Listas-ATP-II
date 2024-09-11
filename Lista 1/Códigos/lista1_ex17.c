#include <stdio.h>


int main()
{
    int numeros[5] = {1, 2, 3, 4, 5};

    int * ptr = &numeros;

    for (int i = 0; i < 5; i++)
    {
        *(ptr + i) += 10;

        printf("Novo numero: %d\n", numeros[i]);
    }
    return 0;
}
