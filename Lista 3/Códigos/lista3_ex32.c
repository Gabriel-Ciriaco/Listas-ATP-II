#include <stdio.h>
#include <stdlib.h>

#define QTD_PRODUTOS 4

typedef struct
{
    char nome[100];
    int codigo;
    int preco;
} Produto;

int main()
{
    Produto produtos[QTD_PRODUTOS];

    for (int i = 0; i < QTD_PRODUTOS; i++)
    {
        printf("Digite o nome do produto %d: ", i+1);
        fgets(produtos[i].nome, 100, stdin);

        printf("Digite o codigo do produto %d: ", i+1);
        scanf("%d", &produtos[i].codigo);

        printf("Digite o preco do produto %d: ", i+1);
        scanf("%d", &produtos[i].preco);

        printf("\n");
        setbuf(stdin, NULL);
    }

    printf("\n");

    for (int i = 0; i < QTD_PRODUTOS; i++)
    {
        printf("Produto %d\n", i+1);
        printf("  - Nome: %s", produtos[i].nome);
        printf("  - Codigo: %d\n", produtos[i].codigo);
        printf("  - Preco: %d\n", produtos[i].preco);
    }

    return 0;
}
