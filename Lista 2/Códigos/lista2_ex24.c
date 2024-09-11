#include <stdio.h>
#include <stdlib.h>

#define LARGURA 3
#define ALTURA 3

void imprimir_matriz(int * ptr_matriz, int largura, int altura);

int eh_ortogonal(int matriz[LARGURA][ALTURA]);


int main()
{
    int matriz_1[LARGURA][ALTURA] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int matriz_2[LARGURA][ALTURA] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printf("A matriz_1 eh: \n");
    imprimir_matriz(matriz_1, LARGURA, ALTURA);

    printf("A matriz_2 eh: \n");
    imprimir_matriz(matriz_2, LARGURA, ALTURA);

    if (eh_ortogonal(matriz_1) == 1)
    {
        printf("As matriz_1 eh ortogonal.\n");
    }
    else
    {
        printf("As matriz_1 nao eh ortogonal.\n");
    }

    if (eh_ortogonal(matriz_2) == 1)
    {
        printf("As matriz_2 eh ortogonal.\n");
    }
    else
    {
        printf("As matriz_2 nao eh ortogonal.\n");
    }

    return 0;
}

/*
    Pela definição, A é ortogonal se

    A_inversa  = A_transposta.

    Logo, com operações de matriz, tem-se:

    A * A_inversa = A * A_transposta

    Portanto: Identidade = A * A_transposta
*/
int eh_ortogonal(int matriz[LARGURA][ALTURA])
{
    /* Criar matriz transposta */
    int transposta[ALTURA][LARGURA];

    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            transposta[i][j] = matriz[j][i];
        }
    }

    /* Multiplicar A pela Transposta*/

    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            // Alocar a matriz resultado.
            int elemento_atual = 0;

            for (int d = j; d < ALTURA; d++)
            {
                elemento_atual += matriz[i][d] * transposta[d][j];
            }

            // Verificar se o resultado da multiplicação é a identidade.
            if (i == j && elemento_atual != 1 ||
                i != j && elemento_atual != 0)
            {
                // A matriz não eh ortogonal.
                return 0;
            }
        }
    }

    // A matriz eh ortogonal.
    return 1;
}

void imprimir_matriz(int * ptr_matriz, int largura, int altura)
{
    // Criamos um array de ponteiros com o tamanho da altura.
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
