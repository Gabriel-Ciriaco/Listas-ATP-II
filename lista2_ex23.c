#include <stdio.h>

#define LARGURA 3
#define ALTURA 3


void imprimir_matriz(int matriz[LARGURA][ALTURA]);

int det_3x3(int matriz[LARGURA][ALTURA]);

int main()
{
    int matriz[LARGURA][ALTURA] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    printf("A matriz eh: \n");
    imprimir_matriz(matriz);

    printf("A determinante eh: %d\n", det_3x3(matriz));

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

int det_3x3(int matriz[LARGURA][ALTURA])
{
    // Utilizamos a própria fórmula da determinante 3x3.
    // Regra de Sarrus.
    return ((matriz[0][0] * matriz[1][1] * matriz[2][2]) +
           (matriz[0][1] * matriz[1][2] * matriz[2][0]) +
           (matriz[1][0] * matriz[2][1] * matriz[0][2]) -
           (matriz[0][2] * matriz[1][1] * matriz[2][0]) -
           (matriz[1][2] * matriz[2][1] * matriz[0][0]) -
           (matriz[0][1] * matriz[1][0] * matriz[2][2]));
}
