#include <stdio.h>

int main()
{
    float fibo[8] = {1.0, 1.0, 2.0, 3.0, 5.0, 8.0, 13.0, 21.0};

    for (int i = 0; i < 8; i++)
    {
        printf("%.1f\n", fibo[i]);
    }

    return 0;
}
