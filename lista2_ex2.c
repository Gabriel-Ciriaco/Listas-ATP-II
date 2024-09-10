#include <stdio.h>

#define DIM 4

int main()
{
    int matriz[DIM][DIM] = { {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};

    int soma = 0;

    printf("A matriz eh: \n");

    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            printf("%d ", matriz[i][j]);
            soma += matriz[i][j];
        }

        printf("\n");
    }

    printf("A soma dos elementos eh: %d", soma);

    return 0;
}
