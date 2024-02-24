#include <stdio.h>
#include <time.h>

int soma(int entrada){
    if (entrada == 1){
        return 1;
    }
    return entrada + soma(entrada-1);
}

int repet(int entrada){
    int resultado = 0;
    for (int i =0; i <= entrada; i++){
        resultado += i;
    }
    return resultado;
}

int main(){
    int value = 9;
    clock_t r, t;

    r = clock();
    printf("Valor final %d\n", soma(value));
    r = clock() - r;

    printf("Time re : %lf\n", (double)r);

    t = clock();
    printf("Valor final %d\n", soma(value));
    t = clock() - t;
    printf("Time t : %lf\n", (double)t);

    return 0;
}
