#include <stdio.h>


int max(int * numeros, int i, int maior);

int main()
{
    int numeros[5] = {1, -2, 3, -4, 5};

    printf("O maior elemento eh: %d", max(numeros, 0, numeros[0]));

    return 0;
}

int max(int * numeros, int i, int maior)
{
    if (numeros[i] == '\0')
    {
        return maior;
    }
    else if (numeros[i] > maior)
    {
        maior = numeros[i];
    }

    return max(numeros, i + 1, maior);
}
