#include <stdio.h>

#define LARGURA 4
#define ALTURA 4


void imprimir_matriz(int matriz[LARGURA][ALTURA]);

int eh_diagonal(int matriz[LARGURA][ALTURA]);

int main()
{
    int matriz[LARGURA][ALTURA] = {{1, 0, 0, 0}, {0, 2, 0, 0}, {0, 0, 3, 0}, {0, 0, 0, 4}};

    printf("A matriz eh: \n");
    imprimir_matriz(matriz);

    printf("\n");

    if (eh_diagonal(matriz) == 1)
    {
        printf("A matriz eh diagonal.\n");
    }
    else
    {
        printf("A matriz nao eh diagonal.\n");
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
}

int eh_diagonal(int matriz[LARGURA][ALTURA])
{
    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            /*
                Se o elemento não pertence a diagonal
                principal é diferente de 0, então não é
                uma matriz diagonal.
            */
           if(i != j && matriz[i][j] != 0)
           {
               return 0;
           }
        }
    }

    return 1;
}
