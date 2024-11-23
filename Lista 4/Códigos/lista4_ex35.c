#include <stdio.h>
#include <string.h>

#define NUM_CARACT 128
#define QTD_CARACT 1

int main()
{
  FILE * arquivo;

  arquivo = fopen("./lista4_ex35.txt", "r");

  if (arquivo != NULL)
  {
    // Contamos quantos caracteres tem no arquivo.
    fseek(arquivo, 0, SEEK_END);
    int total_caracteres = ftell(arquivo) / sizeof(char);
    rewind(arquivo);

    int histograma[NUM_CARACT][QTD_CARACT];

    // Inicializando o histograma.
    for (int i = 0; i < NUM_CARACT; i++)
    {
      histograma[i][0] = 0;
    }

    // Salvamos quantas vezes cada caracter aparece.
    char c;
    while(fscanf(arquivo, "%c", &c) != EOF)
    {
      histograma[c][0] += 1;
    }

    // Calculando a frequência de cada caracter.
    for (int i = 0; i < NUM_CARACT; i++)
    {
      if (histograma[i][0] != 0)
      {
        float frequencia_caract = (float) histograma[i][0] / total_caracteres;

        printf("Frequencia do caracter \"%c\": %.2f\n",
               i,
               frequencia_caract);
      }
    }
  }
  else
  {
    printf("Nao foi possivel abrir o arquivo.");
  }

  fclose(arquivo);

  return 0;
}