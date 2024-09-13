#include <stdio.h>

#define LARGURA 4
#define ALTURA 4


void imprimir_matriz(int * ptr_matriz, int largura, int altura);

float media_mat(int matriz[LARGURA][ALTURA]);


int main()
{
    int matriz[LARGURA][ALTURA] = {{2, 2, 2, 2}, {1, 1, 1, 1}, {1, 1, 1, 1}, {3, 3, 3, 3}};
    int rot_matriz[LARGURA][ALTURA];

    printf("A matriz eh: ");

    imprimir_matriz(matriz, LARGURA, ALTURA);

    printf("A media dos elementos da matriz eh: %.2f\n", media_mat(matriz));

    return 0;
}

float media_mat(int matriz[LARGURA][ALTURA])
{
    float media = 0;

    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            media += (float) matriz[i][j];
        }
    }

    media /= (LARGURA * ALTURA);

    return media;
}

void imprimir_matriz(int * ptr_matriz, int largura, int altura)
{
    // Criamos um array de ponteiros com o tamanho da altura.
    int (* matriz)[altura] = ptr_matriz;

    printf("\n");

    for (int i = 0; i < largura; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}
