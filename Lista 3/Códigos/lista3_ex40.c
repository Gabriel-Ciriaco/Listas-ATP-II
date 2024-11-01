#include <stdio.h>
#include <stdlib.h>


typedef struct
{
  int x;
  int y;
  int z;
} Ponto;


int main()
{
  Ponto ponto;

  ponto.x = 1;
  ponto.y = 2;
  ponto.z = 3;


  printf("X: %d\nY: %d\nZ: %d",
    ponto.x,
    ponto.y,
    ponto.z
  );

  return 0;
}