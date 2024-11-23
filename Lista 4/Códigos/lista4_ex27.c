#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTD_ARQUIVOS 3


/**
 * Cria um novo arquivo binário.
 */
void novo_arquivo_bin(char * arquivo_path,
                      char * dados,
                      int dados_size)
{
  FILE * arquivo_bin;

  arquivo_bin = fopen(arquivo_path, "wb");
  if (arquivo_bin != NULL)
  {
    fwrite(dados, dados_size, 1, arquivo_bin);

    printf("Foi criado o arquivo: %s\n", arquivo_path);
  }
  else
  {
    printf("[NOVO_ARQUIVO]: Nao foi possivel criar o arquivo %s",
           arquivo_path);
  }

  fclose(arquivo_bin);
}

/**
 * Divide o arquivo em n arquivos menores, sendo
 * n = chunk_size.
 */
void split_chunks(FILE * arquivo,
                  int chunk_size,
                  char * arquivo_nome)
{
  fseek(arquivo, 0, SEEK_END);
  int tamanho_arquivo = ftell(arquivo);

  rewind(arquivo);

  int chunk = (tamanho_arquivo / chunk_size) + 1;

  char * buffer;

  for (int i = 0; i < chunk_size; i++)
  {
    buffer = malloc(sizeof(char) * chunk);

    fread(buffer, chunk, 1, arquivo);

    // Criando o nome do arquivo menor.
    char arquivo_menor_nome[100];
    char id_arquivo[10];

    itoa(i + 1, id_arquivo, 10);

    strcpy(arquivo_menor_nome, arquivo_nome);

    strcat(arquivo_menor_nome, "_");
    strcat(arquivo_menor_nome, id_arquivo);
    strcat(arquivo_menor_nome, ".bin");

    // Criando um novo arquivo menor.
    novo_arquivo_bin(arquivo_menor_nome, buffer, chunk);
  }

  free(buffer);
}

int main()
{
  FILE * arquivo_bin;

  arquivo_bin = fopen("./lista4_ex27.bin", "rb");

  if (arquivo_bin != NULL)
  {
    split_chunks(arquivo_bin, QTD_ARQUIVOS, "./lista4_ex27.bin");
  }
  else
  {
    printf("Nao foi possivel abrir o arquivo.");
  }

  fclose(arquivo_bin);

  return 0;
}