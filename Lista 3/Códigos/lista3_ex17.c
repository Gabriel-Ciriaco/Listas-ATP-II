#include <stdio.h>
#include <stdlib.h>

#define titulo_SIZE 8


typedef struct
{
    char * titulo;
    char * diretor;
    int ano;
} Filme;

int main()
{
    Filme * ptr_filme;
    Filme filme;

    ptr_filme = &filme;

    ptr_filme->titulo = "Seu Cuca";
    ptr_filme->diretor = "Bundogan";

    ptr_filme->ano = 2016;

    printf("\nTitulo: %s\nDiretor: %s\nAno de Lancamento: %d\n",
           filme.titulo, filme.diretor, filme.ano);

    return 0;
}
