#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[])
{
    if (argc == 1)
    {
        printf("Nenhum argumento foi passado.");
    }
    else if (argc >= 2 && argc <= 6)
    {
        int max_num = atoi(argv[1]);

        for (int i = 2; i < 7; i++)
        {
            int cur_num = atoi(argv[i]);

            if (cur_num > max_num)
            {
                max_num = cur_num;
            }
        }

        printf("O maior numero eh: %d", max_num);
    }

    return 0;
}
