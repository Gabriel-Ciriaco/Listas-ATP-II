#include <stdio.h>

#define DIM 4


void imprimir_matriz(int matriz[DIM][DIM]);

int main()
{
    int matriz[DIM][DIM] = {{0, 2, 3, 4},
                            {5, 0, 7, 8},
                            {7, 8, 0, 1},
                            {1, 2, 3, 0}};


    printf("A matriz eh:\n");

    imprimir_matriz(matriz);


    int soma_abaixo = 0;

    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            // Elemento abaixo da diagonal principal.
            if (i > j)
            {
                soma_abaixo += matriz[i][j];
            }
        }
    }

    printf("\nA soma dos elementos abaixo da diagonal principal eh: %d\n",
           soma_abaixo);
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
