#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>

#define LARGURA 5
#define ALTURA 5

void imprimir_matriz(int * ptr_matriz, int largura, int altura);

int regras_universo(int estado_celula, int qtd_vizinhos_vivos);

void aplicar_regras(int * ptr_universo);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int universo[LARGURA][ALTURA] = {{0, 0, 0, 1, 1},
                                     {0, 1, 0, 0, 1},
                                     {0, 1, 0, 0, 1},
                                     {0, 1, 1, 1, 0},
                                     {0, 0, 0, 1, 0}};

    int geracoes = 0;

    printf("Digite o número de gerações: ");

    scanf("%d", &geracoes);


    for (int i = 0; i < geracoes; i++)
    {
        system("cls");
        printf("Geração: %d\n\n", i + 1);
        imprimir_matriz(universo, LARGURA, ALTURA);
        aplicar_regras(universo);
        usleep(100 * 1000);
    }

    return 0;
}

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
    Uma célula é viva quando seu estado é 1.
    Uma célula é morta quando seu estado é 0.
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
            return 1;
        }
    }
    else if (estado_celula == 0)
    {
        if (qtd_vizinhos_vivos == 3)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

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
