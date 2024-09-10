#include <stdio.h>

#define LARGURA 3
#define ALTURA 3


void imprimir_matriz(int matriz[LARGURA][ALTURA]);

void inverter_linha(int matriz[LARGURA][ALTURA], int linha_pos_original, int nova_linha_pos);

int main()
{
    int matriz[LARGURA][ALTURA] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printf("A matriz eh: \n");
    imprimir_matriz(matriz);

    //Inverter linha 2 e 3
    inverter_linha(matriz, 2, 3);

    printf("A matriz com as linhas invertidas eh:\n");
    imprimir_matriz(matriz);


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

void inverter_linha(int matriz[LARGURA][ALTURA], int linha_pos_original, int nova_linha_pos)
{
    /*
        Deixar a função para escrever
        a linha intuitivamente, por exemplo,
        inverter(matriz, 1, 2) vai inverter
        as linhas 1 com a 2.
    */

    linha_pos_original--;
    nova_linha_pos--;

    for (int j = 0; j < ALTURA; j++)
    {
        // Trocamos os elementos com um XOR.
        matriz[nova_linha_pos][j] ^= matriz[linha_pos_original][j];
        matriz[linha_pos_original][j] ^= matriz[nova_linha_pos][j];
        matriz[nova_linha_pos][j] ^= matriz[linha_pos_original][j];
    }
}
