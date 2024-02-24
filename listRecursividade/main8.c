#include <stdio.h>

int dif(int k, int n){
    if(n <= 0){
        return 0;
    }
    int resto = n%10;
    int result = 0;
    if (resto == k) {
        result = 1;
    }
    return result+ dif(k, n/10);
}

int main(){
    int k = 3;
    int n = 33376763;

    printf("Resultado eh %d", dif(k, n));
    return 0;
}