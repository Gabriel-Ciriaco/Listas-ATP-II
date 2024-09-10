#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int numeros[10];
    float media = 0;

    // Aplicar seed conforme o tempo.
    srand((unsigned) time(NULL));


    for (int i = 0; i < 10; i++)
    {
        numeros[i] = 50 + (rand() % 150);

        media += (float) numeros[i];

        printf("Elemento %d: %d\n", i, numeros[i]);
    }

    media /= 10;

    printf("Media: %.2f", media);

    return 0;
}
