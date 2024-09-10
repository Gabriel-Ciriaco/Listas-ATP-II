#include <stdio.h>

int main()
{
    int numeros[10];

    for (int i = 0; i < 10; i++)
    {
        numeros[i] = i;
        printf("Elemento %d do array: %d\n", i, numeros[i]);
    }

    return 0;
}
