#include <stdio.h>
#include "fibonacci.h"

/*
    A sequencia de fibonnaci

    Neste exemplo, irá ixibir a sequencia de Fibonacci dos primeiros n numeros (inserido pelo usuario)

    A sequencia de fibonacci é uma sequencia em que o prox termono eh a soma dois dois termos anteriores.
    os primeiros dois termos sao 0 e 1.

    a sequencia de fibonacci: 0, 1, 1, 2, 3, 5, 8, 13...n
*/

int main() {
    int n;
    printf("Input some number: ");
    scanf("%i", &n);
    
    fibonacci(n);
    return 0;
}