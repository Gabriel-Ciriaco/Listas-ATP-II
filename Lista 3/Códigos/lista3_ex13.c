#include <stdio.h>
#include <stdlib.h>


typedef struct
{
  char nome[50];
  float salario;
  char departamento[50];
} Funcionario;


int main()
{

  Funcionario funcionario;

  printf("Digite o nome do funcionario: ");
  gets(funcionario.nome);

  printf("Digite o salario do funcionario: ");
  scanf("%f", &funcionario.salario);

  setbuf(stdin, NULL);

  printf("Digite o nome do departamento do funcionario: ");
  gets(funcionario.departamento);

  printf("O nome do funcionario: %s\n", funcionario.nome);

  printf("O salario do funcionario: %.2f\n", funcionario.salario);
  
  printf("O departamento do funcionario: %s\n", funcionario.departamento);


  return 0;
}