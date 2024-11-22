#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
  FILE * arquivo_leitura_1;
  FILE * arquivo_leitura_2;

  arquivo_leitura_1 = fopen("./lista4_ex26_1.txt", "r");
  arquivo_leitura_2 = fopen("./lista4_ex26_2.txt", "r");

  if (arquivo_leitura_1 != NULL &&
      arquivo_leitura_2 != NULL)
  {
    char linha_1[100];
    char linha_2[100];

    while(fgets(linha_1, 100, arquivo_leitura_1))
    {
      fgets(linha_2, 100, arquivo_leitura_2);

      if (strcmp(linha_1, linha_2) != 0)
      {
        printf("\nTXT_1: %s", linha_1);
        printf("virou\n");
        printf("TXT_2: %s", linha_2);
      }
      else
      {
        printf("\n%s", linha_1);
      }
    }
  }
  else
  {
    printf("Nao foi possivel abrir o(s) arquivo(s).");
  }

  fclose(arquivo_leitura_1);
  fclose(arquivo_leitura_2);

  return 0;
}