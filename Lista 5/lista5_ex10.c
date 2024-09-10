#include <stdio.h>
#include <math.h>


int soma_digitos(int num);

int main()
{
    int num = 0;

    printf("Digite um numero: ");

    scanf("%d", &num);

    printf("A soma dos digitos eh: %d", soma_digitos(num));

    return 0;
}

int soma_digitos(int num)
{
    if (num == 0)
    {
        return num;
    }

    return (num % 10) + soma_digitos(num / 10);
}
