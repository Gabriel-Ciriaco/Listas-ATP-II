#include <stdio.h>
#include <stdlib.h>


int main()
{
    int numeros[20];

    for (int i = 0; i < 20; i++)
    {
        numeros[i] = rand() % 100;
    }

    for (int i = 0; i < 20; i++)
    {
        printf("%d\n", numeros[i]);
    }

    return 0;
}
