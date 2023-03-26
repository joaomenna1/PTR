#include <stdio.h>

void fibonacci(int n) {
    int i, t1 = 0, t2 = 1, prox;

    printf("\n Serie de Fibonacci \n ");

    for(i = 1; i <= n; i++) {
        printf("%d ", t1);
        prox = t1 + t2;
        t1 = t2;
        t2 = prox;
    }
}