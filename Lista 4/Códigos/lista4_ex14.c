#include <stdio.h>
#include <stdlib.h>


#define NUMS_SIZE 7


int busca_binaria(int elemento, FILE * arquivo)
{
  int left = 0;

  // Descubrindo quantos números estão amarzenados.
  fseek(arquivo, 0, SEEK_END);
  int right = ftell(arquivo) / sizeof(int);

  while (left <= right)
  {
    int pivot = (left + right) / 2;

    // Colocamos o ponteiro onde está o pivot.
    fseek(arquivo, pivot * sizeof(int), SEEK_SET);
    int elemento_pivot = 0;
    fread(&elemento_pivot, sizeof(int), 1, arquivo);

    if (elemento_pivot == elemento)
    {
      return pivot;
    }

    if (elemento_pivot > elemento)
    {
      right = pivot - 1;
    }
    
    if (elemento_pivot < elemento)
    {
      left = pivot + 1;
    }
  }

  return -1;

}

int main()
{
  FILE * arquivo_bin;

  /**
   * Arquivo com o seguinte array:
   * {1, 2, 4, 7, 9, 20, 50}
   */
  arquivo_bin = fopen("./lista4_ex14.bin", "rb");

  if (arquivo_bin != NULL)
  {
    int numeros[NUMS_SIZE];

    //fread(numeros, sizeof(int), NUMS_SIZE, arquivo_bin);

    int index_num = busca_binaria(20, arquivo_bin);

    if (index_num != -1)
    {
      printf("O elemento esta na posicao: %d\n", index_num);
    }
    else
    {
      printf("O elemento nao esta no registro");
    }
  }
  else
  {
    printf("Nao foi possivel abrir o arquivo");
  }

  fclose(arquivo_bin);

  return 0;
}