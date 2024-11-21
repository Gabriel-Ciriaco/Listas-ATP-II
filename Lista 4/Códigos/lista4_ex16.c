#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PESSOAS 3


typedef struct
{
  char nome[50];
  int idade;
} Pessoa;


int main()
{
  FILE * arquivo_bin;
  FILE * deletar_bin;

  /**
   * O arquivo possui 3 registros de pessoas.
   */
  arquivo_bin = fopen("./lista4_ex16.bin", "rb");
  deletar_bin = fopen("./lista4_ex16_temp.bin", "wb");

  if (arquivo_bin != NULL &&
      deletar_bin != NULL)
  {
    Pessoa pessoas[NUM_PESSOAS];
    Pessoa pessoas_new[NUM_PESSOAS - 1];

    fread(pessoas, sizeof(Pessoa), NUM_PESSOAS, arquivo_bin);

    // Deletaremos o registro roberto
    int j = 0;
    for (int i = 0; i < NUM_PESSOAS; i++)
    {
      if (strcmp(pessoas[i].nome, "roberto") != 0)
      {
        pessoas_new[j++] = pessoas[i];
      }
    }

    fwrite(pessoas_new, sizeof(Pessoa), NUM_PESSOAS - 1, deletar_bin);

    fclose(arquivo_bin);
    fclose(deletar_bin);

    remove("./lista4_ex16.bin");
    rename("./lista4_ex16_temp.bin", "lista4_ex16.bin");
  }
  else
  {
    printf("Nao foi possivel abrir o(s) arquivo(s)");
  }

  fclose(arquivo_bin);
  fclose(deletar_bin);

  return 0;
}