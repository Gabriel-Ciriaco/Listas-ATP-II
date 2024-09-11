#include <stdio.h>

#define DIM 3

int main()
{
    int matriz[DIM][DIM] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            printf("%d ", matriz[i][j]);
        }

        printf("\n");
    }

    return 0;
}
