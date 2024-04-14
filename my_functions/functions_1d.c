#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "functions_0d.h"
#include "functions_1d.h"

void i_array_print(const int *first, const int *last, const char *header)
{
    printf("%s[", header);
    while (first < last)
    {
        printf("%d ", *first);
        first++;
    }
    printf("]/n");
}

void d_array_print(const double *first, const double *last, const char *header)
{
    printf("%s[", header);
    while (first < last)
    {
        printf("%.2f ", *first);
        first++;
    }
    printf("]\n");
}

void i_array_set_zero(int *first, int *last)
{
    while (first < last)
    {
        *(last - 1) = 0;
        last--;
    }
}

void d_array_set_zero(double *first, double *last)
{
    while (first < last)
    {
        *(last - 1) = 0;
        last--;
    }
}

void i_array_set_random(int *first, int *last, int min, int max)
{
    while (first < last)
    {
        *(last - 1) = i_rand(min, max);
        last--;
    }
}

void d_array_set_random(double *first, double *last, double min, double max)
{
    while (first < last)
    {
        *(last - 1) = d_rand(min, max);
        last--;
    }
}

double d_array_sum(double *first, double *last)
{
    double sum = 0;
    while (first < last)
    {
        sum += *first;
        first++;
    }
    return sum;
}

double d_array_avg(double *first, double *last)
{
    return d_array_sum(first, last) / (last - first);
}

//double d_array_os(double *first, double *last)
//{
//    double os = 0;
//    int j = last - first;
//    double avg = d_array_avg(first, last);
//    for (int i = 0; i < j; i++)
//    {
//        os += (*(first + i) - avg) * (*(first + i) - avg);
//    }
//    os /= j;
//    return sqrt(os);
//}

double *d_array_min(double *first, double *last)
{
    double *min = first;
    while (first < last)
    {
        if (*min > *first)
        {
            min = first;
        }
        first++;
    }
    return min;
}

double *d_array_max(double *first, double *last)
{
    double *max = first;
    while (first < last)
    {
        if (*max < *first)
        {
            max = first;
        }
        first++;
    }
    return max;
}
