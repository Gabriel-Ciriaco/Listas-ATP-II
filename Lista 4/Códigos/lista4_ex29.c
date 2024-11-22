#include <stdio.h>
#include <stdlib.h>


void encrypt(char * palavra, int shift)
{
  int i = 0;
  while (palavra[i] != '\0')
  {
    palavra[i] += shift;
    i++;
  }
}

void decrypt(char * palavra, int shift)
{
  int i = 0;
  while(palavra[i] != '\0')
  {
    palavra[i] -= shift;
    i++;
  }
}

int main()
{
  FILE * arquivo;

  arquivo = fopen("./lista4_ex29.txt", "w");

  if (arquivo != NULL)
  {
    char palavra[100];
    printf("Digite uma palavra: ");

    gets(palavra);

    encrypt(palavra, 5);

    printf("Criptografado: %s\n", palavra);
    fprintf(arquivo, "%s", palavra);

    fclose(arquivo);

    arquivo = fopen("./lista4_ex29.txt", "r");

    if (arquivo != NULL)
    {
      char palavra[100];
      fgets(palavra, 100, arquivo);
      decrypt(palavra, 5);
      printf("Descriptografado: %s", palavra);
    }
    else
    {
      printf("Nao foi possivel abrir o arquivo.");
    }

    fclose(arquivo);
  }
  else
  {
    printf("Nao foi possivel abrir o arquivo.");
  }

  fclose(arquivo);

 return 0;
}