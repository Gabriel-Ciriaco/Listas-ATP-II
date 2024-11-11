#include <stdio.h>
#include <stdlib.h>


int main()
{
  FILE * arquivo_leitura;
  FILE * arquivo_copia;

  arquivo_leitura = fopen("./lista4_ex4_leitura.txt", "r");
  arquivo_copia = fopen("./lista4_ex4_copia.txt", "w");


  if (arquivo_leitura != NULL && arquivo_copia != NULL)
  {
    char c;
    while(fscanf(arquivo_leitura, "%c", &c) != EOF)
    {
      fprintf(arquivo_copia, "%c", c);
    }

    printf("Arquivo copiado com sucesso!");
  }
  else
  {
    printf("Nao foi possivel abrir o(s) arquivo(s)");
  }

  fclose(arquivo_leitura);
  fclose(arquivo_copia);

  return 0;
}