#include <stdio.h>

#define LARGURA 2
#define ALTURA 3

#define DIM4 4


void imprimir_matriz(int * ptr_matriz, int largura, int altura);

void mult_2x3_3x4(int result[LARGURA][DIM4],
                  int matriz_1[LARGURA][ALTURA],
                  int matriz_2[ALTURA][DIM4]);

int main()
{
    int matriz_1[LARGURA][ALTURA] = {{1, 2, 3}, {4, 5, 6}};

    int matriz_2[ALTURA][DIM4] = {{1, 0, 0, 1}, {0, 1, 0, 1}, {0, 0, 1, 1}};

    int result[LARGURA][DIM4];

    printf("A matriz 1 eh: ");

    imprimir_matriz(matriz_1, LARGURA, ALTURA);

    printf("A matriz 2 eh: ");

    imprimir_matriz(matriz_2, ALTURA, DIM4);

    printf("Multiplicando-as: ");

    mult_2x3_3x4(result, matriz_1, matriz_2);

    imprimir_matriz(result, LARGURA, DIM4);


    return 0;
}

void mult_2x3_3x4(int result[LARGURA][DIM4],
                  int matriz_1[LARGURA][ALTURA],
                  int matriz_2[ALTURA][DIM4])
{
    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < DIM4; j++)
        {
            result[i][j] = 0;

            for (int d = 0; d < ALTURA; d++)
            {
                result[i][j] += matriz_1[i][d] * matriz_2[d][j];
            }
        }
    }
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
