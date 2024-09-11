#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[])
{
    if (argc == 1)
    {
        printf("Nenhum argumento foi passado.");
    }
    else if (argc > 2 && argc <= 4)
    {
        int soma = 0;

        for (int i = 0; i < argc; i++)
        {
            int num = 0;
            printf("Numero %d: %s\n", i, argv[i]);
            soma += atoi(argv[i]);
        }

        printf("Soma eh: %d", soma);

    }

    return 0;
}
