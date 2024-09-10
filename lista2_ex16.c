#include <stdio.h>

#define LARGURA 5
#define ALTURA 5


void imprimir_matriz(int matriz[LARGURA][ALTURA]);

void preencher_primos(int matriz[LARGURA][ALTURA]);

int num_primo(int n_pos);

int eh_primo(int n);

int main()
{
    int matriz[LARGURA][ALTURA] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    printf("A matriz eh: \n");
    imprimir_matriz(matriz);

    preencher_primos(matriz);

    printf("A matriz com primos eh:\n");

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

void preencher_primos(int matriz[LARGURA][ALTURA])
{
    /*
        Contador para o  N-ésimo primo
        que queremos, por exemplo, quando
        primos = 2, pegaremos o segundo número primo existente.
    */
    int primos = 1;

    for (int i = 0; i < LARGURA; i++)
    {
        for(int j = 0; j < ALTURA; j++)
        {
            matriz[i][j] = num_primo(primos);
            primos++;
        }
    }
}

/* Retorna o n_pos número primo.*/
int num_primo(int n_pos)
{
    // num_primo(1) = 2;
    // num_primo(2) = 3;
    // num_primo(3) = 5;
    // num_primo(4) = 7;
    // num_primo(5) = 11;

    int num = 1;

    /*
        Iniciamos um contador com a posição,
        por exemplo, se n_pos = 5, então rodaremos
        o while até chegar no quinto número primo.
    */
    int count = n_pos;

    while(count != 0)
    {
        num++;

        if (eh_primo(num) == 1)
        {
            count--;
        }
    }

    return num;
}

/* Verifica se o número é primo.*/
int eh_primo(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            // O número não é primo.
            return 0;
        }
    }

    // O número é primo.
    return 1;
}
