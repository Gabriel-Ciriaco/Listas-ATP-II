#include <stdio.h>


typedef struct
{
    char marca[100];
    char modelo[100];
    int ano;
} Antiga;

typedef struct
{
    char marca[100];
    char modelo[100];
    int ano;
    int preco;
} Nova;


int main()
{
    Antiga carro_old;
    Nova carro_novo;

    strcpy(carro_old.marca, "Renault");
    strcpy(carro_old.modelo, "Sandero");
    carro_old.ano = 2013;

    strcpy(carro_novo.modelo, carro_old.modelo);
    strcpy(carro_novo.marca, carro_old.marca);
    carro_novo.ano = carro_old.ano;
    carro_novo.preco = 21000;

    printf("Marca: %s\nModelo: %s\nAno: %d\nPreco: %d\n",
           carro_novo.marca,
           carro_novo.modelo,
           carro_novo.ano,
           carro_novo.preco);

    return 0;
}
