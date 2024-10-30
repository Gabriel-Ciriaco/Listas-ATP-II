#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char * marca;
    char * modelo;
    int ano;
} Carro;

void atualizar_carro(Carro * carro,
                     char * marca,
                     char * modelo,
                     int ano)
{
  carro->marca = marca;
  carro->modelo = modelo;
  carro->ano = ano;
}

int main()
{
  Carro carro;

  atualizar_carro(&carro, "Renault", "Sandero", 2013);

  printf("\nMarca: %s\nModelo: %s\nAno: %d",
  carro.marca, carro.modelo, carro.ano);

  return 0;
}
