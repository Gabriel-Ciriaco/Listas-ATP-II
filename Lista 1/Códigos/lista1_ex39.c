#include <stdio.h>


int positivos(int * numeros);

int main()
{
    int numeros[6] = {1, 2, -3, 4, -5};

    printf("Existem %d numeros positivos", positivos(numeros));


    return 0;
}

int positivos(int * numeros)
{
    int posi = 0;
    int i = 0;

    while(numeros[i] != '\0')
    {
        if (numeros[i] > 0)
        {
            posi++;
        }

        i++;
    }

    return posi;
}
