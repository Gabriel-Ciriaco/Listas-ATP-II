#include <stdio.h>


int main()
{
    int numeros[5] = {1, 243, -1, 4, 39};

    int sao_positivos = 0;

    for (int i = 0; i < 5; i++)
    {
        if (numeros[i] >= 0)
        {
            sao_positivos ++;
        }
    }

    if (sao_positivos == 5)
    {
        printf("Todos os elementos sao positivos.");
    }
    else
    {
        printf("Nem todos os elementos sao positivos.");
    }

    return 0;
}
