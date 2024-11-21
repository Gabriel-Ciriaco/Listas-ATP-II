#include <stdio.h>
#include <stdlib.h>


int main()
{
  FILE * arquivo_leitura;

  arquivo_leitura = fopen("./lista4_ex18.txt", "r");

  if (arquivo_leitura != NULL)
  {
    int menor = 0;
    int maior = 0;

    char string[100];

    while(fgets(string, 100, arquivo_leitura))
    {
      int num = atoi(string);
      if (num < menor)
      {
        menor = num;
      }

      if (num > maior)
      {
        maior = num;
      }
    }

    printf("O menor num eh: %d\n", menor);
    printf("O maior num eh: %d", maior);
  }
  else
  {
    printf("Nao foi possivel abrir o arquivo.");
  }

  fclose(arquivo_leitura);

  return 0;
}