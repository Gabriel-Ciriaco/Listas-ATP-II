#include <stdio.h>

#define NUM_LEN 3
#define START_IND 0

int min_rec(int * numeros, int pos, int max);

int mdc(int * numeros, int div, int pos, int max);

int main()
{
    int numeros[NUM_LEN] = {6, 12, 9};

    int min_num = min_rec(numeros, START_IND, NUM_LEN);

    int MDC = mdc(numeros, min_num, START_IND, NUM_LEN);

    printf("O maior divisor do array eh: %d", MDC);

    return 0;
}

int min_rec(int * array, int pos, int max)
{
    int retorno = 0;

    if (pos < max)
    {
        retorno = min_rec(array, pos + 1, max);
        return array[pos] < retorno ? array[pos] : retorno;
    }

    return array[pos - 1];
}

int mdc(int * numeros, int div, int pos, int max)
{
    if (pos < max)
    {
        if (numeros[pos] % div != 0)
        {
            return mdc(numeros, div - 1, START_IND, max);
        }

        return mdc(numeros, div, pos + 1, max);
    }

    return div;
}
