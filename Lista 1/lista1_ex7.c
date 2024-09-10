#include <stdio.h>


int main()
{
    float valores[6];
    float media = 0;

    for (int i = 0; i < 6; i++)
    {
        scanf("%f", &valores[i]);

        media += valores[i];
    }

    media /= 6;

    printf("Media: %.2f", media);

    return 0;
}
