#include <stdio.h>
#include <stdlib.h>


typedef struct
{
  int x;
  int y;
  int z;
} Vetor;


typedef struct
{
  Vetor pos;
} Ponto;

typedef struct
{
  Ponto a;
  Ponto b;
  Ponto c;
} Triangulo;



int main()
{
  Triangulo triangulo;

  triangulo.a.pos.x = 0;
  triangulo.a.pos.y = 0;
  
  triangulo.b.pos.x = 2;
  triangulo.b.pos.y = 2;

  triangulo.c.pos.x = 4;
  triangulo.c.pos.y = 4;

  printf("O Triangulo tem pontos na posicao:\n A: (%d, %d)\n B: (%d, %d)\n C: (%d, %d)",
    triangulo.a.pos.x,
    triangulo.a.pos.y,
    triangulo.b.pos.x,
    triangulo.b.pos.y,
    triangulo.c.pos.x,
    triangulo.c.pos.y
  );

  return 0;
}