#include <stdio.h>
#include <stdlib.h>


void ler_e_copiar_arquivo(FILE * destino, FILE * fonte)
{
  char c;
  while (fscanf(fonte, "%c", &c) != EOF)
  {
    fprintf(destino, "%c", c);
  }

  printf("Arquivo salvo com sucesso!\n");
}

int main()
{
  FILE * arquivo_1;
  FILE * arquivo_2;
  FILE * arquivo_final;


  arquivo_1 = fopen("./lista4_ex5_arq1.txt", "r");
  arquivo_2 = fopen("./lista4_ex5_arq2.txt", "r");

  arquivo_final = fopen("./lista4_ex5_final.txt", "w");

  if (arquivo_1 != NULL
      && arquivo_2 != NULL
      && arquivo_final != NULL)
  {
    ler_e_copiar_arquivo(arquivo_final, arquivo_1);
    ler_e_copiar_arquivo(arquivo_final, arquivo_2);
  }
  else
  {
    printf("Nao foi possivel abrir o(s) arquivo(s)");
  }

  fclose(arquivo_1);
  fclose(arquivo_2);
  fclose(arquivo_final);

  return 0;
}