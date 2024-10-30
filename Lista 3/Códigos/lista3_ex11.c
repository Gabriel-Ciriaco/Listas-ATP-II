#include <stdio.h>

enum dias
{
    DOMINGO = 1,
    SEGUNDA,
    TERCA,
    QUARTA,
    QUINTA,
    SEXTA,
    SABADO,
};

int main()
{
    int dia = SEGUNDA;

    printf("%d %d %d %d %d %d %d",
     DOMINGO, SEGUNDA, TERCA, QUARTA, QUINTA, SEXTA, SABADO);

    return 0;
}