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
  FILE * ordenado_bin;

  /**
   * O arquivo contém 3 pessoas do tipo Pessoa:
   * gabriel, danilo e roberto (respectivamente).
   */
  arquivo_bin = fopen("./lista4_ex13.bin", "r+b");

  if (arquivo_bin != NULL)
  {
    fseek(arquivo_bin, 0, SEEK_END);
    int num_pessoas = ftell(arquivo_bin) / sizeof(Pessoa);

    // Ordenaremos com Bubble Sort.
    for (int i = 0; i < num_pessoas; i++)
    {
      for (int j = 0; j < num_pessoas - i - 1; j++)
      {
        Pessoa p1;
        Pessoa p2;

        // Lendo a pessoa na posição j.
        fseek(arquivo_bin, j * sizeof(Pessoa), SEEK_SET);
        fread(&p1, sizeof(Pessoa), 1, arquivo_bin);

        // Lendo a pessoa na posição (j + 1).
        fseek(arquivo_bin, (j + 1) * sizeof(Pessoa), SEEK_SET);
        fread(&p2, sizeof(Pessoa), 1, arquivo_bin);

        // Ordenação em ordem alfabética.
        if (strcmp(p1.nome, p2.nome) > 0)
        {
          // Salvamos a pessoa da posição (j + 1) na posição j.
          fseek(arquivo_bin, j * sizeof(Pessoa), SEEK_SET);
          fwrite(&p2, sizeof(Pessoa), 1, arquivo_bin);

          // Salvamos a pessoa da posição j na posição (j + 1).
          fseek(arquivo_bin, (j + 1) * sizeof(Pessoa), SEEK_SET);
          fwrite(&p1, sizeof(Pessoa), 1, arquivo_bin);
        }
      }
    }

    /**
     * Apenas para visualização:
     */
    printf("Registros ordenados: \n");
    for (int i = 0; i < 3; i++)
    {
      /*
      printf("Pessoa:\n -Nome : %s\n -Idade: %d\n\n",
             pessoas[i].nome,
             pessoas[i].idade);*/
    }
  }
  else
  {
    printf("Nao foi possivel abrir o arquivo.");
  }

  fclose(arquivo_bin);

  return 0;
}