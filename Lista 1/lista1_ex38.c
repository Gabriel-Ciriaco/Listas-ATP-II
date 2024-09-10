#include <stdio.h>


int max(int * numeros);

int main()
{
    int numeros[10] = {1, 2, -3, 4, 5, 6, -7, 8, 9};

    printf("O maior elemento eh: %d", max(numeros));


    return 0;
}

int max(int * numeros)
{
    int maior = numeros[0];
    int i = 0;

    while(numeros[i] != '\0')
    {
        if (numeros[i] > maior)
        {
            maior = numeros[i];
        }

        i++;
    }

    return maior;
}
