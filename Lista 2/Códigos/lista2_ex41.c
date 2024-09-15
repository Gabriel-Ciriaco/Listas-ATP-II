#include <stdio.h>

#define LARGURA 3
#define ALTURA 3


void imprimir_matriz(int * ptr_matriz, int largura, int altura);

int eh_toeplitz(int * ptr_matriz);


int main()
{
    int matriz[LARGURA][ALTURA] = {{1, 2, 3}, {4, 1, 2}, {5, 4, 1}};

    printf("A matriz eh: ");

    imprimir_matriz(matriz, LARGURA, ALTURA);

    if (eh_toeplitz(matriz) == 1)
    {
        printf("A matriz eh de Toeplitz.\n");
    }
    else
    {
        printf("A matriz nao eh de Toeplitz.\n");
    }


    return 0;
}

/*
    Matriz de Toeplitz é a que os elementos das diagonais do topo esquerdo
    para o topo direito são iguais.
*/
int eh_toeplitz(int * ptr_matriz)
{
    int (*matriz)[ALTURA] = ptr_matriz;

    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            if (j < ALTURA - 1 && i < LARGURA - 1)
            {
                // Se o elemento abaixo e à direita é diferente,
                // Não é de Hankel.
                if (matriz[i][j] != matriz[i + 1][j + 1])
                {
                    return 0;
                }
            }
        }
    }

    return 1;
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
