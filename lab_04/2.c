#include <stdio.h>
#include <stdlib.h>
#include "../my_functions/functions_0d.h"
#include "../my_functions/functions_1d.h"

double *my_alloc(int i_min, int i_max)
{
    int size = i_max - i_min + 1;
    double *tab = malloc(size * sizeof(double));
    tab = tab - i_min;

    return tab;
}

void my_free(double **my_tab, int i_min)
{
    if (*my_tab != NULL)
    {
        free(*my_tab + i_min);
        *my_tab = NULL;
    }
}

int main()
{
    double *tab = my_alloc(-2, 4);

    for (int i = -2; i <= 4; i++)
    {
        tab[i] = 8.8;
        printf(" tab[%d] = %.2f, indeks: %p |", i, tab[i], &tab[i]);
    }

    d_array_set_random(tab - 1, tab + 4, -10.0, 10.0);
    printf("\n");

    for (int i = -2; i <= 4; i++)
    {
        printf(" tab[%d] = %.2f, indeks: %p |", i, tab[i], &tab[i]);
    }

    my_free(&tab, -2);
    my_free(&tab, -2);

    return 0;
}