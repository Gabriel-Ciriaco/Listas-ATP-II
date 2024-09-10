#include <stdio.h>
#include <string.h>
#include <math.h>

#define START 0


void inverter(char * string, int i);

int main()
{
    char string[100];

    printf("Digite uma string de no max 100 caracteres: ");

    gets(string);

    inverter(string, START);

    printf("Ela invertida eh: %s", string);

    return 0;
}

void inverter(char * string, int i)
{
    int str_size = strlen(string) - 1;

    int meio = (int) str_size / 2;

    if (meio == 0) meio++;


    if (i < meio)
    {
        // Fazemos um swap com o XOR.
        string[i] ^= string[str_size - i];
        string[str_size - i] ^= string[i];
        string[i] ^= string[str_size - i];

        inverter(string, i + 1);
    }

}
