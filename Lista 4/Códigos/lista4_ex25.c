#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTD_PESSOAS 3

typedef struct
{
  char nome[50];
  int idade;
} Pessoa;


int main()
{
  FILE * arquivo_leitura;

  arquivo_leitura = fopen("./lista4_ex25.txt", "w");

  if (arquivo_leitura != NULL)
  {
    Pessoa pessoas[QTD_PESSOAS];

    /**
     * Padronização da estrutura no arquivo .txt:
     * 
     * [PESSOA](nome)(/nome)(idade)(/idade)[/PESSOA]
     */ 
    char * pessoa_txt;
    for (int i = 0; i < QTD_PESSOAS; i++)
    {
      printf("Digite o nome da pessoa %d: ", i + 1);
      gets(pessoas[i].nome);
      
      printf("Digite a idade da pessoa %d: ", i + 1);
      scanf("%d", &pessoas[i].idade);

      char idade_txt[100];
      itoa(pessoas[i].idade, idade_txt, 10);

      pessoa_txt = malloc(sizeof(char) * strlen(pessoas[i].nome) +
                          sizeof(char) * strlen(idade_txt));

      strcpy(pessoa_txt, pessoas[i].nome);
      strcat(pessoa_txt, idade_txt);

      fprintf(arquivo_leitura, "%s\n", pessoa_txt);
      setbuf(stdin, NULL);
    }

    free(pessoa_txt);
  }
  else
  {
    printf("Nao foi possivel abrir o arquivo");
  }

  fclose(arquivo_leitura);

  return 0;
}