#include <stdio.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    int ra;
    char * nome;
    Data data_nascimento;
} Aluno;

int main()
{
    Aluno aluno;
    char nome[100] = "Gabriel";

    aluno.ra = 2345678;

    aluno.nome = malloc(sizeof(char) * strlen(nome));
    aluno.nome = nome;

    aluno.data_nascimento.dia = 2;
    aluno.data_nascimento.mes = 9;
    aluno.data_nascimento.ano = 2005;

    printf("Nome: %s\nRA: %d\nData\n  - Dia: %d\n  - Mes: %d\n  - Ano: %d\n",
           aluno.nome,
           aluno.ra,
           aluno.data_nascimento.dia,
           aluno.data_nascimento.mes,
           aluno.data_nascimento.ano);

    return 0;
}
