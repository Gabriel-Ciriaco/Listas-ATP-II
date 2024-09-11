#include <stdio.h>
#include <string.h>


int main()
{
    char string[100];
    gets(string);

    int i = 0;
    while (string[i] != '\0')
    {
        string[i] = '*';
        i++;
    }

    printf("Nova palavra: %s", string);


    return 0;
}
