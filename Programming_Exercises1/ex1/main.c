#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sum.h"

int main(int argc, char const *argv[]) {
    int n;
    /*Gerando valores aleatórios entre 0 e 100*/
    n  = rand()%100;
    printf("valor gerado : n = %d\n", n);
    sum(n);
    return 0;
}