#include <stdio.h>

#define DIM 3

void transpor_matriz(int matriz[DIM][DIM], int transposta[DIM][DIM]);

int comparar_matriz(int matriz_1[DIM][DIM], int matriz_2[DIM][DIM]);

void imprimir_matriz(int matriz[DIM][DIM]);

int main()
{
    int matriz[DIM][DIM] = {{1, 1, 1}, {1, 2, 1}, {1, 1, 1}};
    int transposta[DIM][DIM];

    printf("A matriz eh:\n");
    imprimir_matriz(matriz);
    printf("\n");

    printf("A transposta eh:\n");
    transpor_matriz(matriz, transposta);
    imprimir_matriz(transposta);
    printf("\n");

    // Para a matriz ser simétrica, deve ser igual a transposta.
    if (comparar_matriz(matriz, transposta) == 1)
    {
        printf("A matriz eh simetrica.");
    }
    else
    {
        printf("As matrizes nao eh simetrica.");
    }

    return 0;
}

void transpor_matriz(int matriz[DIM][DIM], int transposta[DIM][DIM])
{
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            transposta[i][j] = 0;

            transposta[i][j] += matriz[j][i];
        }
    }
}

int comparar_matriz(int matriz_1[DIM][DIM], int matriz_2[DIM][DIM])
{
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            if (matriz_1[i][j] != matriz_2[i][j])
            {
                return 0;
            }
        }
    }

    return 1;
}

void imprimir_matriz(int matriz[DIM][DIM])
{
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            printf("%d ", matriz[i][j]);
        }

        printf("\n");
    }
}
