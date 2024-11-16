#include <stdio.h>
#include <stdlib.h>


int main()
{
  FILE * arquivo_bin;

  arquivo_bin = fopen("./lista4_ex08.bin", "rb");

  if (arquivo_bin != NULL)
  {
    char palavra[3];

    fread(palavra, sizeof(char), 3, arquivo_bin);

    printf("Palavra no arquivo binario: %s", palavra);  
  }
  else
  {
    printf("Nao foi possivel abrir o arquivo.");
  }

  fclose(arquivo_bin);

  return 0;
}
