#include <stdio.h>

int fat (int num){
    if (num == 1){
        return num;
    }
    return num * fat(num-1);
}

int main (){
    int valor = 6;

    double resultado;

    resultado = valor * fat(valor-1);

    printf("Resultado %f", resultado);

    return 0;
}