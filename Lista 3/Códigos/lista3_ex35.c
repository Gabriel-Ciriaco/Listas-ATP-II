#include <stdio.h>
#include <stdlib.h>

enum estacoes
{
  VERAO = 1,
  OUTONO,
  INVERNO,
  PRIMAVERA
};

int main()
{
  int estacao = VERAO;

  printf("%d %d %d %d",
    VERAO,
    OUTONO,
    INVERNO,
    PRIMAVERA
  );

  return 0;
}