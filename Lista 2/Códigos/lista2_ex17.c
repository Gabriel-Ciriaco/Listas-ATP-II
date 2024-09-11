#include <stdio.h>

#define LARGURA 3
#define ALTURA 3


void imprimir_matriz(int matriz[LARGURA][ALTURA]);

void imprimir_elemento_pos(int matriz[LARGURA][ALTURA], int elemento);

int main()
{
    int matriz[LARGURA][ALTURA] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int elemento = 0;

    printf("A matriz eh: \n");
    imprimir_matriz(matriz);

    printf("Digite um elemento da matriz: ");

    scanf("%d", &elemento);

    imprimir_elemento_pos(matriz, elemento);


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

    printf("\n");
}

void imprimir_elemento_pos(int matriz[LARGURA][ALTURA], int elemento)
{
    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            if (matriz[i][j] == elemento)
            {
                /*
                    Somamos 1 a i e j para facilitar a leitura, já que
                    indices de arrays começam no zero.
                */
                printf("\nO elemento %d esta em:\nLinha: %d\nColuna: %d\n",
                       elemento, i + 1, j + 1);
                break;
            }
        }
    }
}
