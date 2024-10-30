#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
  char rua[100];
  int numero;
} Antiga;

typedef struct
{
  char rua[100];
  int numero;
  int complemento;
} Nova;


int main()
{
  Antiga endereco_old;
  Nova endereco_novo;

  strcpy(endereco_old.rua, "Rua Sao Sebastiao");
  endereco_old.numero = 213;

  // Copiando para a nova estrutura.
  strcpy(endereco_novo.rua, endereco_old.rua);

  endereco_novo.numero = endereco_old.numero;
  endereco_novo.complemento = 123;

  printf("Rua: %s\nNumero: %d\nComplemento: %d\n",
         endereco_novo.rua,
         endereco_novo.numero,
         endereco_novo.complemento);

  return 0;
}
