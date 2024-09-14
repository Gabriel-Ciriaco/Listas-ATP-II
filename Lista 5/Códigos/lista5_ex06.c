#include <stdio.h>

#define NUM_MAX 10


void inverter(int * numeros, int i);

int main()
{
    int numeros[NUM_MAX] = {1, 2, 3, 4, 5, -6, -7, 8, -9, -10};

    inverter(numeros, 0);

    return 0;
}

void inverter(int * numeros, int i)
{
    /*
        Chegamos no limite do array. Logo,
        basta imprimir os elementos anteriores.
    */
    if(i == NUM_MAX)
    {
        return;
    }

    // Chamamos a função até chegar no final do array.
    inverter(numeros, i + 1);

    // Imprimimos o elemento pelo contador.
    printf("Elemento %d eh: %d\n", i, numeros[i]);

}
