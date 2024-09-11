#include <stdio.h>

#define LARGURA 3
#define ALTURA 3


void imprimir_matriz(int * ptr_matriz, int largura, int altura);

int eh_esparsa(int matriz[LARGURA][ALTURA]);

int main()
{
    int matriz[LARGURA][ALTURA] = {{9, 0, 0}, {0, 5, 1}, {1, 0, 0}};

    printf("A matriz: \n");
    imprimir_matriz(matriz, LARGURA, ALTURA);

    if (eh_esparsa(matriz) == 1)
    {
        printf("eh esparsa.\n");
    }
    else
    {
        printf("nao eh esparsa.\n");
    }

    return 0;
}

/*
    Uma matriz é esparsa quando zero é o elemento mais presente.
*/
int eh_esparsa(int matriz[LARGURA][ALTURA])
{
    float count_zeros = 0;
    float total_elementos = LARGURA * ALTURA;

    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            if (matriz[i][j] == 0)
            {
                count_zeros++;
            }
        }
    }

    float media_zeros = count_zeros / total_elementos;

    return media_zeros >= 0.5 ? 1 : 0;
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
