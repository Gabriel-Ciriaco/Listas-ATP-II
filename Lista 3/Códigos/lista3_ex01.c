#include <stdio.h>


struct Livro
{
    char titulo[100];
    char autor[100];
    int ano;
};


int main()
{
    struct Livro livro;

    printf("Digite o titulo do livro: ");
    fgets(livro.titulo, 100, stdin);

    printf("Digite o autor do livro: ");
    fgets(livro.autor, 100, stdin);

    printf("Digite o ano de publicacao do livro: ");
    scanf("%d", &livro.ano);

    printf("\nTitulo: %sAutor: %sAno: %d",
           livro.titulo, livro.autor, livro.ano);

    return 0;
}
