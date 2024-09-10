#include <stdio.h>


int soma(int n);

int main()
{
    int num = 0;

    printf("Digite um numero: ");

    scanf("%d", &num);

    printf("A soma dos %d primeiros naturais eh: %d", num, soma(num));

    return 0;
}

int soma(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n + soma(n - 1);
}
