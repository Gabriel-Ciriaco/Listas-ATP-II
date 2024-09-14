#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LARGURA 5
#define ALTURA 5


void imprimir_matriz(int * ptr_matriz, int largura, int altura);

void swap_variaveis(int * a, int * b);

void preencher_aleatorio(int * ptr_matriz, int max_rand);

void ordenar_colunas(int * ptr_matriz);


int main()
{
    int matriz[LARGURA][ALTURA] = {{0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0}};

    printf("A matriz eh: ");

    imprimir_matriz(matriz, LARGURA, ALTURA);

    printf("A matriz com numeros aleatorios eh: ");

    preencher_aleatorio(matriz, 100);

    imprimir_matriz(matriz, LARGURA, ALTURA);

    printf("Ordenando as colunas dela: ");

    ordenar_colunas(matriz);

    imprimir_matriz(matriz, LARGURA, ALTURA);

    return 0;
}

void ordenar_colunas(int * ptr_matriz)
{
    int (* matriz)[ALTURA] = ptr_matriz;

    for (int j = 0; j < ALTURA; j++)
    {
        for (int i = 0; i < LARGURA; i++)
        {
            for (int d = 0; d < LARGURA; d++)
            {
                if (matriz[i][j] < matriz[d][j])
                {
                    swap_variaveis(&matriz[i][j], &matriz[d][j]);
                }
            }
        }
    }
}

void preencher_aleatorio(int * ptr_matriz, int max_rand)
{
    int (* matriz)[ALTURA] = ptr_matriz;

    srand(time(NULL));

    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            matriz[i][j] = rand() % max_rand;
        }
    }
}

void swap_variaveis(int * a, int * b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
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
