#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LARGURA 4
#define ALTURA 4


void imprimir_matriz(int * ptr_matriz, int largura, int altura);

void swap_variaveis(int * a, int * b);

void preencher_aleatorio(int * ptr_matriz, int max_rand);

float media_acima_dprincipal(int matriz[LARGURA][ALTURA]);


int main()
{
    int matriz[LARGURA][ALTURA] = {{0, 0, 0, 0},
                                   {0, 0, 0, 0},
                                   {0, 0, 0, 0},
                                   {0, 0, 0, 0}};

    printf("A matriz eh: ");

    imprimir_matriz(matriz, LARGURA, ALTURA);

    printf("A matriz com numeros aleatorios eh: ");

    preencher_aleatorio(matriz, 10);

    imprimir_matriz(matriz, LARGURA, ALTURA);

    printf("A media dos elementos acima da diagonal principal eh: %.2f",
           media_acima_dprincipal(matriz));

    return 0;
}

/*
    Ordenamos a matriz e pegamos o segundo maior elemento.
*/
float media_acima_dprincipal(int matriz[LARGURA][ALTURA])
{
    float media = 0;
    int count_elementos = 0;

    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            // Elemento está acima da diagonal principal
            if (i < j)
            {
                media += matriz[i][j];
                count_elementos++;
            }
        }
    }

    media /= count_elementos;

    return media;

}

void swap_variaveis(int * a, int * b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
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
