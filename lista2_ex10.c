#include <stdio.h>

#define DIM 4


void imprimir_matriz(int matriz[DIM][DIM]);
int menor_elemento(int matriz[][DIM]);

int main()
{
    int matriz[DIM][DIM] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, -16}};

    printf("A matriz eh: \n");
    imprimir_matriz(matriz);

    printf("\n");

    printf("O menor elemento eh: %d\n", menor_elemento(matriz));

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

int menor_elemento(int matriz[][DIM])
{
    int menor = matriz[0][0];

    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            if (matriz[i][j] < menor)
            {
                menor = matriz[i][j];
            }
        }
    }

    return menor;
}
