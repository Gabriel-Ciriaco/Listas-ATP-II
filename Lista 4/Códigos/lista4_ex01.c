#include <stdio.h>
#include <stdlib.h>


int main()
{
  FILE * mensagem_arquivo;

  mensagem_arquivo = fopen("./lista4_ex1.txt", "w");

  fprintf(mensagem_arquivo, "Nathan Lindo 123");

  if (mensagem_arquivo != NULL)
  {
    printf("O arquivo foi salvo com sucesso!");
  }
  else
  {
    printf("O arquivo nao foi salvo.");
  }

  fclose(mensagem_arquivo);

  return 0;
}