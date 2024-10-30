#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
  char * nome;
  int codigo;
  int preco;
} Produto;


int main()
{
  Produto produto;

  printf("O tamanho da struct do produto eh: %d", sizeof(produto));

  return 0;
}