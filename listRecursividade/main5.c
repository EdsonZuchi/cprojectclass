#include <stdio.h>

float calc(float array[5], int n){
    if (n == 0){
        return array[n];
    }

    return array[n] + calc(array, n-1);
}

int main(){
    float array[5] = {1.5,2.4,2.8,2.7,2.4};

    printf("Resultado final %f", calc(array, 4));

    return 0;
}