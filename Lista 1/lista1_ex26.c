#include <stdio.h>
#include <string.h>


int main()
{
    char str1[100];
    char str2[100];
    char result[100] = {'\0'};

    gets(str1);
    fflush(stdin);
    gets(str2);
    fflush(stdin);

    strcat(result, str1);
    strcat(result, str2);

    printf("%s", result);


    return 0;
}
