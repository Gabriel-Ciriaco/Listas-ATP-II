#include <stdio.h>


int main()
{
    int valores[5];

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &valores[i]);
    }

    for (int j = 4; j >= 0; j--)
    {
        printf("Inverso: %d\n", valores[j]);
    }

    return 0;
}
