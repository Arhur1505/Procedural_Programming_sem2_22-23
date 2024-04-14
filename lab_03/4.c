#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../my_functions/functions_0d.h"
#include "../my_functions/functions_1d.h"

#define ROWS 7
#define COLS 5

int main(void)
{
    srand(time(NULL));
    double array[ROWS][COLS];

    for (double *p = *array; p < *(array + ROWS); p += COLS)
    {
        d_array_set_random(p, p + COLS,
                           ((double(*)[COLS])p - array) * 10,
                           (((double(*)[COLS])p - array) + 1) * 10);
    }

    for (double(*row)[COLS] = array; row < array + ROWS; row++)
    {
        d_array_print(*row, *row + COLS, (const char[]){'w', '=', row - array + '0', '\0'});
    }

    return 0;
}