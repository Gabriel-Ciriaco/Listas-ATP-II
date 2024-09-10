#include <stdio.h>

#define NUM_MAX 10


int inverter(int * numeros, int start);

int main()
{
    int numeros[NUM_MAX] = {1, 2, 3, 4, 5, -6, -7, 8, -9};

    inverter(numeros, 0);

    return 0;
}

int inverter(int * numeros, int start)
{
    if(numeros[start] == '\0')
    {
        /*
            Chegamos no limite do array. Logo,
            basta imprimir os elementos anteriores.
        */
        return 0;
    }
    else
    {
        // Chamamos a função até chegar no final do array.
        inverter(numeros, start + 1);

        // Imprimimos o elemento pelo contador.
        printf("Elemento %d eh: %d\n", start, numeros[start]);

        return 0;
    }

}
