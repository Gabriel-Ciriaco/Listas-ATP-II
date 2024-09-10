#include <stdio.h>


int coef_binomial(int n, int k);

int main()
{
    int n, k = 0;

    printf("Digite n e k de C(n, k): ");

    scanf("%d %d", &n, &k);

    printf("\nC(%d, %d) = %d\n", n, k, coef_binomial(n, k));

    return 0;
}

int coef_binomial(int n, int k)
{
    // Condi��o de exist�ncia n >= k.
    if (n < k)
    {
        return 0;
    }

    /*
        Como pela defini��o n >= k - 1 >= 0,
        nossa base ser� C(0, 0) ou C(1, 0) que s�o
        iguais a 1.
    */
    if (n <= 1 || k == 0)
    {
        return 1;
    }


    // Rela��o de Stifel.
    return coef_binomial(n - 1, k) + coef_binomial(n - 1, k - 1);
}
