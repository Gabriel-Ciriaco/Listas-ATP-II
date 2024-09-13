#include <stdio.h>

#define LINHA 3
#define COLUNA 2


int main()
{
    int matriz[LINHA][COLUNA] = {{1, 2}, {3, 4}, {5, 6}};
    int transposta[COLUNA][LINHA];

    // Imprimindo a matriz
    printf("A matriz eh:\n");

    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Transpor a matriz.
    for (int i = 0; i < COLUNA; i++)
    {
        for (int j = 0; j < LINHA; j++)
        {
            transposta[i][j] = 0;

            transposta[i][j] += matriz[j][i];
        }
    }

    // Imprimir a matriz transposta
    printf("\nA transposta eh:\n");

    for (int i = 0; i < COLUNA; i++)
    {
        for (int j = 0; j < LINHA; j++)
        {
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }
}
