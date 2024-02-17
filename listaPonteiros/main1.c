#include <stdio.h>

int main(){

    int nint;
    float nfloat;
    char schar;

    int * prtInt;
    float * prtFloat;
    char * prtChar;

    prtInt = &nint;
    prtFloat = &nfloat;
    prtChar = &schar;

    *prtInt = 5;
    *prtFloat = 5.5;
    *prtChar = 's';

    printf("%d\n", nint);
    printf("%f\n", nfloat);
    printf("%c\n", schar);
}