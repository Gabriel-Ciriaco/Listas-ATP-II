#include <stdio.h>
#include <stdlib.h>


int main()
{
  FILE * arquivo_leitura;

  arquivo_leitura = fopen("./lista4_ex19.txt", "r");

  if (arquivo_leitura != NULL)
  {
    // Deixamos o ponteiro no final do arquivo.
    fseek(arquivo_leitura, 0, SEEK_END);

    int tamanho_do_arquivo = ftell(arquivo_leitura);

    tamanho_do_arquivo == 0
     ? printf("O arquivo esta vazio.")
     : printf("O arquivo nao esta vazio");
  }
  else
  {
    printf("Nao foi possivel abrir o arquivo");
  }

  fclose(arquivo_leitura);

  return 0;
}