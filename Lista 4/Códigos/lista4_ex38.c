#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Cria arquivos binários.
 */
void criar_arquivo(char * dados,
                   int dados_size,
                   char * arquivo_path)
{
  FILE * arquivo;

  arquivo = fopen(arquivo_path, "wb");

  if (arquivo != NULL)
  {
    fwrite(dados, dados_size, 1, arquivo);

    printf("\n%s foi criado!\n", arquivo_path);
  }
  else
  {
    printf("\n[CRIAR ARQUIVO]: Nao foi possivel abrir o arquivo %s.\n",
           arquivo_path);
  }

  fclose(arquivo);
}

/**
 * Renomeia um arquivo.
 */
void renomear_arquivo(char * novo_nome,
                      char * arquivo_path)
{
  rename(arquivo_path, novo_nome);

  printf("\n%s foi renomeado para %s\n",
         arquivo_path,
         novo_nome);
}

/**
 * Exclui um arquivo.
 */
void excluir_arquivo(char * arquivo_path)
{
  remove(arquivo_path);

  printf("\nO arquivo %s foi removido!\n",
         arquivo_path);
}

/**
 * Lê um arquivo como um arquivo de texto!
 */
void ler_arquivo(char * arquivo_path)
{
  FILE * arquivo;

  arquivo = fopen(arquivo_path, "r");

  if (arquivo != NULL)
  {
    printf("\n");

    char c;
    while(fscanf(arquivo, "%c", &c) != EOF)
    {
      printf("%c", c);
    }

    printf("\n");
  }
  else
  {
    printf("\n[LER_ARQUIVO]: Nao foi possivel abrir o arquivo %s.\n",
           arquivo_path);
  }

  fclose(arquivo);
}

/**
 * Retorna o tamanho do arquivo.
 */
int tamanho_arquivo(char * arquivo_path)
{
  FILE * arquivo;
  
  arquivo = fopen(arquivo_path, "rb");

  if (arquivo != NULL)
  {
    fseek(arquivo, 0, SEEK_END);

    int tamanho_arquivo = ftell(arquivo);

    printf("\nO arquivo %s possui %d bytes.\n",
           arquivo_path,
           tamanho_arquivo);
  }
  else
  {
    printf("\n[TAMANHO_ARQUIVO]: Nao foi possivel abrir o arquivo %s.\n",
           arquivo_path);
  }

  fclose(arquivo);
}

int main()
{
  char string[3] = {'O', 'i', '\0'};

  criar_arquivo(string,
                sizeof(char) * strlen(string),
                "./lista4_ex38.txt");

  tamanho_arquivo("./lista4_ex38.txt");

  ler_arquivo("./lista4_ex38.txt");

  renomear_arquivo("./lista4_ex38_morte.txt", "./lista4_ex38.txt");

  excluir_arquivo("./lista4_ex38_morte.txt");

  return 0;
}