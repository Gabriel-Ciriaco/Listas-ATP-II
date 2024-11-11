#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Retorna o tamanho da maior palavra.
 */
int maior_palavra_tamanho(char * palavra_1, char * palavra_2)
{
  if (strlen(palavra_1) > strlen(palavra_2))
  {
    return strlen(palavra_1);
  }
  else
  {
    return strlen(palavra_2);
  }
}

/**
 * Retorna o indice de onde a palavra está no txt.
 */
int encontrar_palavra(char * arquivo_path, char * palavra)
{
  FILE * arquivo;

  arquivo = fopen(arquivo_path, "r");

  char c;
  int i = 0;
  int j = 0;
  int caracteres_iguais = 0;

  int tamanho_palavra = strlen(palavra);

  // Lendo o arquivo caracter por caracter.
  while (fscanf(arquivo, "%c", &c) != EOF)
  {
    if (palavra[j] == c)
    {
      caracteres_iguais++;
      j++;
    }
    else
    {
      caracteres_iguais = 0;
      j = 0;
    }

    if (caracteres_iguais == tamanho_palavra)
    {
      fclose(arquivo);
      return i + 1 - tamanho_palavra;
    }
    i++;
  }

  fclose(arquivo);
  return -1;
}

/**
 * Cria um arquivo temporário, substitui a palavra,
 * deleta o arquivo original e renomea o temporário para
 * o original.
 */
void substituir_palavra(char * arquivo_path,
                        char * palavra_original,
                        char * nova_palavra)
{
  int posicao_palavra = encontrar_palavra(arquivo_path, palavra_original);

  // Encontramos a palavra!
  if (posicao_palavra != -1)
  {
    FILE * arquivo_leitura;
    FILE * arquivo_substituir;

    // Criamos um arquivo temporário com as modificações.
    char temp[100];
    strcpy(temp, arquivo_path);
    strcat(temp, "_new.txt");

    arquivo_leitura = fopen(arquivo_path, "r");
    arquivo_substituir = fopen(temp, "w");

    if (arquivo_leitura != NULL && arquivo_substituir != NULL)
    {
      char c;
      int i = 0;
      int j = 0;
      int max_tamanho_palavra = maior_palavra_tamanho(palavra_original, nova_palavra);
      while (fscanf(arquivo_leitura, "%c", &c) != EOF)
      {
        // Substituir a palavra encontrada.
        if (i == posicao_palavra)
        {
          // Adicionando a nova palavra.
          while (nova_palavra[j])
          {
            fprintf(arquivo_substituir, "%c", nova_palavra[j]);
            j++;
          }
        }
        // Só printamos caracteres que não estão no indice da palavra.
        else if (i < posicao_palavra || i > posicao_palavra + strlen(nova_palavra))
        {
          fprintf(arquivo_substituir, "%c", c);
        }
        i++;
      }

     fclose(arquivo_leitura);
     fclose(arquivo_substituir);

     remove(arquivo_path);
     rename(temp, arquivo_path);
    }
    else
    {
      fclose(arquivo_leitura);
      fclose(arquivo_substituir);
      printf("[SUBSTITUIR PALAVRA]: Nao foi possivel salvar o arquivo");
    }
  }
}

int main()
{
  substituir_palavra("./lista4_ex7.txt", "oi", "ae");

  return 0;
}