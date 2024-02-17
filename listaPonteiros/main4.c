#include <stdio.h>

int main(){

    float array[10] = {1,5,4,8,6,4,7,2,3,9};
    
    for(int i = 0; i < 10; i++){
        printf("Endereço[%d] : %p\n", i, &array[i]);
    }
    
    return 0;
}