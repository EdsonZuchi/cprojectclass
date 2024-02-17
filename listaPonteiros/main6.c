#include <stdio.h>

int main(){

    int array[5];
    int aux;  
    
    for(int i = 0; i < 5; i++){
        printf("Digite um valor:\n");
        scanf("%d", &aux);
        array[i] = aux;
    }
    
    for(int i = 0; i < 5; i++){
        if(i % 2 == 0){
            printf("Endereço[%d] : %p\n", i, &array[i]);
        }
    }
    
    return 0;
}