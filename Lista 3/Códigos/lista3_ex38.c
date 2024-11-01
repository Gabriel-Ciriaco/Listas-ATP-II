#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
  char nome[50];
  char email[100];
  int telefone;
} Contato;


int main()
{
  Contato contato;

  strcpy(contato.nome, "Flavio");
  strcpy(contato.email, "flavindopneu@gmail.com");

  contato.telefone = 949513511;

  printf("Nome: %s\nEmail: %s\nTelefone: %d\n",
    contato.nome,
    contato.email,
    contato.telefone
  );

  return 0;
}