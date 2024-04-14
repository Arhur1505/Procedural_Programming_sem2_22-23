#include <stdio.h>
#include <stdlib.h>
#include "../my_functions/functions_0d.h"
#define MIN -15
#define MAX 84.999999
#define MAX_HIST 10
#define DX 10.0

int main(){
    int tab[MAX_HIST];
    for(int i=0; i<MAX_HIST; i++){
        tab[i]=0;
    }

    for(int i=0; i<10000000; i++){
        double x = d_rand(MIN, MAX);
        for(int k=0; k<MAX_HIST; k++){
            if(x<MIN + (k+1)*DX){
                tab[k]++;
                break;
            }
        }
    }    

    for(int i=0; i<MAX_HIST; i++){
        printf("%d przedzial: %d\n", i, tab[i]);
    }

}