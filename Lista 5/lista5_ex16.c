#include <stdio.h>


int ackermann(int m, int n);

int main()
{
    int m, n;

    printf("Sendo a funcao de ackermann A(m, n) digite \"m e n\": ");
    scanf("%d %d", &m, &n);

    printf("A(%d, %d) = %d", m, n, ackermann(m, n));

    return 0;
}

/*
    Simplesmente, desenvolvemos essas regras pela observação
    da função de ackerman.

    Por ex, A(1, 0) = A(0, 1) = 2 ou

    A(1, 2) = A(0, A(1, 1))
            = A(0, A(0, A(1, 0)))
            = A(0, A(0, A(0, 1)))
            = A(0, A(0, 2))
            = A(0, 3)
            = 4
*/
int ackermann(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (m > 0 && n == 0)
    {
        return ackermann(m - 1, 1);
    }
    else if (m > 0 && n > 0)
    {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}
