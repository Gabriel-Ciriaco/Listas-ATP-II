#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int ocorrencias_palavra(char * palavra, char * arquivo_path)
{
  FILE * arquivo_leitura;

  arquivo_leitura = fopen(arquivo_path, "r");

  int ocorrencias = 0;

  int encontrou = 0;
  if (arquivo_leitura != NULL)
  {
    char string[100];
    char c;

    int i = 0;
    int last_index = 0;
    while(fscanf(arquivo_leitura, "%c", &c) != EOF)
    {
      i++;
      if(c == ' ')
      {
        // Posicionamos o ponteiro no inicio do arquivo.
        fseek(arquivo_leitura, last_index, SEEK_SET);

        // Pegamos a string baseado no tamanho dela.
        int tamanho_string = i - last_index;

        fgets(string, tamanho_string, arquivo_leitura);

        if (strcmp(palavra, string) == 0)
        {
          ocorrencias++;
        }

        last_index = i;

        // Posicionamos o ponteiro onde paramos de ler o arquivo.
        fseek(arquivo_leitura, i, SEEK_SET);
      }
    }
  }
  else
  {
    printf("Nao foi possivel abrir o arquivo");
  }

  fclose(arquivo_leitura);

  return ocorrencias;
}

int main()
{
  char palavra[100];

  printf("Digite uma palavra a ser buscada: ");
  gets(palavra);

  printf("Ocorrencias de %s eh: %d",
         palavra,
         ocorrencias_palavra(palavra, "./lista4_ex22.txt"));

  return 0;
}