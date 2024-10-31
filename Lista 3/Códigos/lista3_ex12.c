#include <stdio.h>

#define NUM_ALUNOS 2

typedef struct
{
  char nome[50];
  int idade;
  int matricula;
  int telefone;
} Aluno;


int main()
{
  Aluno alunos[NUM_ALUNOS];

  for (int i = 0; i < NUM_ALUNOS; i++)
  {
    printf("Digite o nome do aluno %d: ", i + 1);
    gets(alunos[i].nome);

    printf("Digite a idade do aluno %d: ", i + 1);
    scanf("%d", &alunos[i].idade);

    printf("Digite a matricula do aluno %d: ", i + 1);
    scanf("%d", &alunos[i].matricula);

    printf("Digite o telefone do aluno %d: ", i + 1);
    scanf("%d", &alunos[i].telefone);

    setbuf(stdin, NULL);
  }

  for (int i = 0; i < NUM_ALUNOS; i++)
  {
    printf("O nome do aluno %d eh: %s\n", i + 1, alunos[i].nome);

    printf("A idade do aluno %d eh: %d\n", i + 1, alunos[i].idade);

    printf("A matricula do aluno %d eh: %d\n", i + 1, alunos[i].matricula);

    printf("O telefone do aluno %d eh: %d\n\n", i + 1, alunos[i].telefone);
  }

  return 0;
}