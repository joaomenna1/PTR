#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void sum(int n) {
    int i, total = 0, base;
    
    for (i = 0; i <= n; i++) {
        base  = 2*i + 1;
        total = (int) pow(base, 2) + total;
    }

    printf("The sum from 0 to %d: %d\n\n", n, total);
    printf("End!!!\n");
}