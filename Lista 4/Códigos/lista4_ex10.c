#include <stdio.h>
#include <stdlib.h>


int main()
{
  FILE * arquivo_bin_1;
  FILE * arquivo_bin_2;

  // Possui apenas armazenado as strings "teste" e "cabra"
  arquivo_bin_1 = fopen("./lista10_1.bin", "rb");

  arquivo_bin_2 = fopen("./lista10_2.bin", "wb");

  if (arquivo_bin_1 != NULL &&
      arquivo_bin_2 != NULL)
  {
    int caracter;

    while((caracter = fgetc(arquivo_bin_1)) != EOF)
    {
      fputc(caracter, arquivo_bin_2);
    }
  }
  else
  {
    printf("Nao foi possivel abrir o(s) arquivo(s)");
  }

  fclose(arquivo_bin_1);
  fclose(arquivo_bin_2);

  return 0;
}