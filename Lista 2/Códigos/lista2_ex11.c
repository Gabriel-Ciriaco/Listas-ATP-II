#include <stdio.h>

#define LARGURA 3
#define ALTURA 3


void imprimir_matriz(int matriz[LARGURA][ALTURA]);

int elementos_pares(int matriz[LARGURA][ALTURA]);

int main()
{
    int matriz[LARGURA][ALTURA] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printf("A matriz eh: \n");
    imprimir_matriz(matriz);

    printf("\n");

    printf("Existem %d elementos pares na matriz.\n", elementos_pares(matriz));


    return 0;
}

void imprimir_matriz(int matriz[LARGURA][ALTURA])
{
    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            printf("%d ", matriz[i][j]);
        }

        printf("\n");
    }
}

int elementos_pares(int matriz[LARGURA][ALTURA])
{
    int pares = 0;

    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
           if(matriz[i][j] % 2 == 0)
           {
               pares++;
           }
        }
    }

    return pares;
}
