#include <stdio.h>
#include <stdlib.h>

#define QTD_ALUNOS 5


typedef struct
{
  char nome[100];
  int idade;
  int RA;
} Aluno;

int main()
{
  FILE * arquivo;

  arquivo = fopen("./lista4_ex30.bin", "rb");

  if (arquivo != NULL)
  {
    Aluno alunos[QTD_ALUNOS];

    fread(alunos, sizeof(Aluno), QTD_ALUNOS, arquivo);

    for (int i = 0; i < QTD_ALUNOS; i++)
    {
      printf("O nome do aluno: %s\n",
             alunos[i].nome);

      printf("A idade do aluno: %d\n",
             alunos[i].idade);

      printf("O RA do aluno: %d\n\n",
             alunos[i].RA);
    }
  }
  else
  {
    printf("Nao foi possivel abrir o arquivo.");
  }

  fclose(arquivo);

  return 0;
}