#include <stdio.h>


int raiz_quadrada(int n);

int main()
{
    int n = 0;

    printf("Digite um numero: ");

    scanf("%d", &n);

    printf("\nSua raiz quadrada eh: %d\n", raiz_quadrada(n));

    return 0;
}

int raiz_quadrada(int n)
{
    // Criamos um intervalo [1, n]
    int aux[n];

    for (int i = 0; i < n; i++)
    {
        aux[i] = i + 1;
    }

    /*
        Aplicamos uma busca binária para um array com elementos
        no intervalo [1, n].

        Assim, durante a busca binária, procuramos o número (k) em que
        k * k = n.
    */
    int left = 0;
    int right = n - 1;

    while (left <= right)
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
            left = meio + 1;
        }
        else if (quadrado_valor > n)
        {
            // O número estará mais para a direita do array.
            right = meio - 1;
        }
    }

}
