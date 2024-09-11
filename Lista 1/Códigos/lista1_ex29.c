#include <stdio.h>
#include <stdlib.h>


int main()
{
    char * str_arr[5];

    // String dinamica.
    char * string;

    for (int i = 0; i < 5; i++)
    {
        printf("String %d: ", i + 1);
        string = malloc(100 * sizeof(char));

        gets(string);
        fflush(stdin);

        // Armazenamos o ponteiro da string no array de ponteiros.
        str_arr[i] = string;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Elemento %d: %s\n", i, str_arr[i]);

        // Dealocação para previnir memory leaks.
        free(str_arr[i]);
    }

    return 0;
}
