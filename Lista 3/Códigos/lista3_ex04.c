#include <stdio.h>


typedef struct
{
    char nome[100];
    int matricula;
    int nota;
} Aluno;


int main()
{
    Aluno aluno;

    printf("Digite o nome do Aluno: ");
    gets(aluno.nome);

    printf("Digite a matricula do Aluno: ");
    scanf("%d", &aluno.matricula);

    printf("Digite a nota do Aluno: ");
    scanf("%d", &aluno.nota);

    printf("\nNome: %s\nMatricula: %d\nAno: %d\n",
           aluno.nome, aluno.matricula, aluno.nota);

    return 0;
}
