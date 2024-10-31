#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char * nome;
    char * departamento;
    float salario;
} Funcionario;

void atualizar_funcionario(Funcionario * funcionario,
                     char * nome,
                     char * departamento,
                     float salario)
{
  funcionario->nome = nome;
  funcionario->departamento = departamento;
  funcionario->salario = salario;
}

int main()
{
  Funcionario funcionario;

  atualizar_funcionario(&funcionario, "Pedroso", "S.T.I", 10500.01);

  printf("\nNome: %s\nDepartamento: %s\nSalario: R$%.2f",
  funcionario.nome, funcionario.departamento, funcionario.salario);

  return 0;
}
