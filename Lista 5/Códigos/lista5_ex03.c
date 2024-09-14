#include <stdio.h>

#define NUM_LEN 5


int max(int * numeros, int i);

int main()
{
    int numeros[NUM_LEN] = {1, -2, 3, -4, 5};

    printf("O maior elemento eh: %d", max(numeros, NUM_LEN - 1));

    return 0;
}

int max(int * numeros, int i)
{
    if (i == 0)
    {
        return numeros[i];
    }

    int maior = max(numeros, i - 1);

    // Verifica se o elemento atual é o maior.
    return numeros[i] > maior ? numeros[i] : maior;
}
