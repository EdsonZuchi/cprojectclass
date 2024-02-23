#include "stdio.h"

float rec(int num){
    if(num == 1){
        return num;
    }

    return 1.0/num + rec(num-1);
}

int main(){
    int value = 4;

    printf("Resultado eh %f", rec(value));

    return 0;
}