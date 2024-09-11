#include <stdio.h>


int main()
{
    int numeros[5] = {1, 2, 3, 4, 5};

    int * ptr = &numeros;

    // Zerar o vetor
    for (int i = 0; i < 5; i++)
    {
        *(ptr + i) = 0;

        printf("Novo elemento %d: %d\n", i, numeros[i]);
    }

    return 0;
}
