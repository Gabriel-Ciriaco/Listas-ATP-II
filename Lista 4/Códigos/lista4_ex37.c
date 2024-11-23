#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQ_PATH_SIZE 18

#define QTD_CONTATOS 2

#define BUFFER_SIZE 256
#define STR_SIZE 100


typedef struct
{
  char * nome;
  char * numero;
}Contato;

/**
 * Prompts para criar um contato.
 */
Contato criar_contato()
{
  Contato contato;

  contato.nome = malloc(sizeof(char) * STR_SIZE);
  contato.numero = malloc(sizeof(char) * STR_SIZE);

  printf("\nDigite o nome do contato a ser criado: ");
  gets(contato.nome);

  printf("Digite o numero do contato a ser criado: ");
  gets(contato.numero);

  return contato;
}

/**
 * Decodifica um contato de string para Contato.
 * 
 * No .txt, o contato está armazenado da seguinte forma:
 * 
 * nome:numero
 * 
 */
Contato decode_contato(char * contato_string)
{
  Contato atual;

  int tamanho_string = strlen(contato_string);

  atual.nome = malloc(sizeof(char) * STR_SIZE);
  atual.numero = malloc(sizeof(char) * STR_SIZE);

  // Criamos uma flag para armazenar ora nome ora número.
  int nome_numero = 0;

  // Tamanho do número.
  int j = 0;

  for (int i = 0; i < tamanho_string; i++)
  {
    /**
     * Ao encontrar o separador do nome para o
     * número, começamos a armazenar o número.
     */
    if (contato_string[i] == ':')
    {
      // Muda a flag para armazenarmos o número.
      nome_numero = 1;

      // Finalizamos a string nome.
      atual.nome[i] = '\0';

      continue;
    }

    if (!nome_numero)
    {
      atual.nome[i] = contato_string[i];
    }
    else
    {
      atual.numero[j++] = contato_string[i];
    }
  }

  // Finalizamos a string número.
  atual.numero[j] = '\0';

  return atual;
}

/**
 * Adiciona um contato com a formatação correta.
 */
void adicionar_contato(Contato * contato, char * arquivo_path)
{
  FILE * arquivo;

  arquivo = fopen(arquivo_path, "a");

  if (arquivo != NULL)
  {
    fprintf(arquivo, "%s:%s\n",
            contato->nome,
            contato->numero);
  }
  else
  {
    printf("\n[ADICIONAR_CONTATO]: Nao foi possivel abrir o arquivo.\n");
  }

  fclose(arquivo);
}

/**
 * Adiciona mais de um contato.
 */
void adicionar_contatos(int qtd_contatos, char * arquivo_path)
{
  for (int i = 0; i < qtd_contatos; i++)
  {
    Contato atual;
    atual = criar_contato();
    adicionar_contato(&atual, arquivo_path);

    free(atual.nome);
    free(atual.numero);
  }
}


/**
 * Retorna quantos contatos o arquivo possui.
 * 
 * Cada contato é uma linha, logo conta as linhas.
 */
int quantidade_contatos(char * arquivo_path)
{
  FILE * arquivo;

  arquivo = fopen(arquivo_path, "r");

  if (arquivo != NULL)
  {
    int linha = 0;

    char contato[BUFFER_SIZE];

    while(fgets(contato, BUFFER_SIZE, arquivo))
    {
      linha++;
    }

    return linha;
  }
  else
  {
    printf("\n[QTD_CONTATOS]: Nao foi possivel abrir o arquivo.\n");
    return -1;
  }

  fclose(arquivo);
}


/**
 * Retorna a linha na qual está o contato desejado.
 */
int buscar_contato_linha(char * nome_contato, char * arquivo_path)
{
  FILE * arquivo;

  arquivo = fopen(arquivo_path, "r");

  if (arquivo != NULL)
  {
    int linha = 0;

    char contato[BUFFER_SIZE];
    /**
     * Lemos os contatos linha por linha.
     */
    while(fgets(contato, BUFFER_SIZE, arquivo))
    {
      linha++;
      Contato atual;

      atual = decode_contato(contato);

      // Se o nome do contato for o que procuramos.
      if (strcmp(atual.nome, nome_contato) == 0)
      {
        free(atual.nome);
        free(atual.numero);
  
        return linha;
      }

      // Evitando memory leaks.
      free(atual.nome);
      free(atual.numero);
    }

    printf("\n[BUSCAR_CONTATO]: Nao foi possivel encontrar %s.\n", nome_contato);

    return -1;
  }
  else
  {
    printf("\n[BUSCAR_CONTATO]: Nao foi possivel abrir o arquivo.\n");
  }

  fclose(arquivo);
}

/**
 * Retorna o contato desejado.
 */
