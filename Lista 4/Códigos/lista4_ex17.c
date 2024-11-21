#include <stdio.h>
#include <stdlib.h>


int main()
{
  FILE * arquivo_leitura;

  arquivo_leitura = fopen("./lista4_ex17.txt", "r");

  if (arquivo_leitura != NULL)
  {
    int soma = 0;

    char string[100];
    while(fgets(string, 100, arquivo_leitura))
    {
      printf("Numero encontrado: %d\n", atoi(string));
      soma += atoi(string);
    }

    printf("A soma eh: %d\n", soma);
  }
  else
  {
    printf("Nao foi possivel abrir o arquivo.");
  }

  fclose(arquivo_leitura);

  return 0;
}