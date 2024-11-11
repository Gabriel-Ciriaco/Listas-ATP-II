#include <stdio.h>
#include <stdlib.h>


int main()
{
  FILE * mensagem_arquivo;

  mensagem_arquivo = fopen("./lista4_ex2.txt", "r");

  if (mensagem_arquivo != NULL)
  {
    char string[100];

    while(fgets(string, 100, mensagem_arquivo))
    {
      printf("%s", string);
    }
  }
  else
  {
    printf("Nao foi possivel ler o arquivo");
  }

  fclose(mensagem_arquivo);
}