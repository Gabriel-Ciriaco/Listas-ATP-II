#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>


/**
 * Retorna o tamanho do arquivo em bytes.
 */
int tamanho_arquivo(char * arquivo_path)
{
  FILE * arquivo;

  arquivo = fopen(arquivo_path, "r");

  if (arquivo != NULL)
  {
    fseek(arquivo, 0, SEEK_END);
    return ftell(arquivo);
  }
  else
  {
    printf("[TAMANHO_ARQUIVO]: Nao foi possivel abrir o arquivo: %s.\n",
           arquivo_path);
  }

  fclose(arquivo);

  return 0;
}

int main()
{
  DIR * diretorio;

  struct dirent * arquivo;
  struct stat tipo_arquivo;

  int soma_arquivos = 0;

  // Abre o diretório atual.
  diretorio = opendir(".");

  if (diretorio != NULL)
  {
    // Lendo os arquivos presentes no diretório.
    while ((arquivo=readdir(diretorio)))
    {
      // Lê o tipo que é o arquivo.
      stat(arquivo->d_name, &tipo_arquivo);

      // Verifica se não é um diretório.
      if (!S_ISDIR(tipo_arquivo.st_mode))
      {
        soma_arquivos += tamanho_arquivo(arquivo->d_name);
      }
    }

    printf("O total de arquivos ocupados pelo diretorio eh: %d bytes.",
           soma_arquivos);
  }
  else
  {
    printf("Nao foi possivel abrir o diretorio");
  }

  closedir(diretorio);

  return 0;
}