#include <stdio.h>
#include <stdlib.h>

#define LARGURA 3
#define ALTURA 3

void imprimir_matriz(int * ptr_matriz, int largura, int altura);

int mult_transposta(int matriz[LARGURA][ALTURA],
                    int resultado[LARGURA][ALTURA]);


int main()
{
    int matriz[LARGURA][ALTURA] = {{1, 0, 2}, {0, 1, 3}, {4, 0, 1}};
    int resultado[LARGURA][ALTURA];

    printf("A matriz eh: ");
    imprimir_matriz(matriz, LARGURA, ALTURA);

    mult_transposta(matriz, resultado);

    printf("A matriz multiplicada pela transposta eh: ");

    imprimir_matriz(resultado, LARGURA, ALTURA);


    return 0;
}

int mult_transposta(int matriz[LARGURA][ALTURA],
                    int resultado[LARGURA][ALTURA])
{
    /* Criar matriz transposta */
    int transposta[ALTURA][LARGURA];

    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            transposta[i][j] = matriz[j][i];
        }
    }

    printf("A transposta dela eh: ");

    imprimir_matriz(transposta, ALTURA, LARGURA);

    /* Multiplicar A pela Transposta*/
    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            // Alocar a matriz resultado.
            resultado[i][j] = 0;

            for (int d = 0; d < ALTURA; d++)
            {
                resultado[i][j] += matriz[i][d] * transposta[d][j];
            }
        }
    }
}

void imprimir_matriz(int * ptr_matriz, int largura, int altura)
{
    printf("\n");

    // Criar um ponteiro apontando para um array.
    int (* matriz)[altura] = ptr_matriz;

    for (int i = 0; i < largura; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}
