#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../my_functions/functions_0d.h"
#include "../my_functions/functions_1d.h"

void fun(double *first, double *last, double *sum, double *avg, double *os, double **max, double **min)
{
    *sum = d_array_sum(first, last);
    *avg = d_array_avg(first, last);
    *os = d_array_os(first, last);
    *max = d_array_max(first, last);
    *min = d_array_min(first, last);
}

int main()
{
    double tab[10];
    char *header = "Tablica";
    srand(time(NULL));
    d_array_set_random(tab, (tab + 10), -5.0, 15.0);
    d_array_print(tab, (tab + 10), header);

    double sum, avg, os;
    double *max, *min;

    fun(tab, (tab + 10), &sum, &avg, &os, &max, &min);

    printf("Suma: %f Srednia: %f Odchylenie standardowe: %f Maksymalny element: %f Minimalny element: %f", sum, avg, os, *max, *min);

    return 0;
}