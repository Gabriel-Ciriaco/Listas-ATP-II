#include <stdio.h>
#include <stdlib.h>

#define QTD_NUM 12

int main()
{
    int numeros[12];
    int negativos = 0;

    srand((unsigned) time(NULL));

    for (int i = 0; i < QTD_NUM; i++)
    {
        numeros[i] = -20 + (rand() % 40);
        printf("Elemento %d: %d\n", i, numeros[i]);
    }

    for (int i = 0; i < QTD_NUM; i++)
    {
        if (numeros[i] < 0) negativos++;
    }

    printf("Negativos: %d", negativos);

    return 0;
}
