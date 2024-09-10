#include <stdio.h>


int fatorial(int n);

int main()
{
    int num = 0;

    printf("Digite um numero: ");

    scanf("%d", &num);

    printf("O fatorial de %d eh: %d", num, fatorial(num));

    return 0;
}

int fatorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    return fatorial(n - 1) * n;
}
