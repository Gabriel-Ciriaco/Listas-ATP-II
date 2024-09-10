#include <stdio.h>
#include <stdlib.h>


int main()
{
    int numeros[10] = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};

    int * left = &numeros;
    int * right = &numeros[9];

    int eh_palindromo = 0;

    for (int i = 0; i < 10; i++)
    {
        if (*(left + i) == *(right - i))
        {
            eh_palindromo = 1;
        }
        else
        {
            eh_palindromo = 0;
            break;
        }
    }

    if (eh_palindromo == 1)
    {
        printf("O numero eh um palindromo.\n");
    }
    else
    {
        printf("O numero nao eh um palindromo.\n");
    }

    return 0;
}
