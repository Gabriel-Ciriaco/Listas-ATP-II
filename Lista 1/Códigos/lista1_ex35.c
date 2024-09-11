#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[])
{
    if (argc == 1)
    {
        printf("Nenhum argumento foi passado.");
    }
    else if (argc == 2)
    {
        int num = atoi(argv[1]);

        if (num % 2 == 0)
        {
            printf("%d eh par.", num);
        }
        else
        {
            printf("%d eh impar.", num);
        }
    }

    return 0;
}
