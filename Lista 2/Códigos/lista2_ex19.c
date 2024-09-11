#include <stdio.h>

#define LARGURA 2
#define ALTURA 3

void imprimir_matriz(int * ptr_matriz, int largura, int altura);

void matriz_mult_2x2(int resultado_2x2[2][2],
                     int mat_2x3[2][3],
                     int mat_3x2[3][2]);

int main()
{
    int matriz1[LARGURA][ALTURA] = {{1, 2, 3}, {4, 5, 6}};

    int matriz2[ALTURA][LARGURA] = {{1, 2}, {4, 5}, {6, 7}};

    int matriz_resultado[LARGURA][LARGURA];

    printf("A matriz_1 eh: \n");
    imprimir_matriz(matriz1, LARGURA, ALTURA);

    printf("A matriz_2 eh: \n");
    imprimir_matriz(matriz2, ALTURA, LARGURA);

    matriz_mult_2x2(matriz_resultado, matriz1, matriz2);

    printf("Matriz 1 * Matriz 2: \n");
    imprimir_matriz(matriz_resultado, LARGURA, LARGURA);


    return 0;
}

void matriz_mult_2x2(int resultado_2x2[2][2],
                     int mat_2x3[2][3],
                     int mat_3x2[3][2])
{
    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            // Alocamos 0 aos elementos do array.
            resultado_2x2[i][j] = 0;

            for (int d = 0; d < ALTURA; d++)
            {
                resultado_2x2[i][j] += mat_2x3[i][d] * mat_3x2[j][d];
            }
        }
    }
}

void imprimir_matriz(int * ptr_matriz, int largura, int altura)
{
    // Criar um ponteiro apontando para um array.
    int (*matriz)[altura] = ptr_matriz;

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
