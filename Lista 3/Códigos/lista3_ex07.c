#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char * nome;
    int matricula;
    int nota;
} Aluno;

void atualizar_aluno(Aluno * aluno,
                      char * nome,
                      int matricula,
                      int nota)
{
    aluno -> nome = nome;

    //(*aluno).matricula = matricula;
    aluno -> matricula = matricula;

    aluno -> nota = nota;

}

int main()
{
    Aluno aluno;

    atualizar_aluno(&aluno, "Gabriel", 2345678, 10);

    printf("\nNome: %s\nMatricula: %d\nAno: %d\n",
           aluno.nome, aluno.matricula, aluno.nota);

    return 0;
}
