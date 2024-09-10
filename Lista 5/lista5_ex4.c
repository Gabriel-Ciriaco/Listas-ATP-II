#include <stdio.h>


int fibo(int n);

int main()
{
    int num = 0;

    printf("Digite um numero: ");

    scanf("%d", &num);

    printf("O %d termo de fibonacci eh: %d", num, fibo(num));

    return 0;
}

int fibo(int n)
{
    if (n <= 2)
    {
        return 1;
    }

    return fibo(n - 1) + fibo(n - 2);
}
