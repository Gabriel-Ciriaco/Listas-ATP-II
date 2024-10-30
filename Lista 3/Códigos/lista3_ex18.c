#include <stdio.h>
#include <stdlib.h>


typedef struct
{
  char * rua;
  int numero;
  char * cidade;
} Endereco;

typedef struct
{
  char * nome;
  Endereco endereco;
  char * pais;
} Estado;

int main()
{
  Estado estado;
  Estado * ptr_estado;

  ptr_estado = &estado;

  ptr_estado->nome = "Sao Paulo";
  ptr_estado->pais = "Brasil";

  ptr_estado->endereco.rua = "Rua Melem Isaac";
  ptr_estado->endereco.numero = 255;
  ptr_estado->endereco.cidade = "Presidente Prudente";

  printf("Pais: %s\nEstado: %s\n -Cidade: %s\n -Rua: %s\n -Numero: %d\n",
   estado.pais,
   estado.nome,
   estado.endereco.cidade,
   estado.endereco.rua,
   estado.endereco.numero);

  return 0;
}