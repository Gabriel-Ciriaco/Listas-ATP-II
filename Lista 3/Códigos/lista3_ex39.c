#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
  char nome[100];
  int telefone;
} Antiga;

typedef struct
{
  char nome[100];
  int telefone;
  int cpf;
} Nova;


int main()
{
  Antiga contato_old;
  Nova contato_novo;

  strcpy(contato_old.nome, "Pina");
  contato_old.telefone = 939124568;

  // Copiando para a nova estrutura.
  strcpy(contato_novo.nome, contato_old.nome);

  contato_novo.telefone = contato_old.telefone;
  contato_novo.cpf = 432219807;

  printf("Nome: %s\nTelefone: %d\nCPF: %d\n",
         contato_novo.nome,
         contato_novo.telefone,
         contato_novo.cpf);

  return 0;
}