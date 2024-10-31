#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    float salario;
    char departamento[100];
} Funcionario;

int main()
{
    printf("O tamanho da estrutura eh: %d\n",
            sizeof(Funcionario));

    return 0;
}