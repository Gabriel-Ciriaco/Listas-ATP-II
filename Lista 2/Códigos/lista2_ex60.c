#include <stdio.h>

#define LARGURA 5
#define ALTURA 5


void imprimir_matriz(int * ptr_matriz, int largura, int altura);

void girar_anti(int matriz[LARGURA][ALTURA], int rot_matriz[LARGURA][ALTURA]);


int main()
{
    int matriz[LARGURA][ALTURA] = {{1, 2, 3, 4, 5},
                                   {6, 7, 8, 9, 0},
                                   {1, 2, 3, 4, 5},
                                   {6, 7, 8, 9, 0},
                                   {1, 2, 3, 4, 5}};

    int rot_matriz[LARGURA][ALTURA];

    printf("A matriz eh: ");

    imprimir_matriz(matriz, LARGURA, ALTURA);

    girar_anti(matriz, rot_matriz);

    printf("A matriz rotacionada eh: ");

    imprimir_matriz(rot_matriz, LARGURA, ALTURA);

    return 0;
}

void girar_anti(int matriz[LARGURA][ALTURA], int rot_matriz[LARGURA][ALTURA])
{
    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            rot_matriz[i][j] = matriz[j][LARGURA - 1 - i];
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
