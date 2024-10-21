#include <stdio.h>


typedef struct
{
    char marca[100];
    char modelo[100];
    int ano;
} Carro;


int main()
{
    Carro carro;

    printf("Digite a marca do Carro: ");
    fgets(carro.marca, 100, stdin);

    printf("Digite o modelo do Carro: ");
    fgets(carro.modelo, 100, stdin);

    printf("Digite o ano do Carro: ");
    scanf("%d", &carro.ano);

    printf("\nMarca: %sModelo: %sAno: %d",
           carro.marca, carro.modelo, carro.ano);

    return 0;
}
