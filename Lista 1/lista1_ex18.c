#include <stdio.h>


int main()
{
    int numeros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int * ptr = &numeros;

    int soma = 0;

    for (int i = 0; i < 10; i++)
    {
        soma += *(ptr + i);
    }

    printf("Soma: %d", soma);

    return 0;
}
