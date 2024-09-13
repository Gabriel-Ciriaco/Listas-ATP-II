#include <stdio.h>

#define LARGURA 3
#define ALTURA 3


void imprimir_matriz(int * ptr_matriz, int largura, int altura);

int eh_primo(int n);

int num_primo(int n_primo);

void preencher_primo(int * ptr_matriz);

void igualar_um(int * ptr_matriz);


int main()
{
    int matriz[LARGURA][ALTURA] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rot_matriz[LARGURA][ALTURA];

    printf("A matriz eh: ");

    imprimir_matriz(matriz, LARGURA, ALTURA);

    printf("A matriz com primos eh: ");

    preencher_primo(matriz);

    imprimir_matriz(matriz, LARGURA, ALTURA);

    printf("Igualando ela a um: ");

    igualar_um(matriz);

    imprimir_matriz(matriz, LARGURA, ALTURA);

    return 0;
}

void igualar_um(int * ptr_matriz)
{
    int (* matriz)[ALTURA] = ptr_matriz;

    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            matriz[i][j] = 1;
        }
    }
}

void preencher_primo(int * ptr_matriz)
{
    int (* matriz)[ALTURA] = ptr_matriz;

    int count = 1;

    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            matriz[i][j] = num_primo(count);

            count++;
        }
    }
}

/*
    Ficamos em loop até achar o enésimo primo.
*/
int num_primo(int n_primo)
{
    int i = 0;
    int qtd_primo = 0;
    int last_primo = 2;

    while (qtd_primo < n_primo)
    {
        if (eh_primo(i) == 1)
        {
            last_primo = i;
            qtd_primo++;
        }

        i++;

    }

    return last_primo;
}

int eh_primo(int n)
{
    if (n == 0 || n == 1 )
    {
        return 0;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
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
