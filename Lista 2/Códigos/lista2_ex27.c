#include <stdio.h>

#define LARGURA 3
#define ALTURA 3


void imprimir_matriz(int * ptr_matriz, int largura, int altura);

void mult_matrix(int matriz[LARGURA][ALTURA], int escalar);

int main()
{
    int matriz[LARGURA][ALTURA] = {{9, 0, 0}, {0, 5, 1}, {1, 0, 0}};

    int escalar = 0;

    printf("A matriz eh: ");

    imprimir_matriz(matriz, LARGURA, ALTURA);

    printf("Digite um escalar: ");

    scanf("%d", &escalar);

    mult_matrix(matriz, escalar);

    printf("\nA matriz multiplicada por %d eh: ");

    imprimir_matriz(matriz, LARGURA, ALTURA);


    return 0;
}

void mult_matrix(int matriz[LARGURA][ALTURA], int escalar)
{
    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            matriz[i][j] *= escalar;
        }
    }
}

void imprimir_matriz(int * ptr_matriz, int largura, int altura)
{
    // Criamos um array de ponteiros com o tamanho da altura.
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
