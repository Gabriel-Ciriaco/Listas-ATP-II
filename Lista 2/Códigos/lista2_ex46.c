#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LARGURA 5
#define ALTURA 5


void imprimir_matriz(int * ptr_matriz, int largura, int altura);

void swap_variaveis(int * a, int * b);

void preencher_aleatorio(int * ptr_matriz, int max_rand);

int encontrar_segundo_maior(int matriz[LARGURA][ALTURA]);


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

    printf("O segundo maior elemento eh: %d",
           encontrar_segundo_maior(matriz));

    return 0;
}

/*
    Ordenamos a matriz e pegamos o segundo maior elemento.
*/
int encontrar_segundo_maior(int matriz[LARGURA][ALTURA])
{
    int ord_vect[LARGURA * ALTURA];

    // Copiar a matriz para um vetor.
    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            ord_vect[i * LARGURA + j] = matriz[i][j];
        }
    }

    // Ordenar o vetor.
    for (int i = 0; i < LARGURA * ALTURA; i++)
    {
        for (int j = 0; j < LARGURA * ALTURA; j++)
        {
            if (ord_vect[i] < ord_vect[j])
            {
                swap_variaveis(&ord_vect[i], &ord_vect[j]);
            }
        }
    }

    // Retornar o segundo maior elemento.
    return ord_vect[(LARGURA * ALTURA) - 2];

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
