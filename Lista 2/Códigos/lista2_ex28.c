#include <stdio.h>

#define LARGURA 3
#define ALTURA 3


void imprimir_matriz(int * ptr_matriz, int largura, int altura);

void swap_variaveis(int * a, int * b);

void ordenar_matriz(int * ptr_matriz, int largura, int altura);

int binary_search(int elemento, int matriz[LARGURA][ALTURA]);


int main()
{
    int matriz[LARGURA][ALTURA] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int elemento = 0;

    printf("A matriz eh: ");

    imprimir_matriz(matriz, LARGURA, ALTURA);

    ordenar_matriz(matriz, LARGURA, ALTURA);

    printf("Digite um elemento para busca-lo: ");
    scanf("%d", &elemento);

    if (binary_search(elemento, matriz) == 1)
    {
        printf("O elemento esta presente na matriz.");
    }
    else
    {
        printf("O elemento nao esta presente na matriz.");
    }

    return 0;
}

int binary_search(int elemento, int matriz[LARGURA][ALTURA])
{
    ordenar_matriz(matriz, LARGURA, ALTURA);

    // Vamos buscar o elemento linha por linha com binary search.
    for (int i = 0; i < LARGURA; i++)
    {
        int left = 0;
        int right = ALTURA - 1;

        while (left <= right)
        {
            int pivot = (int) (left + right) / 2;

            // O elemento está mais para a esquerda.
            if (elemento < matriz[i][pivot])
            {
                right--;
            }

            // O elemento está mais para a direita.
            if (elemento > matriz[i][pivot])
            {
                left++;
            }

            if (elemento == matriz[i][pivot])
            {
                return 1;
            }
        }
    }

    // O elemento não está presente na matriz.
    return 0;
}

void ordenar_matriz(int * ptr_matriz, int largura, int altura)
{
    int (* matriz)[ALTURA] = ptr_matriz;

    int temp_vect_size = largura * altura;

    int temp_vect[temp_vect_size];

    // Copiar a matriz para um vetor
    for (int i = 0; i < largura; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            temp_vect[i * largura + j] = matriz[i][j];
        }
    }

    // Ordernar o vetor
    for (int i = 0; i < temp_vect_size; i++)
    {
        for (int j = i; j < temp_vect_size; j++)
        {
            if (temp_vect[i] > temp_vect[j])
            {
                swap_variaveis(&temp_vect[i], &temp_vect[j]);
            }
        }
    }

    // Copiar o vetor para a matriz
    for (int i = 0; i < largura; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            matriz[i][j] = temp_vect[i * largura + j];
        }
    }

}


/* Utilizamos o XOR para trocar os valores */
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
