#include <stdio.h>
#include <stdlib.h>
#include "binary.h"
#include "hexadecimal.h"


int main () {
    int i, n, vet[50], rem[50];
    int tam = 0;

    for (i = 0; i < 50; i++)
        vet[i] = 0;

    printf("Input some decimal value...");
    scanf("%d",&n);
    
    printf("Binary: \n");
    binary(n, vet, 49);

    printf("\n");

    hexadecimal(n);


    return 0;
}