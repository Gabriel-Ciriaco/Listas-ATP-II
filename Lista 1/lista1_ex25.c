#include <stdio.h>
#include <string.h>

int main()
{
    char string[100];

    int carac = 0;
    int palavras = 0;
    int linhas = 0;

    int ch;
    int eh_letra = 0;

    // INFORMAÇÕES ÚTEIS
    printf("Aperte Enter para imprimir uma linha.\n");
    printf("Aperte Ctrl-C para sair do programa.\n");

    while ((ch = getchar()) != EOF)
    {
        if (ch != '\n')
        {
            carac++;

            if (ch != ' ')
            {
                eh_letra = 1;
            }
        }
        else
        {
            if (eh_letra == 1)
            {
                palavras++;
                eh_letra = 0;
            }

            linhas++;
        }

        // Se antes do espaço havia 1 letra, temos 1 palavra.
        if (ch == ' ' && eh_letra == 1)
        {
            palavras++;
            eh_letra = 0;
        }
    }


    printf("\nCaracteres: %d\n", carac);
    printf("Palavras: %d\n", palavras);
    printf("Linhas: %d\n", linhas);

    return 0;
}
