#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE * arquivo;

  arquivo = fopen("./lista4_ex3.txt", "r");

  if (arquivo != NULL)
  {
    char linha[100];
    int contador_linha = 0;

    char c;
    while(fscanf(arquivo, "%c", &c) != EOF)
    {
      if (c == '\n' || contador_linha == 0)
      {
        contador_linha++;
      }

      printf("%c", c);
    }

    printf("\nExistem %d linhas no txt", contador_linha);
  }
  else
  {
    printf("Nao foi possivel ler o arquivo");
  }

  fclose(arquivo);

  return 0;
}