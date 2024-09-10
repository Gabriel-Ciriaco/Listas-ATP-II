#include <stdio.h>

#define LARGURA 3
#define ALTURA 3


void imprimir_matriz(int matriz[LARGURA][ALTURA]);

void copiar_matriz(int matriz_source[LARGURA][ALTURA],
                   int matriz_dest[LARGURA][ALTURA]);

int main()
{
    int matriz[LARGURA][ALTURA] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matriz_copia[LARGURA][ALTURA] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    printf("A matriz original eh:\n");
    imprimir_matriz(matriz);

    printf("A matriz copia eh:\n");
    imprimir_matriz(matriz_copia);

    copiar_matriz(matriz, matriz_copia);

    printf("A nova matriz copia eh:\n");
    imprimir_matriz(matriz_copia);

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

void copiar_matriz(int matriz_source[LARGURA][ALTURA],
                   int matriz_dest[LARGURA][ALTURA])
{
    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            matriz_dest[i][j] = matriz_source[i][j];
        }
    }
}
