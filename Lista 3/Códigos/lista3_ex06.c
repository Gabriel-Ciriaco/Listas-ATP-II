#include <stdio.h>
#include <stdlib.h>

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
    Aluno * ptr_aluno;

    ptr_aluno = &aluno;

    ptr_aluno->nome = "Gabriel";

    aluno.ra = 2345678;


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
