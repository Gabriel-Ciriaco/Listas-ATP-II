#include <stdio.h>


int main()
{
    char caracteres[10] = {'a', 'B', 'C', 'd', 'E', 'f', 'G', 'h', 'i', 'J'};

    char * ptr = &caracteres;

    int maiusculas = 0;

    for (int i = 0; i < 10; i++)
    {
        if (*(ptr + i) >= 'A' && *(ptr + i) <= 'Z')
        {
            maiusculas += 1;
        }
    }

    printf("Existem %d letras maiusculas.", maiusculas);

    return 0;
}
