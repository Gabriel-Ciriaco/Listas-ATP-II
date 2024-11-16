#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
  char nome[50];
  int idade;
} Pessoa;

int main()
{
  FILE * arquivo_bin;

  /* Este arquivo possui 3 Pessoas armazenadas */
  arquivo_bin = fopen("./lista4_ex9.bin", "rb");

  if (arquivo_bin != NULL)
  {
    // Posicionamos um ponteiro no final do arquivo.
    fseek(arquivo_bin, 0, SEEK_END);

    // Retornamos o valor da posição atual do ponteiro no arquivo.
    long int tamanho_arquivo = ftell(arquivo_bin);

    int registros = tamanho_arquivo / sizeof(Pessoa);

    printf("Numero de registros: %d", registros);
  }
  else
  {
    printf("Nao foi possivel salvar o arquivo.");
  }

  fclose(arquivo_bin);
  return 0;
}
