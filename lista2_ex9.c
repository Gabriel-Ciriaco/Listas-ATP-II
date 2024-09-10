#include <stdio.h>

#define DIM 3


void imprimir_matriz(int matriz[DIM][DIM]);
int maior_elemento(int matriz[][DIM]);

int main()
{
    int matriz[DIM][DIM] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printf("A matriz eh: \n");
    imprimir_matriz(matriz);

    printf("\n");

    printf("O maior elemento eh: %d\n", maior_elemento(matriz));

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

int maior_elemento(int matriz[][DIM])
{
    int maior = matriz[0][0];

    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            if (matriz[i][j] > maior)
            {
                maior = matriz[i][j];
            }
        }
    }

    return maior;
}
