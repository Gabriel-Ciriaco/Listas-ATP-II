#include <stdio.h>
#include <stdlib.h>

#define NUM_LIVROS 3

typedef struct
{
  char titulo[50];
  char autor[50];
  int ano;
} Livro;


int main()
{
  Livro livros[NUM_LIVROS];

  for (int i = 0; i < NUM_LIVROS; i++)
  {
    setbuf(stdin, NULL);

    printf("Digite o titulo do livro %d: ", i + 1);
    gets(livros[i].titulo);

    printf("Digite o autor do livro %d: ", i + 1);
    gets(livros[i].autor);

    printf("Digite o ano de publicacao do livro %d: ", i + 1);
    scanf("%d", &livros[i].ano);
  }

  for (int i = 0; i < NUM_LIVROS; i++)
  {
    printf("O titulo do livro %d: %s\n", i + 1, livros[i].titulo);
    printf("O autor do livro %d: %s\n", i + 1, livros[i].autor);
    printf("O ano do livro %d: %d\n\n", i + 1, livros[i].ano);
  }

  return 0;
}