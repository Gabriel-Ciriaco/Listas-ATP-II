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
  FILE * ordenado_bin;

  /**
   * O arquivo contém 3 pessoas do tipo Pessoa:
   * gabriel, danilo e roberto (respectivamente).
   */
  arquivo_bin = fopen("./lista4_ex13.bin", "rb");
  ordenado_bin = fopen("./lista4_ex13_temp.bin", "wb");

  if (arquivo_bin != NULL &&
      ordenado_bin != NULL)
  {
    Pessoa pessoas[NUM_PESSOAS];

    fread(pessoas, sizeof(Pessoa), NUM_PESSOAS, arquivo_bin);

    // Ordenaremos pelo nome em ordem alfabética.
    for (int i = 0; i < NUM_PESSOAS; i++)
    {
      for (int j = 0; j < NUM_PESSOAS; j++)
      {
        if (strcmp(pessoas[i].nome, pessoas[j].nome) < 0)
        {
          Pessoa temp;

          temp = pessoas[i];
          pessoas[i] = pessoas[j];
          pessoas[j] = temp;
        }
      }
    }

    /**
     * Apenas para visualização:
     */
    printf("Registros ordenados: \n");
    for (int i = 0; i < NUM_PESSOAS; i++)
    {
      printf("Pessoa:\n -Nome : %s\n -Idade: %d\n\n",
             pessoas[i].nome,
             pessoas[i].idade);
    }

    fwrite(pessoas, sizeof(Pessoa), NUM_PESSOAS, ordenado_bin);

    fclose(arquivo_bin);
    fclose(ordenado_bin);

    remove("./lista4_ex13.bin");
    rename("./lista4_ex13_temp.bin", "./lista4_ex13.bin");
  }
  else
  {
    printf("Nao foi possivel abrir o(s) arquivo(s).");
  }

  fclose(arquivo_bin);
  fclose(ordenado_bin);

  return 0;
}