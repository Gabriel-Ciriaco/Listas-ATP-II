#include <stdio.h>


int count_caminhos(int m, int n);

int caminhos_grade_NxN(int n);

int main()
{
    int n = 0;

    printf("Digite N de uma grade NxN: ");

    scanf("%d", &n);

    printf("\nExistem %d caminho(s) possiveis.\n",
           caminhos_grade_NxN(n));

    return 0;
}

int caminhos_grade_NxN(int n)
{
    return count_caminhos(n, n);
}

/*
    Ao desenharmos e analisarmos os diferentes caminhos de grades
    2x3, 3x2 e 3x3, nota-se um padrão. Os diferentes caminhos da 3x3
    é resultado da soma dos caminhos da 2x3 com o da 3x2.

    Assim, ao testarmos com outros exemplos, percebe-se que
    o número total de caminhos possíveis numa grade MxN é:

    caminhos(m - 1, n) + caminhos(m, n - 1).
*/
int count_caminhos(int m, int n)
{
    // Evitar erros desnecessários.
    if (m == 0 || n == 0)
    {
        return 0;
    }


    if (m == 1 || n == 1)
    {
        return 1;
    }

    return count_caminhos(m - 1, n) + count_caminhos(m, n - 1);
}
