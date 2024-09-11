#include <stdio.h>

#define LARGURA 4
#define ALTURA 3

void imprimir_matriz(int * ptr_matriz, int largura, int altura);

void soma_coluna_mat_4x3(int matriz[LARGURA][ALTURA]);

int main()
{
    int matriz[LARGURA][ALTURA] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}, {1, 1, 1}};


    printf("A matriz eh: \n");
    imprimir_matriz(matriz, LARGURA, ALTURA);

    soma_coluna_mat_4x3(matriz);

    return 0;
}

void soma_coluna_mat_4x3(int matriz[LARGURA][ALTURA])
{
    for (int i = 0; i < ALTURA; i++)
    {
        int soma = 0;

        for (int j = 0; j < LARGURA; j++)
        {
            soma += matriz[i][j];
        }

        printf("Soma da coluna %d eh: %d\n", i + 1, soma);
    }
}

void imprimir_matriz(int * ptr_matriz, int largura, int altura)
{
    int ** matriz;

    for (int i = 0; i < largura; i++)
    {
        // Alocar o sub_array na matriz.
        matriz[i] = &ptr_matriz[i];

        for (int j = 0; j < altura; j++)
        {
            printf("%d ", matriz[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}
