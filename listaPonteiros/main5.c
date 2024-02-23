#include "stdio.h"

void printaArray(int *array){
    int *aux = &array[0];

    for (int i = 0; i < 5; i++){
        printf("Endereco : %p\n", aux);
        printf("Valor : %d\n", *aux);
        aux++;
    }

}


int main(){
    int value[5] = {1,2,3,4,5};

    printaArray(&value);
}
