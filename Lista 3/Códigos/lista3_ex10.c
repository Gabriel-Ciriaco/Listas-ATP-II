#include <stdio.h>
#include <stdlib.h>

union Teste
{
  int id;
  float salario;
};

int main()
{
  union Teste teste;

  teste.id = 15;

  printf("O id da Union eh: %d\n",
    teste.id
  );

  teste.salario = 17.05;

  printf("O valor da salario da union eh: %.2f",
    teste.salario
  );

  return 0;
}
