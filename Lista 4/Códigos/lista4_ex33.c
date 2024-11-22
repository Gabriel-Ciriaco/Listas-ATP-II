#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTD_ALUNO 5


typedef struct
{
  char nome[100];
  int idade;
  int RA;
} Aluno;


int busca_binaria(char * nome_aluno, FILE * arquivo)
{
  int left = 0;
  int right = QTD_ALUNO;

  // Garantir que nosso ponteiro está no inicio.
  fseek(arquivo, 0, SEEK_SET);

  while (left <= right)
  {
    int pivot = (left + right) / 2;

    fseek(arquivo, pivot * sizeof(Aluno), SEEK_SET);
    Aluno aluno_pivot;
    fread(&aluno_pivot, sizeof(Aluno), 1, arquivo);

    if (strcmp(aluno_pivot.nome, nome_aluno) == 0)
    {
      return pivot;
    }

    
    if (strcmp(aluno_pivot.nome, nome_aluno) < 0)
    {
      left = pivot + 1;
    }

    
    if (strcmp(aluno_pivot.nome, nome_aluno) > 0)
    {
      right = pivot - 1;
    }
  }

  return -1;
}

void ordernar(char * arquivo_path, Aluno * alunos)
{
  FILE * arquivo;

  arquivo = fopen(arquivo_path, "wb");

  if (arquivo != NULL)
  {
    for (int i = 0; i < QTD_ALUNO; i++)
    {
      for (int j = 0; j < QTD_ALUNO; j++)
      {
        if (strcmp(alunos[i].nome, alunos[j].nome) < 0)
        {
          Aluno temp;

          temp = alunos[i];
          alunos[i] = alunos[j];
          alunos[j] = temp;
        }
      }
    }

    fwrite(alunos, sizeof(Aluno), QTD_ALUNO, arquivo);
  }
  else
  {
    printf("Nao foi possivel abrir o arquivo");
  }

  fclose(arquivo);
}

int main()
{
  FILE * arquivo;

  /**
   * O arquivo contém 5 alunos armazenadas.
   */
  arquivo = fopen("./lista4_ex33.bin", "rb");

  if (arquivo != NULL)
  {
    Aluno alunos[QTD_ALUNO];

    fread(alunos, sizeof(Aluno), QTD_ALUNO, arquivo);

    ordernar("./lista4_ex33.bin", alunos);

    printf("Achei a pessoa no indice: %d",
           busca_binaria("Joelma", arquivo));
  }
  else
  {
    printf("Nao foi possivel abrir o arquivo.");
  }

  fclose(arquivo);

  return 0;
}