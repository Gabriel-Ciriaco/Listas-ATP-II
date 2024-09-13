#include <stdio.h>


int raiz_quadrada(int n, int * aux, int left, int right);

int main()
{
    int n = 0;

    printf("Digite um numero: ");

    scanf("%d", &n);

    // Criamos um intervalo [1, n]
    int aux[n];

    for (int i = 0; i < n; i++)
    {
        aux[i] = i + 1;
    }

    int raiz = raiz_quadrada(n, aux, 0, n - 1);

    printf("\nSua raiz quadrada eh, aproximadamente: %d\n", raiz);

    return 0;
}

/*
    Aplicamos uma busca binária para um array com elementos
    no intervalo [1, n].

    Assim, durante a busca binária, procuramos o número (k) em que
    k * k = n.

    Left é um ponteiro que aponta para o início do array.
    Right é um ponteiro que aponta para o final do array.
*/
int raiz_quadrada(int n, int * aux, int left, int right)
{
    if (left <= right)
    {
        int meio = (int) (left + right) / 2;

        int valor = aux[meio];

        int quadrado_valor = valor * valor;

        if (quadrado_valor == n)
        {
            return valor;
        }
        else if (quadrado_valor < n)
        {
            // O número estará mais para a esquerda do array.
            return raiz_quadrada(n, aux, meio + 1, right);
        }
        else if (quadrado_valor > n)
        {
            // O número estará mais para a direita do array.
            return raiz_quadrada(n, aux, left, meio - 1);
        }
    }

}
