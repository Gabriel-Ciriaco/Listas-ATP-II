#include <stdio.h>
#include <stdlib.h>

#define LARGURA 3
#define ALTURA 4

void imprimir_matriz(int * ptr_matriz, int largura, int altura);

void transposta(int matriz[LARGURA][ALTURA],
               int transposta[ALTURA][LARGURA]);


int main()
{
    int matriz[LARGURA][ALTURA] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 0, 1}};
    int resultado[LARGURA][ALTURA];

    printf("A matriz eh: ");
    imprimir_matriz(matriz, LARGURA, ALTURA);

    printf("A transposta eh: ");

    transposta(matriz, resultado);

    imprimir_matriz(resultado, ALTURA, LARGURA);


    return 0;
}

/* Cria uma matriz transposta */
void transposta(int matriz[LARGURA][ALTURA],
               int transposta[ALTURA][LARGURA])
{
    for (int i = 0; i < ALTURA; i++)
    {
        for (int j = 0; j < LARGURA; j++)
        {
            transposta[i][j] = matriz[j][i];
        }
    }
}

void imprimir_matriz(int * ptr_matriz, int largura, int altura)
{
    printf("\n");

    // Criar um ponteiro apontando para um array.
    int (* matriz)[altura] = ptr_matriz;

    for (int i = 0; i < largura; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}
