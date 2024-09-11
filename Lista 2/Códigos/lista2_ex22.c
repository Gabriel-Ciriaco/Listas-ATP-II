#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LARGURA 4
#define ALTURA 4
#define RAND_INTER 10

void imprimir_matriz(int * ptr_matriz, int largura, int altura);

void preencher_rand(int matriz[LARGURA][ALTURA], int intervalo);

void sort_linha(int matriz[LARGURA][ALTURA]);

void swap(int * var_a, int * var_b);


int main()
{
    int matriz[LARGURA][ALTURA];

    preencher_rand(matriz, RAND_INTER);

    printf("A matriz eh: \n");
    imprimir_matriz(matriz, LARGURA, ALTURA);

    sort_linha(matriz);

    printf("A matriz com linhas ordenadas eh: \n");
    imprimir_matriz(matriz, LARGURA, ALTURA);

    return 0;
}

void preencher_rand(int matriz[LARGURA][ALTURA], int intervalo)
{
    // Alimentar a seed do rand.
    srand((unsigned int) time(NULL));

    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            matriz[i][j] = rand() % intervalo;
        }
    }
}

void sort_linha(int matriz[LARGURA][ALTURA])
{
    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            for (int d  = j; d < ALTURA; d++)
            {
                if (matriz[i][j] > matriz[i][d])
                {
                    swap(&matriz[i][j], &matriz[i][d]);
                }
            }
        }
    }
}

/* Utilizamos o XOR para o swap.*/
void swap(int * var_a, int * var_b)
{
    *var_a = *var_a ^ *var_b;
    *var_b = *var_a ^ *var_b;
    *var_a = *var_a ^ *var_b;
}

void imprimir_matriz(int * ptr_matriz, int largura, int altura)
{
    // Criar um ponteiro apontando para um array.
    int (* matriz)[altura] = ptr_matriz;

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