Contato buscar_contato(char * nome_contato, char * arquivo_path)
{
  FILE * arquivo;

  arquivo = fopen(arquivo_path, "r");

  if (arquivo != NULL)
  {
    int linha = 0;

    char contato[BUFFER_SIZE];
    /**
     * Lemos os contatos linha por linha.
     */
    while(fgets(contato, BUFFER_SIZE, arquivo))
    {
      linha++;
      Contato atual;

      atual = decode_contato(contato);

      // Se o nome do contato for o que procuramos.
      if (strcmp(atual.nome, nome_contato) == 0)
      {
        return atual;
      }
    }

    printf("\n[BUSCAR_CONTATO]: Nao foi possivel encontrar %s.\n", nome_contato);
  }
  else
  {
    printf("\n[BUSCAR_CONTATO]: Nao foi possivel abrir o arquivo.\n");
  }

  fclose(arquivo);
}

/**
 * Remove um contato da lista.
 */
void remover_contato(char * nome_contato, char * arquivo_path)
{
  FILE * arquivo_leitura;

  arquivo_leitura = fopen(arquivo_path, "r");

  if (arquivo_leitura != NULL)
  {
    // Calculamos quantos contatos temos.
    int qtd_contatos = quantidade_contatos(arquivo_path);

    // Removemos 1 contato da lista.
    int nova_qtd = qtd_contatos - 1;

    char contatos_atualizados[nova_qtd * BUFFER_SIZE];

    int pos_contato = buscar_contato_linha(nome_contato, arquivo_path);

    // O contato não está na lista.
    if (pos_contato == -1)
    {
      printf("\n[REMOVER_CONTATO]: Nao foi possivel encontrar %s.\n",
             nome_contato);
      return;
    }

    char contato[BUFFER_SIZE];
    int linha = 0;

    // Iniciamos o armazenamento da lista atualizada.
    while(fgets(contato, BUFFER_SIZE, arquivo_leitura))
    {
      linha++;

      // Pulamos o contato que queremos remover.
      if (linha != pos_contato)
      {
        /**
         * Caso seja o primeiro contato que vamos armazenar,
         * precisamos usar o "strcpy".
         * 
         * Caso contrário, concatenaremos os contatos.
         */
        if (linha == 1)
        {
          strcpy(contatos_atualizados, contato);
        }
        else
        {
          strcat(contatos_atualizados, contato);
        }
      }
    }

    fclose(arquivo_leitura);

    // Escreveremos as nova lista!
    FILE * arquivo_escrita;

    arquivo_escrita = fopen(arquivo_path, "w");

    if (arquivo_escrita != NULL)
    {
      if (sizeof(contatos_atualizados) != 0)
      {
        fprintf(arquivo_escrita, "%s", contatos_atualizados);
      }
      else
      {
        fprintf(arquivo_escrita, "%s", "");
      }

      printf("\n%s foi removido com sucesso!\n", nome_contato);
    }
    else
    {
      printf("\n[REMOVER_CONTATO]: Nao foi possivel salvar a nova lista.\n");
    }

    fclose(arquivo_escrita);

  }
  else
  {
    printf("\n[REMOVER_CONTATO]: Nao foi possivel abrir o arquivo.\n");
  }

  fclose(arquivo_leitura);
}

/**
 * Programa principal da apliacação.
 * 
 * Pergunta se queremos adicionar, buscar ou removar alguém
 * dos contatos!
 */
int main()
{
  char arquivo_path[ARQ_PATH_SIZE];
  strcpy(arquivo_path, "./lista4_ex37.txt");

  int qtd_contatos = 0;
  char c1;

  printf("Deseja adicionar contato(s)? (s/n)\n");
  scanf("%c", &c1);

  if (c1 == 's')
  {
    printf("Quantos contatos deseja adicionar?\n");
    scanf("%d", &qtd_contatos);
    setbuf(stdin, NULL);

    adicionar_contatos(qtd_contatos, arquivo_path);
  }
  setbuf(stdin, NULL);

  char c2;
  printf("Digita buscar algum contato? (s/n)?\n");
  scanf("%c", &c2);
  setbuf(stdin, NULL);

  if (c2 == 's')
  {
    Contato contato;
    char contato_nome[STR_SIZE];

    printf("Digite o nome do contato a ser buscado: ");
    gets(contato_nome);

    contato = buscar_contato(contato_nome, arquivo_path);

    printf("\nNome do contato: %s\nNumero do contato: %s\n",
            contato.nome, contato.numero);
  }

  char c3;
  printf("Deseja remover algum contato? (s/n)?\n");
  scanf("%c", &c3);
  setbuf(stdin, NULL);

  if(c3 == 's')
  {
    char contato[STR_SIZE];

    printf("Digite o nome do contato a ser removido: ");
    gets(contato);

    remover_contato(contato, arquivo_path);
  }

  return 0;
}