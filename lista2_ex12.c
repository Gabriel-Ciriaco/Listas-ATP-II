#include <stdio.h>

#define LARGURA 2
#define ALTURA 4


void imprimir_matriz(int matriz[LARGURA][ALTURA]);

float media_elementos(int matriz[LARGURA][ALTURA]);

int main()
{
    int matriz[LARGURA][ALTURA] = {{1, 2, 3, 4}, {5, 6, 7, 8}};

    printf("A matriz eh: \n");
    imprimir_matriz(matriz);

    printf("\n");

    printf("A media dos elementos eh: %.2f", media_elementos(matriz));


    return 0;
}

void imprimir_matriz(int matriz[LARGURA][ALTURA])
{
    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            printf("%d ", matriz[i][j]);
        }

        printf("\n");
    }
}

float media_elementos(int matriz[LARGURA][ALTURA])
{
    float media = 0;

    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
           media += (float) matriz[i][j];
        }
    }

    media /= (float) (LARGURA * ALTURA);

    return media;
}
