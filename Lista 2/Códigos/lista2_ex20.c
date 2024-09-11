#include <stdio.h>

#define LARGURA 4
#define ALTURA 3

void imprimir_matriz(int * ptr_matriz, int largura, int altura);

void soma_coluna_mat_4x3(int matriz[LARGURA][ALTURA]);

int main()
{
    int matriz[LARGURA][ALTURA] = {{1, 1, 1}, {1, 1, 2}, {1, 3, 1}, {4, 1, 1}};


    printf("A matriz eh: \n");
    imprimir_matriz(matriz, LARGURA, ALTURA);

    soma_coluna_mat_4x3(matriz);

    return 0;
}

void soma_coluna_mat_4x3(int matriz[LARGURA][ALTURA])
{
    for (int j = 0; j < ALTURA; j++)
    {
        int soma = 0;

        for (int i = 0; i < LARGURA; i++)
        {
            soma += matriz[i][j];
        }

        printf("A soma dos elementos da coluna %d eh: %d\n", j + 1, soma);
    }
}

void imprimir_matriz(int * ptr_matriz, int largura, int altura)
{
    // Criar um ponteiro apontando para um array.
    int (*matriz)[altura] = ptr_matriz;

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
