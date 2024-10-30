#include <stdio.h>

#define NUM_FUNCIONARIOS 5

typedef struct
{
  char nome[50];
  int idade;
  int registro;
  int telefone;
} Funcionario;


int main()
{
  Funcionario funcionarios[NUM_FUNCIONARIOS];

  for (int i = 0; i < NUM_FUNCIONARIOS; i++)
  {
    printf("Digite o nome do funcionario %d: ", i + 1);
    gets(funcionarios[i].nome);

    printf("Digite a idade do funcionario %d: ", i + 1);
    scanf("%d", &funcionarios[i].idade);

    printf("Digite a registro do funcionario %d: ", i + 1);
    scanf("%d", &funcionarios[i].registro);

    printf("Digite o telefone do funcionario %d: ", i + 1);
    scanf("%d", &funcionarios[i].telefone);

    setbuf(stdin, NULL);
  }

  for (int i = 0; i < NUM_FUNCIONARIOS; i++)
  {
    printf("\nO nome do funcionario %d eh: %s\n", i + 1, funcionarios[i].nome);

    printf("A idade do funcionario %d eh: %d\n", i + 1, funcionarios[i].idade);

    printf("A registro do funcionario %d eh: %d\n", i + 1, funcionarios[i].registro);

    printf("O telefone do funcionario %d eh: %d\n\n", i + 1, funcionarios[i].telefone);
  }
  return 0;
}