#include <stdio.h>


int main()
{
    int numeros[10] = {1, 109, 12, 34, 41, 6, 7, 8, 10, 3};

    int maior = 0;
    int menor = 0;

    for (int i = 0; i < 10; i++)
    {
        if (numeros[i] > maior)
        {
            maior = numeros[i];
        }
    }

    menor = maior;

    for (int i = 0; i < 10; i++)
    {
        if (numeros[i] < menor)
        {
            menor = numeros[i];
        }
    }

    printf("O maior numero eh: %d\nO menor numero eh: %d", maior, menor);

    return 0;
}
