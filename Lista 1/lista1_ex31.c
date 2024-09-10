#include <stdio.h>
#include <stdlib.h>


int main()
{
    int * ptr_array[5];

    int * num;

    // Armazenando os números.
    for (int i = 0; i < 5; i++)
    {
        printf("Inteiro %d: ", i + 1);
        num = malloc(sizeof(int));

        scanf("%d", num);
        ptr_array[i] = num;
    }

    // Imprimindo-os e liberando a memória.
    for (int i = 0; i < 5; i++)
    {
        printf("Elemento %d: %d\n", i, *(ptr_array[i]));
        free(ptr_array[i]);
    }

    return 0;
}
