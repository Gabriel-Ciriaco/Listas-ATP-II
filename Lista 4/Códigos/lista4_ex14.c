#include <stdio.h>
#include <stdlib.h>


#define NUMS_SIZE 7


int busca_binaria(int elemento, int * array, int array_size)
{
  int left = 0;
  int right = array_size;

  while (left <= right)
  {
    int pivot = (left + right) / 2;

    if (array[pivot] == elemento)
    {
      return pivot;
    }

    if (array[pivot] > elemento)
    {
      right--;
    }
    
    if (array[pivot] < elemento)
    {
      left++;
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

    fread(numeros, sizeof(int), NUMS_SIZE, arquivo_bin);

    int index_num = busca_binaria(20, numeros, NUMS_SIZE);

    if (index_num != -1)
    {
      printf("O elemento esta na posicao: %d\n", index_num);
      printf("O elemento: %d", numeros[index_num]);
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