#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define LARGURA 5
#define ALTURA 5

void imprimir_matriz(int * ptr_matriz, int largura, int altura);

int regras_universo(int estado_celula, int qtd_vizinhos_vivos);

void aplicar_regras(int * ptr_universo);


int main()
{
    setlocale(LC_ALL, "portuguese");

    int universo[LARGURA][ALTURA] = {{0, 0, 0, 0, 0},
                                     {0, 0, 1, 0, 0},
                                     {0, 1, 1, 0, 0},
                                     {0, 0, 1, 1, 0},
                                     {0, 0, 0, 0, 0}};

    int geracoes = 0;

    printf("Digite o número de gerações do jogo de Conway: ");
    scanf("%d", &geracoes);

    for (int i = 0; i < geracoes; i++)
    {
        // Limpar o console.
        system("cls");

        // Imprimir geração.
        printf("Geração: %d\n\n", i + 1);

        // Imprimir o universo.
        imprimir_matriz(universo, LARGURA, ALTURA);

        // Atualizar o universo.
        aplicar_regras(universo);

        // Esperar 1 segundo.
        sleep(1);
    }

    return 0;
}

/*
    Aplica as regras do jogo de Conway no nosso universo,
    ou seja, muda o estado das células para vivo ou morto
    de acordo com as regras impostas.
*/
void aplicar_regras(int  * ptr_universo)
{
    int (* universo)[ALTURA] = ptr_universo;

    int novo_universo[LARGURA][ALTURA];

    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            int estado_celula = universo[i][j];

            int qtd_vizinhos_vivos = 0;

            // Vizinho direito
            if (j < ALTURA - 1)
            {
                // Vizinho direito
                qtd_vizinhos_vivos += universo[i][j + 1];

                // Vizinho direito cima
                if (i > 0)
                {
                    qtd_vizinhos_vivos += universo[i - 1][j + 1];
                }

                // Vizinho direito baixo
                if (i < LARGURA - 1)
                {
                    qtd_vizinhos_vivos += universo[i + 1][j + 1];
                }
            }

            // Vizinho esquerdo
            if (j > 0)
            {
                // Vizinho esquerdo
                qtd_vizinhos_vivos += universo[i][j - 1];

                // Vizinho esquerdo cima
                if (i > 0)
                {
                    qtd_vizinhos_vivos += universo[i - 1][j - 1];
                }

                // Vizinho esquerdo baixo
                if (i < LARGURA - 1)
                {
                     qtd_vizinhos_vivos += universo[i + 1][j - 1];
                }
            }

            // Vizinho cima
            if (i > 0)
            {
                qtd_vizinhos_vivos += universo[i - 1][j];
            }

            // Vizinho baixo
            if (i < LARGURA - 1)
            {
                 qtd_vizinhos_vivos += universo[i + 1][j];
            }

            // Mudar estado da célula atual
            novo_universo[i][j] = regras_universo(estado_celula, qtd_vizinhos_vivos);
        }
    }

    // Copiar o novo universo para o universo atual.
    for (int i = 0; i < LARGURA; i++)
    {
        for (int j = 0; j < ALTURA; j++)
        {
            universo[i][j] = novo_universo[i][j];
        }
    }
}

/*
    Uma célula é VIVA quando seu estado é UM.
    Uma célula é MORTA quando seu estado é ZERO.

    As regras são as seguintes:

    1 - Qualquer célula viva com menos de dois vizinhos vivos morre.

    2 - Qualquer célula viva com dois ou três vizinhos vivos vive.

    3 - Qualquer célula viva com mais de três vizinhos morre.

    4 - Qualquer célula morta com exatos três vizinhos vivos renasce.

*/
int regras_universo(int estado_celula, int qtd_vizinhos_vivos)
{
    if (estado_celula == 1)
    {
        if (qtd_vizinhos_vivos < 2 ||
            qtd_vizinhos_vivos > 3)
        {
            // A célula morre
            return 0;
        }

        if (qtd_vizinhos_vivos == 2 ||
            qtd_vizinhos_vivos == 3)
        {
            // A célula vive
            return 1;
        }
    }
    else if (estado_celula == 0)
    {
        if (qtd_vizinhos_vivos == 3)
        {
            // A célula vive
            return 1;
        }

        return 0;
    }
}

/*
    Célula viva: '*'.

    Célula morta: '.'.
*/
void imprimir_matriz(int * ptr_matriz, int largura, int altura)
{
    // Criamos um array de ponteiros com o tamanho da altura.
    int (* matriz)[altura] = ptr_matriz;

    for (int i = 0; i < largura; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            char celula = matriz[i][j] == 1 ? '*' : '.';

            printf(" %c " , celula);
        }
        printf("\n");
    }

    printf("\n");
}
