#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char nome[100];
    char endereco[50];
    int idade;
} Cliente;


int main()
{
    Cliente cliente;

    printf("Digite o nome do cliente: ");
    gets(cliente.nome);

    printf("Digite o nome do endereco do cliente: ");
    gets(cliente.endereco);

    printf("Digite a idade do cliente: ");
    scanf("%d", &cliente.idade);

    printf("\nNome: %s\nEndereco: %s\nIdade: %d\n",
           cliente.nome, cliente.endereco, cliente.idade);

    return 0;
}
