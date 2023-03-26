#include <stdio.h>
#include <stdlib.h>

/*Fraçao imprória é uma fraçao onde o numerador é maior ou igual ao denominador*/

void improper(int a, int b) {
    if (a >= b) {
        printf("\n%d\n", a);
        printf("--\n");
        printf("%d\n",b);
    } else {
        printf("\nNao é uma fraçao imprópria\n");
    }
}

/*Fração própria é uma fraçao onde o numerador é menor que o donominador*/
void own(int a, int b) {
    if (a < b) {
        printf("\n%d\n", a);
        printf("--\n");
        printf("%d\n",b);
    } else {
        printf("Nao é uma fraçao própria\n");
    }

}

void decimal(int a, int b) {
    printf("%d%d\n",a,b);
}