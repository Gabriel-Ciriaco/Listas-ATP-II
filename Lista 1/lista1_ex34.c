#include <stdio.h>
#include <string.h>


int main(int argc, char * argv[])
{
    if (argc == 1)
    {
        printf("Nenhum argumento foi passado.");
    }
    else if (argc == 2)
    {
        char * string = argv[1];
        printf("O tamanho de %s eh: %d", argv[1], strlen(argv[1]));
    }

    return 0;
}
