#include <stdio.h>

#define DIM 5


void imprimir_matriz(int matriz[DIM][DIM]);

int main()
{
    int matriz[DIM][DIM] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 0}, {1, 2, 3, 4, 5}, {6, 7, 8, 9, 0}, {1, 2, 3, 4, 5}};


    printf("A matriz eh:\n");
    imprimir_matriz(matriz);
    printf("\n");

    // Cálculo da diagonal principal.
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            if (i == j)
            {
                printf("Diagonal principal: %d", matriz[i][j]);
            }
        }
        printf("\n");
    }

    printf("\n");
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
