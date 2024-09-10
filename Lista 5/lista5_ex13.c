#include <stdio.h>

#define NUM_LEN 5

int ocorrencias(int elemento, int * numeros, int i);

int main()
{
    int numeros[NUM_LEN] = {1, 2, 2, 3, 2};

    int elemento = 2;

    printf("Existem %d ocorrencias de %d no array.",
           ocorrencias(elemento, numeros, 0), elemento);

    return 0;
}

/*
    int i é o indice pelo qual "andaremos" pelo array.
*/
int ocorrencias(int elemento, int * numeros, int i)
{
    int count = 0;

    if (numeros[i] != '\0')
    {
        if (elemento == numeros[i])
        {
            count++;
        }

        return count + ocorrencias(elemento, numeros, i + 1);
    }
}
