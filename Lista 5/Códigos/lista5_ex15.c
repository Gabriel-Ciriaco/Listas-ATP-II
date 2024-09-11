#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SET_LEN 3


void powerset(char * array, int i, char * subset, int subset_len);

int main()
{
    char group[SET_LEN] = {'1', '2', '3'};

    int SUB_LEN = (int) pow(2, SET_LEN);
    char subset[SUB_LEN];

    powerset(group, 0, subset, 0);

    for (int i = 0; i < SUB_LEN; i++)
    {
        printf("%c", subset[i]);
    }

    return 0;
}

void powerset(char * array, int i, char * subset, int subset_len)
{
    if (i == SET_LEN)
    {
        printf("{");
        for (int j = 0; j < subset_len; j++)
        {
            if (j == subset_len - 1)
            {
                printf("%c", subset[j]);
            }
            else
            {
                printf("%c,", subset[j]);
            }
        }

        printf("}\n");
        return;
    }

    subset[subset_len] = array[i];

    powerset(array, i + 1, subset, subset_len + 1);

    powerset(array, i + 1, subset, subset_len);
}
