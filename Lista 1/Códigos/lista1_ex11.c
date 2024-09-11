#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD_NUM 15

int main()
{
    int numeros[QTD_NUM];
    int maior = 0;

    srand((unsigned) time(NULL));

    for (int i = 0; i < QTD_NUM; i++)
    {
        numeros[i] = rand() % 50;
        printf("Elemento %d: %d\n", i, numeros[i]);
    }

    for (int i = 0; i < QTD_NUM; i++)
    {
        if (i == 0) maior = numeros[i];

        if (maior < numeros[i])
        {
            maior = numeros[i];
        }
    }

    printf("O maior valor: %d", maior);

    return 0;
}
