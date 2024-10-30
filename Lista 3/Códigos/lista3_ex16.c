#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char titulo[100];
    char diretor[50];
    int ano;
} Filme;


int main()
{
    Filme filme;

    printf("Digite o titulo do filme: ");
    gets(filme.titulo);

    printf("Digite o nome do diretor do filme: ");
    gets(filme.diretor);

    printf("Digite o ano de lancamento do filme: ");
    scanf("%d", &filme.ano);

    printf("\nTitulo: %s\nDiretor: %s\nAno de Lancamento: %d\n",
           filme.titulo, filme.diretor, filme.ano);

    return 0;
}
