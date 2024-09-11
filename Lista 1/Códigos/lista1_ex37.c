#include <stdio.h>


int media(int * numeros);

int main()
{
    int numeros[5] = {1, 2, 3, 4, 5};

    printf("A media eh: %d", media(numeros));


    return 0;
}

int media(int * numeros)
{
    int resultado = 0;
    int i = 0;

    while (numeros[i] != NULL)
    {
        resultado += numeros[i];
        i++;
    }

    resultado /= i;

    return resultado;
}
