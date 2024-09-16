#include <stdio.h>

#define LARGURA 4
#define ALTURA 4


void imprimir_matriz(int * ptr_matriz, int largura, int altura);

int soma_diagonal_qualquer(int * ptr_matriz, int selecionar_diagonal);


int main()
{
    int matriz[LARGURA][ALTURA] = {{1, 2, 3, 4},
                                   {5, 6, 7, 8},
                                   {9, 1, 2, 3},
                                   {9, 1, 3, 4}};
    int diagonal = 0;

    printf("A matriz eh: ");

    imprimir_matriz(matriz, LARGURA, ALTURA);

    printf("Digite 1 para a diagonal principal e 2 para a secundaria: \n");
    scanf("%d", &diagonal);

    int soma =  soma_diagonal_qualquer(matriz, diagonal);

    printf("A soma dos elementos da diagonal %d eh: %d\n", diagonal, soma);

    return 0;
}

int soma_diagonal_qualquer(int * ptr_matriz, int selecionar_diagonal)
{
    int (* matriz)[ALTURA] = ptr_matriz;
    int soma = 0;

    if (selecionar_diagonal == 1)
    {
        for (int i = 0; i < LARGURA; i++)
        {
            for (int j = 0; j < ALTURA; j++)
            {
                // Elemento está na Diagonal principal.
                if (i == j)
                {
                    soma += matriz[i][j];
                }
            }
        }
    }
    else if (selecionar_diagonal == 2)
    {
        for (int i = 0; i < LARGURA; i++)
        {
            for (int j = 0; j < ALTURA; j++)
            {
                // Elemento está na Diagonal secundária.
                if (i + j == ALTURA - 1)
                {
                    soma += matriz[i][j];
                }
            }
        }
    }

    return soma;
}

void imprimir_matriz(int * ptr_matriz, int largura, int altura)
{
    // Criamos um ponteiro que aponta para um array de tamanho altura.
    int (* matriz)[altura] = ptr_matriz;

    printf("\n");

    for (int i = 0; i < largura; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}
