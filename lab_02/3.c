#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../my_functions/functions_0d.h"

void sort(double *a, double *b, double *c){
    double tab[3]={*a, *b, *c};
    for(int i=0; i<3; i++){
        for(int i=0; i<2; i++){
            if(tab[i]<tab[i+1]){
                swap(&tab[i], &tab[i+1], sizeof(double));
            }
        }
    }
    *a=tab[0];
    *b=tab[1];
    *c=tab[2];
}

int main(){
    for(int i=0; i<100; i++){
        double a, b, c, d;
        a = d_rand(0, 10);
        b = d_rand(0, 10);
        c = d_rand(0, 10);
        d = a+b+c;
        
        sort(&a, &b, &c);
        if (!(a >= b && b >= c)){
            printf("Blad!");
            break;
        }
        if (fabs(d - ( a + b + c)) > 1e-6){
            printf("Blad!");
            break;
        }
    }
    return 0;
}