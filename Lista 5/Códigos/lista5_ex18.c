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
    Ao analisarmos o padr�o de uma torre de hanoi com 1 e 2 discos,
    nota-se que sempre: pegamos o menor disco e o colocamos no poste auxiliar,
    depois pegamos o maior disco seguinte e o colocamos no poste final. Voltamos
    pro poste auxiliar e pegamos o menor disco e o colocamos no maior.

    Assim, se testarmos com 3 discos, percebe-se que � poss�vel utilizar o mesmo
    padr�o se ignorarmos moment�neamente o terceiro (e maior) disco e
    aplicarmos o padr�o com os outros dois discos at� os colocarmos no poste aux.
    Ap�s isso, movemos o maior disco pro poste final, e retomamos o final
    do padr�o com os outros discos.

    Com isso, percebe-se uma recursividade da resolu��o da torre de hanoi, pois
    sempre aplicamos o nosso m�todo na quantidade de discos - 1. Dessa forma,
    simplificadamente, nosso m�todo consiste em:

    1� - Pegamos os nossos n - 1 discos e os movemos pro poste auxiliar.
    2� - Pegamos o nosso n disco (o maior) e o movemos para o poste final.
    3� - Pegamos os nossos n - 1 discos do poste auxiliar e os movemos
         para o poste final.

    O.B.S: Os valores, ou seja, quem � o poste inicial, auxiliar e final, n�o
           s�o fixos! Isso se deve porque conforme movimentamos os discos, o
           poste inicial ser� o que ele est�, o final para onde queremos lev�-lo
           e o auxiliar � o que n�o � nem o inicial nem o final.
*/
void hanoi(int qtd_discos, char poste_ini, char poste_aux, char poste_fim)
{
    // Nosso caso base � quando n�o temos nenhum disco.
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
