#include <stdio.h>
#include <string.h>


int main()
{
    char string[100];

    printf("Digite uma palavra: ");
    gets(string);

    int str_size = strlen(string);

    /*
        Definimos 2 ponteiros, um no começo da string,
        outro no fim. Depois, vamos movimentando-os de
        tal forma que os caracteres deve ser iguais para
        ser um palíndromo.

    */
    char * lft_ptr = &string;
    char * rgt_ptr = &string[str_size - 1];

    int eh_palindromo = 0;

    for (int i = 0; i < str_size - 1; i++)
    {
        if (*(lft_ptr + i) == *(rgt_ptr - i))
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
        printf("Eh palindromo.\n");
    }
    else
    {
        printf("Nao eh palindromo.\n");
    }

    return 0;
}
