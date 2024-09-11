#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CONJ_LEN 3


void conj_partes(char * conj, int i, char * subconj, int subconj_len);


int main()
{
    char conj[CONJ_LEN] = {'A', 'B', 'C'};
    int subconj[CONJ_LEN];


    conj_partes(conj, 0, subconj, 0);

    return 0;
}

/*
    Retorna o conjunto das partes com recursão.

    conj:        Nosso conjunto inicial.
    i:           Indice atual.
    subconj:     Subconjunto atual
    subconj_len: Tamanho atual do subconjunto
*/
void conj_partes(char * conj, int i, char * subconj, int subconj_len)
{
    // Chegamos ao final do caminho
    if (i == CONJ_LEN)
    {
        // Imprimir o subconjunto atual
        printf("{");

        for (int j = 0; j < subconj_len; j++)
        {
            if (j == subconj_len - 1)
            {
                printf("%c", subconj[j]);
            }
            else
            {
                printf("%c,", subconj[j]);
            }
        }
        printf("}\n");

        return;
    }

    // Elemento atual
    subconj[subconj_len] = conj[i];

    // Incluir o elemento atual no subconjunto
    conj_partes(conj, i + 1, subconj, subconj_len + 1);

    // Excluir o elemento atual do subconjunto
    conj_partes(conj, i + 1, subconj, subconj_len);
}
