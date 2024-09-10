#include <stdio.h>

#define LARGURA 3
#define ALTURA 3


void imprimir_matriz(int matriz[LARGURA][ALTURA]);

int eh_identidade(int matriz[LARGURA][ALTURA]);

int main()
{
    int matriz[LARGURA][ALTURA] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    printf("A matriz eh: \n");
    imprimir_matriz(matriz);

    if (eh_identidade(matriz) == 1)
    {
        printf("A matriz eh identidade.\n");
    }
    else
    {
        printf("A matriz nao eh identidade.\n");
    }


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

int eh_identidade(int matriz[LARGURA][ALTURA])
{
    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            /*
                Se a diagonal principal não é
                composta somente de 1, ou se os outros
                elementos não são somente 0, então não
                é matriz identidade.
            */
            if (i == j && matriz[i][j] != 1 ||
                i != j && matriz[i][j] != 0)
            {
                return 0;
            }
        }
    }

    // É matriz identidade.
    return 1;
}
