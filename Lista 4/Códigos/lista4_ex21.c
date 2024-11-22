#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define QTD_NUM 5


int procurar_numero(int numero_procurado, int * numeros)
{
  for (int i = 0; i < QTD_NUM; i++)
  {
    if (numeros[i] == numero_procurado)
    {
      return TRUE;
    }
  }

  return FALSE;
}

int main()
{
  FILE * arquivo_bin;

  /**
   * O arquivo contem 5 números.
   */
  arquivo_bin = fopen("./lista4_ex21.bin", "rb");

  if (arquivo_bin != NULL)
  {
    int numeros[QTD_NUM];

    fread(numeros, sizeof(int), QTD_NUM, arquivo_bin);

    procurar_numero(2, numeros) == TRUE
     ? printf("O numero esta no arquivo")
     : printf("O numero nao esta no arquivo");
  }
  else
  {
    printf("Nao foi possivel abrir o arquivo.");
  }

  fclose(arquivo_bin);

  return 0;
}