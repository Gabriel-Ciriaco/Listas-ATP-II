#include <stdio.h>

#define LARGURA 5
#define ALTURA 5


void imprimir_matriz(int * ptr_matriz, int largura, int altura);

int menor_elemento(int matriz[LARGURA][ALTURA]);


int main()
{
    int matriz[LARGURA][ALTURA] = {{1, 2, 3, 4, 5}, {7, 8, 9, 2, 1}, {0, 6, -1, 6, 5}, {7, 8, 9, 2, 1}, {1, 2, 3, 4, 5}};
    int rot_matriz[LARGURA][ALTURA];

    printf("A matriz eh: ");

    imprimir_matriz(matriz, LARGURA, ALTURA);

    printf("O menor da matriz eh: %d\n", menor_elemento(matriz));

    return 0;
}

int menor_elemento(int matriz[LARGURA][ALTURA])
{
    int menor = matriz[0][0];

    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            if (matriz[i][j] < menor)
            {
                menor = matriz[i][j];
            }
        }
    }

    return menor;
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
