#include <stdio.h>


int main()
{
    float numeros[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    float * ptr = &numeros;

    float media = 0;

    for (int i = 0; i < 8; i++)
    {
        media += *(ptr + i);
    }

    media /= 8;

    printf("A media eh: %.2f", media);

    return 0;
}
