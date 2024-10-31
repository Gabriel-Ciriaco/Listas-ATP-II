#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char * nome;
    char * endereco;
    int idade;
} Cliente;

int main()
{
    Cliente * ptr_cliente;
    Cliente cliente;

    ptr_cliente = &cliente;

    ptr_cliente->nome = "Seu Cuca";
    ptr_cliente->endereco = "Rua Bundogan";

    ptr_cliente->idade = 25;

    printf("\nNome: %s\nEndereco: %s\nIdade: %d\n",
           cliente.nome, cliente.endereco, cliente.idade);

    return 0;
}
