#include <stdio.h>


int main()
{
    int numeros[20];
    int pares, impares = 0;

    // Populando o vetor
    for (int i = 0; i < 20; i++)
    {
        numeros[i] = i + 1;

        // Deixando um ímpar a mais para testes.
        if(i == 19) numeros[i] = 21;
    }

    for (int i = 0; i < 20; i++)
    {
        if (numeros[i] % 2 == 0)
        {
            pares += 1;
        }
        else
        {
            impares += 1;
        }
    }

    printf("Pares: %d\nImpares: %d", pares, impares);

    return 0;
}
