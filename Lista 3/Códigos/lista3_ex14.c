#include <stdio.h>
#include <stdlib.h>


typedef struct
{
  char nome[50];
  int idade;
  char endereco[50];
} Cliente;


int main()
{
  Cliente cliente;

  printf("Digite o nome do cliente: ");
  gets(cliente.nome);

  printf("Digite a idade do cliente: ");
  scanf("%d", &cliente.idade);

  setbuf(stdin, NULL);

  printf("Digite o nome do endereco do cliente: ");
  gets(cliente.endereco);

  printf("O nome do cliente: %s\n", cliente.nome);

  printf("A idade do cliente: %d\n", cliente.idade);
  
  printf("O endereco do cliente: %s\n", cliente.endereco);


  return 0;
}