#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
  FILE * arquivo_bin;

  arquivo_bin = fopen("./lista4_ex12.bin", "wb");

  if (arquivo_bin != NULL)
  {
    int qtd_nomes = 0;

    printf("Digite quantos nomes deseja adicionar: ");
    scanf("%d", &qtd_nomes);

    char * nome;
    for (int i = 0; i < qtd_nomes; i++)
    {
      printf("Digite o nome %d: ", i + 1);

      nome = (char * ) malloc(sizeof(char) * 50);

      setbuf(stdin, NULL);

      gets(nome);

      fwrite(nome, sizeof(char) * strlen(nome), 1, arquivo_bin);
    }

    free(nome);
  }
  else
  {
    printf("Nao foi possivel abrir o arquivo.");
  }

  fclose(arquivo_bin);

  return 0;
}