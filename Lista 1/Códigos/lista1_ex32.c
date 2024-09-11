#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char * ptr_array[4];

    char * string;

    char * str_max;

    for (int i = 0; i < 4; i++)
    {
        string = malloc(100 * sizeof(char));

        printf("String %d: ", i + 1);

        gets(string);
        fflush(stdin);

        ptr_array[i] = string;
    }

    // Inicializamos a maior string como sendo a primeira.
    str_max = ptr_array[0];

    char * cur_str;

    int cur_str_len = 0;
    int max_len_str = 0;

    for (int i = 0; i < 4; i++)
    {
        cur_str = ptr_array[i];

        cur_str_len = strlen(cur_str);
        max_len_str = strlen(str_max);

        if (cur_str_len > max_len_str)
        {
            str_max = cur_str;
        }
    }

    printf("O elemento mais comprido eh: %s", str_max);

    // Liberar a memória.
    for (int i = 0; i < 4; i++)
    {
        free(ptr_array[i]);
    }

    return 0;
}
