#include <stdio.h>


int main()
{
    char vogais[5] = {'a', 'e', 'i', 'o', 'u'};

    int sao_vogais = 0;


    for (int i = 0; i < 8; i++)
    {
        char letra;

        scanf("%c", &letra);

        fflush(stdin);

        for (int j = 0; j < 5; j++)
        {
            if (letra == vogais[j])
            {
                sao_vogais++;
            }
        }
    }


    printf("Vogais: %d", sao_vogais);

    return 0;
}
