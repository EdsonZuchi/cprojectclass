#include <stdio.h>

int main(){

    int v2;
    int v1;

    if(&v1 > &v2){
        printf("Endereço maior: %p da v1", &v1);
    }else{
        printf("Endereço maior: %p da v2", &v2);
    }
    
    return 0;
}