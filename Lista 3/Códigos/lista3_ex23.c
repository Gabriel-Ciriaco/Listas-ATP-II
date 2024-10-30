#include <stdio.h>

enum meses
{
  JANEIRO = 1,
  FEVEREIRO,
  MARCO,
  ABRIL,
  MAIO,
  JUNHO,
  JULHO,
  AGOSTO,
  SETEMBRO,
  OUTUBRO,
  NOVEMBRO,
  DEZEMBRO,
};

int main()
{
  printf("%d %d %d %d %d %d %d %d %d %d %d %d",
     JANEIRO,
     FEVEREIRO,
     MARCO,
     ABRIL,
     MAIO,
     JUNHO,
     JULHO,
     AGOSTO,
     SETEMBRO,
     OUTUBRO,
     NOVEMBRO,
     DEZEMBRO);

  return 0;
}