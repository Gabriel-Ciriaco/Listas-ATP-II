#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ordenar(char * str_array[]);

int main()
{
    char * str_array[3];

    char * string;

    for (int i = 0; i < 3; i++)
    {
        printf("String %d: ", i);
        string = malloc(100 * sizeof(char));

        gets(string);
        fflush(stdin);

        str_array[i] = string;
    }

    ordenar(str_array);

    for (int i = 0; i < 3; i++)
    {
        printf("Elemento %d: %s\n", i, str_array[i]);

        free(str_array[i]);
    }

    return 0;
}

void ordenar(char * str_array[])
{
    // Verificar ordem alfabetica ate esse contador zerar.
    int ordem_counter = 3;

    while (ordem_counter > 0)
    {
        for (int i = 1; i < 3; i++)
        {
            char last_str[100];
            char crnt_str[100];

            strcpy(crnt_str, str_array[i]);
            strcpy(last_str, str_array[i - 1]);

            if (strcmp(crnt_str, last_str) < 0)
            {
                char temp[100] = {'\0'};
                strcpy(temp, crnt_str);

                strcpy(str_array[i], last_str);
                strcpy(str_array[i - 1], temp);
            }
            else
            {
                ordem_counter--;
            }
        }
    }

}
