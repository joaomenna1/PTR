#include <stdlib.h>
#include <stdio.h>


void binary(int n, int *vet, int id) {
    if (n == 0) {
        printf("%d", n);
        vet[id] = n;
    } else {
        binary(n/2, vet, id - 1);
        printf("%d", n % 2);
        vet[id] = n % 2;
    }
}
