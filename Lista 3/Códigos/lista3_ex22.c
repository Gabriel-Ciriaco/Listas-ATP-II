#include <stdio.h>
#include <stdlib.h>

union Teste
{
  int valor;
  char letra;
};

int main()
{
  union Teste teste;

  teste.valor = 15;

  printf("O valor da Union eh: %d\n",
    teste.valor
  );
  
  teste.letra = 'G';

  printf("O valor da letra da union eh: %c",
    teste.letra
  );


  return 0;
}
