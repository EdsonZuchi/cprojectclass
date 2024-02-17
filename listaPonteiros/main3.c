#include <stdio.h>

void trocarValor(int *num1, int *num2){
    if (*num2 > *num1){
        int aux = *num1;
        *num1 = *num2;
        *num2 = aux;
    }
    return;
}

int main(){

    int v2;
    int v1;

    v1 = 47;
    v2 = 103;
    
    trocarValor(&v1, &v2);
    
    printf("Valor da v1 : %d\n", v1);
    printf("Valor da v2 : %d\n", v2);
    
    return 0;
}