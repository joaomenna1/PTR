#include <stdio.h>
#include <stdlib.h>
#include "binary.h"


int main () {
    int i, n, vet[50];

    for (i = 0; i < 50; i++)
        vet[i] = 0;

    printf("Input some decimal value...");
    scanf("%d",&n);

    binary(n, vet, 49);

    printf("\n");

    for (i = 0; i < 50; i++)
        printf("%d", vet[i]);
    printf("\n\n");

    return 0;
}