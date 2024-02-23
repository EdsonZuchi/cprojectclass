#include <stdio.h>

int soma(int entrada){
    if (entrada == 1){
        return 1;
    }
    return entrada + soma(entrada-1);
}

int main(){
    int value = 3;
    printf("Valor final %d\n", soma(value));
    return 0;
}
