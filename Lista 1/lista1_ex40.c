#include <stdio.h>

#define NUM_MAX 8


void inverter(int * numeros);

int main()
{
    int numeros[NUM_MAX] = {1, 2, -3, 4, 5, 6, -7, 58};

    printf("O array atual:\n");
    for (int i = 0; i < NUM_MAX; i++)
    {
        printf("Elemento %d: %d\n", i, numeros[i]);
    }

    inverter(numeros);

    printf("\nA nova ordem de elementos eh:\n");
    for (int i = 0; i < NUM_MAX; i++)
    {
        printf("Elemento %d: %d\n", i, numeros[i]);
    }


    return 0;
}

void inverter(int * numeros)
{
    for (int i = 0; i < (int) NUM_MAX / 2; i++)
    {
        // Usando a lógica do XOR, conseguimos
        // trocar os valores das variaveis sem uma temporária.
        numeros[i] ^= numeros[NUM_MAX - 1 - i];
        numeros[NUM_MAX - 1 - i] ^= numeros[i];
        numeros[i] ^= numeros[NUM_MAX - 1 - i];
    }
}
