#include <stdio.h>


int pow(int n, int pot);

int main()
{
    int num = 0;
    int potencia = 0;

    printf("Digite um numero: ");

    scanf("%d", &num);

    printf("Digite a potencia para eleva-lo: ");

    scanf("%d", &potencia);

    printf("%d elevado a %d eh: %d", num, potencia, pow(num, potencia));



    return 0;
}

int pow(int n, int pot)
{
    if (pot == 0)
    {
        return 1;
    }
    else
    {
        return n * pow(n, pot - 1);
    }
}
