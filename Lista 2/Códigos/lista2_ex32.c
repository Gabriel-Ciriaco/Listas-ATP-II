#include <stdio.h>
#include <stdlib.h>

#define LARGURA 2
#define ALTURA 2

void imprimir_matriz(int * ptr_matriz, int largura, int altura);

int eh_reflexao(int matriz[LARGURA][ALTURA]);

int det2x2(int matriz[LARGURA][ALTURA]);


int main()
{
    int matriz[LARGURA][ALTURA] = {{0, 1}, {1, 0}};

    printf("A matriz eh: \n");
    imprimir_matriz(matriz, LARGURA, ALTURA);

    if (eh_reflexao(matriz) == 1)
    {
        printf("A matriz eh de reflexao.\n");
    }
    else
    {
        printf("A matriz nao eh de reflexao.\n");
    }


    return 0;
}

/*
    Pela definição, para ser de reflexão:

    Identidade = A * A_transposta

    E

    det(A) = -1.
*/
int eh_reflexao(int matriz[LARGURA][ALTURA])
{
    // Verificar se a determinante é -1.
    if (det2x2(matriz) != -1)
    {
        return 0;
    }

    /* Criar matriz transposta */
    int transposta[ALTURA][LARGURA];

    for (int i = 0; i < ALTURA; i++)
    {
        for (int j = 0; j < LARGURA; j++)
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

            for (int d = 0; d < ALTURA; d++)
            {
                elemento_atual += matriz[i][d] * transposta[d][j];
            }

            // Verificar se o resultado da multiplicação é a identidade.
            if (i == j && elemento_atual != 1 ||
                i != j && elemento_atual != 0)
            {
                // A matriz não eh de reflexão.
                return 0;
            }
        }
    }

    // A matriz eh de reflexão.
    return 1;
}

// Cálculo da determinante 2 por 2.
int det2x2(int matriz[LARGURA][ALTURA])
{
    return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
}

void imprimir_matriz(int * ptr_matriz, int largura, int altura)
{
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
