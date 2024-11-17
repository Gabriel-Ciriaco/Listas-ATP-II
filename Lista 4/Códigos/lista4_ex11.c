#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
  FILE * arquivo_bin;

  /*
    O arquivo binário possui a seguinte estrutura:
      - string "Gabriel" : 8 bytes
      - int idade: 4 bytes
  */
  arquivo_bin = fopen("./lista4_ex11.bin", "rb");

  if (arquivo_bin != NULL)
  {
    int idade;

    fseek(arquivo_bin, sizeof(char) * 8, SEEK_SET);

    fread(&idade, sizeof(int), 1, arquivo_bin);

    printf("Idade: %d", idade);
  }
  else
  {
    printf("Nao foi possivel abrir o arquivo");
  }

  fclose(arquivo_bin);

  return 0;
}
