#include <stdio.h>


int main()
{
    int numeros[7] = {1, 2, 3, 4, 5, 6, 7};

    int * ptr = &numeros;
    int soma = 0;

    for (int i = 0; i < 7; i++)
    {
        soma += *(ptr + i);
    }

    printf("A soma dos numeros eh: %d", soma);

    return 0;
}
