#include <stdio.h>
#include <stdlib.h>
#include "../my_functions/functions_0d.h"
#include "../my_functions/functions_1d.h"

void triangle_printf(double **triangle, int n){
    int a = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < a; j++){
            printf("%.1f ", *(*(triangle + i) + j));
        }
        printf("\n");
        a++;
    }
}

void free_triangle(double **triangle, int n){
    for(int i = 0; i < n; i++){
        free(*(triangle + i));
    }
    free(triangle);
}

int main(int argc, char *argv[]){
    if(argc == 1){
        printf("Brak argumentow wywolania! \n");
        return 1;
    }

    int n = atoi(*(argv + 1));
    double **triangle; 
    triangle = malloc(n * sizeof(double*));
    int a = 1;

    for(int i = 0; i < n; i++){
        *(triangle + i) = malloc(a * sizeof(double));
        for(int j = 0; j < a; j++){
            *(*(triangle + i) + j) = d_rand(0, 9);
        }
        a++;
    }

    triangle_printf(triangle, n);
    free_triangle(triangle, n);

    return 0;
}