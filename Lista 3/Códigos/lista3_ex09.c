#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[100];
    int idade;
    int altura;
} Pessoa;

int main()
{
    printf("O tamanho da estrutura eh: %d",
            sizeof(Pessoa));
    return 0;
}