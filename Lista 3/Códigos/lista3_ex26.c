#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
  char nome[50];
  char disciplina[100];
  int salario;
} Professor;


int main()
{
  Professor professor;

  strcpy(professor.nome, "Roberto");
  strcpy(professor.disciplina, "ATP");

  professor.salario = 2000;

  printf("Nome: %s\nDiscipilina: %s\nSalario: %d\n",
    professor.nome,
    professor.disciplina,
    professor.salario
  );

  return 0;
}