#include <stdio.h>
#include <stdlib.h>
#include "../my_functions/functions_0d.h"
#include "../my_functions/functions_1d.h"

double *max_pointer(double *tab, int number_of_elements)
{
    double *max = d_array_max(tab, (tab + number_of_elements));
    return max;
}

double *max_of_rows(double *tab, int cols, int number_of_rows)
{
  double *tab1 = malloc(number_of_rows * sizeof(double));
  for (int w = 0; w < number_of_rows; ++w)
    *(tab1 + w) = *max_pointer((tab + w), cols);
  return tab1;
}

int main()
{
    double tab[8][4];
    char *header = "Tablica";

    d_array_set_random(*tab, *(tab + 7) + 4, 0, 9);
    d_array_print(*tab, *(tab + 7) + 4, header);

    printf("Maksymalna wartosc: %.2f Adres: %p ", *max_pointer(*tab, 32), max_pointer(*tab, 32));
    double *all_max = max_of_rows(&tab, 4, 8);

    return 0;
}