#include <stdio.h>
#include <stdlib.h>

#define NOME_SIZE 8


typedef struct
{
    char * nome;
    int matricula;
    int nota;
} Aluno;

int main()
{
    Aluno * ptr_aluno;
    Aluno aluno;

    ptr_aluno = &aluno;

    ptr_aluno->nome = "Gabriel";

    ptr_aluno->matricula = 2345678;
    ptr_aluno->nota = 10;

    printf("\nNome: %s\nMatricula: %d\nAno: %d\n",
           aluno.nome, aluno.matricula, aluno.nota);

    return 0;
}
