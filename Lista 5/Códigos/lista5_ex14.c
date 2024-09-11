#include <stdio.h>
#include <string.h>
#include <math.h>

int eh_palindromo(char * string, int i);

int main()
{
    char string[100];

    printf("Digite uma palavra de no max 100 caracteres: ");

    gets(string);

    if (eh_palindromo(string, 0) == 1)
    {
        printf("A palavra eh palindromo.\n");
    }
    else
    {
        printf("A palavra nao eh palindromo.\n");
    }

    return 0;
}

int eh_palindromo(char * string, int i)
{
    int max_indice = strlen(string) - 1;

    if (string[i] == string[max_indice - i] && max_indice > 0)
    {
        if(i == max_indice)
        {
            return 1;
        }

        return eh_palindromo(string, i + 1);
    }

    return 0;
}
