#include <stdio.h>

#define DIM 2

int compare(int matriz_1[DIM][DIM], int matriz_2[DIM][DIM]);

int main()
{
    int matriz_1[DIM][DIM] = {{1, 2}, {3, 4}};
    int matriz_2[DIM][DIM] = {{1, 2}, {3, 4}};

    if (compare(matriz_1, matriz_2) == 1)
    {
        printf("As matrizes sao iguais.");
    }
    else
    {
        printf("As matrizes nao sao iguais.");
    }

    return 0;
}

int compare(int matriz_1[DIM][DIM], int matriz_2[DIM][DIM])
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
