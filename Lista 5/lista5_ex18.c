#include <stdio.h>


void hanoi(int qtd_discos, char poste_ini, char poste_aux, char poste_fim);

int main()
{
    int qtd_discos = 0;

    printf("Digite a quantidade de discos da Torre de Hanoi: ");

    scanf("%d", &qtd_discos);

    hanoi(qtd_discos, 'A', 'B', 'C');

    return 0;
}

/*
    Ao analisarmos o padrão de uma torre de hanoi com 1 e 2 discos,
    nota-se que sempre: pegamos o menor disco e o colocamos no poste auxiliar,
    depois pegamos o maior disco seguinte e o colocamos no poste final. Voltamos
    pro poste auxiliar e pegamos o menor disco e o colocamos no maior.

    Assim, se testarmos com 3 discos, percebe-se que é possível utilizar o mesmo
    padrão se ignorarmos momentâneamente o terceiro (e maior) disco e
    aplicarmos o padrão com os outros dois discos até os colocarmos no poste aux.
    Após isso, movemos o maior disco pro poste final, e retomamos o final
    do padrão com os outros discos.

    Com isso, percebe-se uma recursividade da resolução da torre de hanoi, pois
    sempre aplicamos o nosso método na quantidade de discos - 1. Dessa forma,
    simplificadamente, nosso método consiste em:

    1° - Pegamos os nossos n - 1 discos e os movemos pro poste auxiliar.
    2º - Pegamos o nosso n disco (o maior) e o movemos para o poste final.
    3° - Pegamos os nossos n - 1 discos do poste auxiliar e os movemos
         para o poste final.

    O.B.S: Os valores, ou seja, quem é o poste inicial, auxiliar e final, não
           são fixos! Isso se deve porque conforme movimentamos os discos, o
           poste inicial será o que ele está, o final para onde queremos levá-lo
           e o auxiliar é o que não é nem o inicial nem o final.
*/
void hanoi(int qtd_discos, char poste_ini, char poste_aux, char poste_fim)
{
    // Nosso caso base é quando não temos nenhum disco.
    if (qtd_discos == 0)
    {
        return;
    }

    // Mover os n - 1 discos para o poste auxiliar.
    hanoi(qtd_discos - 1, poste_ini, poste_fim, poste_aux);

    // Movemos o nosso n disco para o poste final.
    printf("Mova o disco %d de %c para %c\n", qtd_discos, poste_ini, poste_fim);

    // Mover os n - 1 discos para o poste final.
    hanoi(qtd_discos - 1, poste_aux, poste_ini, poste_fim);
}
