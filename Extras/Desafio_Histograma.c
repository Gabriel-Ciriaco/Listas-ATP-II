#include <stdio.h>
#include <stdlib.h>

#define HISTO_MAX 10
#define NUM_QTD 1


int main()
{
    int tam = 0;

    printf("Digite o tamanho do vetor: ");

    scanf("%d", &tam);
    fflush(stdin);

    // Populando a sequência
    char seq[tam];

    printf("Digite uma sequencia de %d numeros de 1 a 9: ", tam);

    fgets(seq, tam + 1, stdin);

    printf("\n");

    // O Histograma é uma matrix com [NÚMERO][NUM_QTD]
    int histo[HISTO_MAX + 1][NUM_QTD];

    //Inicializando a matrix
    for (int num = 0; num < HISTO_MAX; num++)
    {
        histo[num][NUM_QTD] = 0;
    }

    int num_maior_qtd = 0;
    int maior_qtd = 0;

    // Contando as repetições e populando o histograma.
    for (int i = 0; i < tam; i++)
    {
        // Convertendo o número da sequência em int.
        int num = (int) seq[i] - 48;

        histo[num][NUM_QTD] += 1;

        int num_qtd = histo[num][NUM_QTD];

        if (maior_qtd < num_qtd)
        {
            num_maior_qtd = num;
            maior_qtd = num_qtd;
        }
    }

    // Teto determina os asteriscos a serem printados.
    int teto = maior_qtd;

    for (int i = 0; i < maior_qtd; i++)
    {
        for (int cur_num = 1; cur_num < HISTO_MAX; cur_num++)
        {
            int qtd = histo[cur_num][NUM_QTD];

            if (qtd >= teto)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }

        teto--;
        printf("\n");
    }

    printf("1 2 3 4 5 6 7 8 9");

    return 0;
}
