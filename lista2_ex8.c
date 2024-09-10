#include <stdio.h>

#define DIM 4


void imprimir_matriz(int matriz[DIM][DIM]);

int main()
{
    int matriz[DIM][DIM] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 1, 2, 3}, {4, 5, 6, 7}};
    int rot[DIM][DIM];

    printf("A matriz eh:\n");
    imprimir_matriz(matriz);

    for(int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            rot[i][j] = 0;

            rot[i][j] += matriz[DIM - j - 1][i];
        }
    }

    printf("\nA rotacao horaria fica:\n");
    imprimir_matriz(rot);

    return 0;
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
