#include <stdio.h>


int main()
{
    int soma = 0;

    int valores[10];

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &valores[i]);

        soma += valores[i];
    }

    printf("Soma: %d", soma);

    return 0;
}
