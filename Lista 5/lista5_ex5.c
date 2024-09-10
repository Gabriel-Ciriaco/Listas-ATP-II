#include <stdio.h>


int eh_primo(int n, int divisor);

int main()
{
    int num = 0;

    printf("Digite um numero: ");

    scanf("%d", &num);

    if (eh_primo(num, num - 1) == 1)
    {
        printf("%d eh primo.", num);
    }
    else
    {
        printf("%d nao eh primo.", num);
    }

    return 0;
}

int eh_primo(int n, int divisor)
{
    if (divisor < 2 && n >= 2)
    {
        /*
            O número não é divisivel por ngm antecessor
            à ele e até o 2. Logo, é divisível por ele e 1.
        */
        return 1;
    }
    else if (divisor != 0 && n % divisor != 0)
    {
        /*
            Verificar os próximos divisores, no caso,
            (números anteriores a ele).
        */
        return eh_primo(n, divisor - 1);
    }
    else
    {
        // O número é divísivel por alg além de 1 e ele mesmo.
        return 0;
    }
}
