#include <stdio.h>
#include <stdlib.h>


/**
 * O caracter encontrado será exibido entre astericos.
 */
void buscar_e_exibir_caracter(FILE * arquivo, char caracter)
{
  char c;
  while (fscanf(arquivo, "%c", &c) != EOF)
  {
    if (c == caracter)
    {
      printf("*%c*", c);
    }
    else
    {
      printf("%c", c);
    }
  }
}

int main()
{
  FILE * arquivo;

  arquivo = fopen("./lista4_ex6.txt", "r");

  if (arquivo != NULL)
  {
    buscar_e_exibir_caracter(arquivo, 'r');
  }
  else
  {
    printf("Nao foi possivel abrir o arquivo.");
  }

  fclose(arquivo);

  return 0;
}