#include <stdio.h>

#define LARGURA 3
#define ALTURA 3


void imprimir_matriz(float * ptr_matriz, int largura, int altura);

int eh_vandermonde(float * ptr_matriz);


int main()
{
    float matriz[LARGURA][ALTURA] = {{1, 2, 4}, {1, -3, 9}, {1, 0.50, 0.25}};

    printf("A matriz eh: ");

    imprimir_matriz(matriz, LARGURA, ALTURA);

    if (eh_vandermonde(matriz) == 1)
    {
        printf("A matriz eh de Vandermonde.\n");
    }
    else
    {
        printf("A matriz nao eh de Vandermonde.\n");
    }


    return 0;
}

/*
    Matriz de Vandermonde é a que os termos de cada linha
    estão em progressão geométrica.
*/
int eh_vandermonde(float * ptr_matriz)
{
    float (* matriz)[ALTURA] = ptr_matriz;

    for (int i = 0; i < LARGURA; i++)
    {
        float first_element = matriz[i][0];

        if (first_element != 1.0)
        {
            return 0;
        }

        float ratio = matriz[i][1] / first_element;

        for (int j = 0; j < ALTURA; j++)
        {
            if (j < ALTURA - 1)
            {
                float cur_ratio = matriz[i][j + 1] / matriz[i][j];

                // Se encontramos alguma razão diferente, não é P.G
                if (cur_ratio != ratio)
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

void imprimir_matriz(float * ptr_matriz, int largura, int altura)
{
    // Criamos um ponteiro que aponta para um array de tamanho altura.
    float (* matriz)[altura] = ptr_matriz;

    printf("\n");

    for (int i = 0; i < largura; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            printf(" %.2f ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}
