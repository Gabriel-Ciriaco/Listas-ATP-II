#include <stdio.h>

#define DIM 3


void imprimir_matriz(int matriz[DIM][DIM]);

int main()
{
    int matriz_1[DIM][DIM] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matriz_2[DIM][DIM] = {{1, 2, 3}, {4, 1, 0}, {0, 0, 1}};
    int result[DIM][DIM];

    printf("A primeira matriz eh:\n");
    imprimir_matriz(matriz_1);

    printf("\n");

    printf("A segunda matriz eh:\n");
    imprimir_matriz(matriz_2);

    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            result[i][j] = 0;

            for (int d = 0; d < DIM; d++)
            {
                result[i][j] += matriz_1[i][d] * matriz_2[d][j];
            }
        }
    }

    printf("\nO resultado da multiplicacao eh:\n");
    imprimir_matriz(result);
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
