#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Retorna o indice de onde a palavra está no txt.
 */
int encontrar_palavra(char * arquivo_path, char * palavra)
{
  FILE * arquivo;

  arquivo = fopen(arquivo_path, "r");

  char c;
  int i = 0;

  int caracteres_iguais = 0;
  int tamanho_palavra = strlen(palavra);

  // Lendo o arquivo caracter por caracter.
  while (fscanf(arquivo, "%c", &c) != EOF)
  {
    // Caracter da palavra é igual o do arquivo.
    if (palavra[caracteres_iguais] == c)
    {
      caracteres_iguais++;
    }
    else
    {
      caracteres_iguais = 0;
    }

    if (caracteres_iguais == tamanho_palavra)
    {
      fclose(arquivo);

      // Posição inicial da palavra encontrada.
      int pos_ini_encontrada = i + 1 - tamanho_palavra;

      return pos_ini_encontrada;
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
    strcat(temp, "_new.txt"); // O arquivo sera "nome_original.txt_new.txt"

    arquivo_leitura = fopen(arquivo_path, "r");
    arquivo_substituir = fopen(temp, "w");

    if (arquivo_leitura != NULL && arquivo_substituir != NULL)
    {
      char c;
      int i = 0;
      int j = 0;

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
        /*Só printamos caracteres que não estão nos índices da palavra,
          ou seja, se a palavra ocupa os índices 1 e 2, qualquer índice
          diferente de 1 e 2 será printado igual está no arquivo original.
        */
        else if (i < posicao_palavra ||
                 i >= posicao_palavra +
                  strlen(palavra_original))
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
  substituir_palavra("./lista4_ex7.txt", "oi", "eae");

  return 0;
}