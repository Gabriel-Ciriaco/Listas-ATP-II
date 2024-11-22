#include <stdio.h>
#include <stdlib.h>

#define QTD_NUM 5


int main()
{
  FILE * arquivo_bin;

  /**
   * O arquivo contem 5 números.
   */
  arquivo_bin = fopen("./lista4_ex20.bin", "rb");

  if (arquivo_bin != NULL)
  {
    int numeros[QTD_NUM];

    float media = 0;

    fread(numeros, sizeof(int), QTD_NUM, arquivo_bin);


    for (int i = 0; i < QTD_NUM; i++)
    {
      media += (float) numeros[i];
    }

    media /= QTD_NUM;

    printf("A media eh: %.2f", media);
  }
  else
  {
    printf("Nao foi possivel abrir o arquivo.");
  }

  fclose(arquivo_bin);

  return 0;
}