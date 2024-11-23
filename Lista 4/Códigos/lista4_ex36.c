// média, desvio padrão, mediana
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define QTD_ALUNOS 5


typedef struct
{
  char nome[100];
  float media;
} Aluno;


float media(float * notas, int qtd_notas)
{
  float media = 0;

  for (int i = 0; i < qtd_notas; i++)
  {
    media += notas[i];
  }

  media /= qtd_notas;

  return media;
}

float desvio_padrao(float * notas, int qtd_notas)
{
  float media_valor = media(notas, qtd_notas);

  float desvio = 0;

  for (int i = 0; i < qtd_notas; i++)
  {
    float p = pow(notas[i] - media_valor, 2);

    desvio += p;
  }

  desvio /= qtd_notas;

  desvio = sqrt(desvio);

  return desvio;
}


int main()
{
  FILE * arquivo;

  /**
   * O arquivo possui 5 alunos diferentes
   * cada um com seu nome e média.
   */
  arquivo = fopen("./lista4_ex36.bin", "rb");

  if (arquivo != NULL)
  {
    Aluno alunos[QTD_ALUNOS];
    float notas[QTD_ALUNOS];

    fread(alunos, sizeof(Aluno), QTD_ALUNOS, arquivo);

    for (int i = 0; i < QTD_ALUNOS; i++)
    {
      printf("O aluno %s tem media %.2f\n",
             alunos[i].nome,
             alunos[i].media);
      notas[i] = alunos[i].media;
    }

    float media_valor = media(notas, QTD_ALUNOS);
    float desvio = desvio_padrao(notas, QTD_ALUNOS);

    printf("\nA media das medias dos alunos eh: %.2f\n", media_valor);
    printf("\nO desvio padrao das medias dos alunos eh: %.2f\n", desvio);
  }
  else
  {
    printf("Nao foi possivel ler o arquivo.");
  }

  fclose(arquivo);

  return 0;
}