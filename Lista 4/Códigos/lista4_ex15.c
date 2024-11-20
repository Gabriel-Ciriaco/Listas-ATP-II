#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PESSOAS 3


typedef struct
{
  char nome[50];
  int idade;
} Pessoa;


void atualizar_dados(Pessoa * pessoa, char * novo_nome, int nova_idade)
{
  strcpy(pessoa->nome, novo_nome);
  pessoa->idade = nova_idade;
}

int main()
{
  FILE * arquivo_bin;
  FILE * atualizado_bin;

  /**
   * O arquivo contém 3 pessoas do tipo Pessoa:
   * gabriel, danilo e roberto (respectivamente).
   */
  arquivo_bin = fopen("./lista4_ex15.bin", "rb");
  atualizado_bin = fopen("./lista4_ex15_temp.bin", "wb");

  if (arquivo_bin != NULL &&
      atualizado_bin != NULL)
  {
    Pessoa pessoas[NUM_PESSOAS];

    fread(pessoas, sizeof(Pessoa), NUM_PESSOAS, arquivo_bin);

    // Atualizando o registro 1.
    atualizar_dados(&pessoas[0], "Valdair", 90);

    /**
     * Apenas para visualização:
     */
    printf("Registro(s) atualizado(s): \n");
    for (int i = 0; i < NUM_PESSOAS; i++)
    {
      printf("Pessoa:\n -Nome : %s\n -Idade: %d\n\n",
             pessoas[i].nome,
             pessoas[i].idade);
    }

    fwrite(pessoas, sizeof(Pessoa), NUM_PESSOAS, atualizado_bin);

    fclose(arquivo_bin);
    fclose(atualizado_bin);

    remove("./lista4_ex15.bin");
    rename("./lista4_ex15_temp.bin", "./lista4_ex15.bin");
  }
  else
  {
    printf("Nao foi possivel abrir o(s) arquivo(s).");
  }

  fclose(arquivo_bin);
  fclose(atualizado_bin);

  return 0;
}