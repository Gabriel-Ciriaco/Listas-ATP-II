#include <stdio.h>


int main()
{
    char caracteres[12] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'};

    char * ptr = &caracteres;

    for (int i = 0; i < 6; i++)
    {
        char temp = *(ptr + i);

        *(ptr + i) = *(ptr + 11 - i);
        *(ptr + 11 - i) = temp;
    }

    for (int i = 0; i < 12; i++)
    {
        printf("Elemento %d: %c\n", i, caracteres[i]);
    }

    return 0;
}
