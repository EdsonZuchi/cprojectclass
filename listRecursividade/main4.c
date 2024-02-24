#include "stdio.h"
#include <math.h>

float calc(int x, int n){
    if(n == 1){
        return x;
    }
    return pow(x, n) + calc(x, n-1);
}

int main(){
    int x = 2;
    int n = 3;

    printf("Resultado eh: %f", calc(x,n));
}
