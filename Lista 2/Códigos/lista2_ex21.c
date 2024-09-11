#include <stdio.h>

#define LARGURA 3
#define ALTURA 3

void imprimir_matriz(int * ptr_matriz, int largura, int altura);

int eh_permutacao(int matriz[LARGURA][ALTURA]);

int main()
{
    int matriz[LARGURA][ALTURA] = {{0, 1, 0}, {1, 0, 0}, {0, 0, 1}};


    printf("A matriz eh: \n");
    imprimir_matriz(matriz, LARGURA, ALTURA);

    if (eh_permutacao(matriz) == 1)
    {
        printf("A matriz eh permutacao.\n");
    }
    else
    {
        printf("A matriz nao eh de permutacao.\n");
    }

    return 0;
}

/*
    Pela definição, a matriz é de permutação se o valor de apenas
    um elemento por linha e por coluna for igual a um e o resto zero.

    Assim, basta ver se a soma da linha = 1 e da coluna = 1.
*/
int eh_permutacao(int matriz[LARGURA][ALTURA])
{
    for (int i = 0; i < LARGURA; i++)
    {
        int soma_linha = 0;
        int soma_coluna = 0;

        for (int j = 0; j < ALTURA; j++)
        {
            soma_linha += matriz[i][j];
            soma_coluna += matriz[j][i];
        }

        if (soma_linha != 1 || soma_coluna != 1)
        {
            return 0;
        }
    }

    return 1;
}

void imprimir_matriz(int * ptr_matriz, int largura, int altura)
{
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
