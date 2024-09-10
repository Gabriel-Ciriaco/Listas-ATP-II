#include <stdio.h>


int max(int n1, int n2);

int mdc(int n1, int n2, int div);

int main()
{
    int n1, n2;

    printf("Digite o primeiro numero: ");
    scanf("%d", &n1);

    printf("Digite o segundo numero: ");
    scanf("%d", &n2);

    printf("O MDC eh: %d", mdc(n1, n2, max(n1, n2)));

    return 0;
}

int max(int n1, int n2)
{
    if (n1 > n2)
    {
        return n1;
    }
    else
    {
        return n2;
    }
}

int mdc(int n1, int n2, int div)
{
    if (n1 % div == 0 && n2 % div == 0)
    {
        return div;
    }
    else
    {
        return mdc(n1, n2, div - 1);
    }
}
