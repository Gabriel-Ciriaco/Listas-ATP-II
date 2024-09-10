#include <stdio.h>

int eh_primo(int num, int div);

int num_primos(int qtd_primos, int num);

int main()
{
    num_primos(5, 0);

    return 0;
}

int eh_primo(int num, int div)
{
    // Garantir que o divisor começará no 2.
    if (div < 2) div = 2;

    if (div < num)
    {
        if (num % div == 0)
        {
            return 0;
        }
        else
        {
            return eh_primo(num, div + 1);
        }
    }

    return 1;
}

int num_primos(int qtd_primos, int num)
{
    // Garantir que começaremos do primeiro primo: 2.
    if (qtd_primos > 0 && num < 2)
    {
        num = 2;
    }

    if (qtd_primos > 0)
    {
        if (eh_primo(num, 0) == 1)
        {
            printf("%d\n", num);
            return num_primos(qtd_primos - 1, num + 1);
        }
        else
        {
            return num_primos(qtd_primos, num + 1);
        }
    }
}
