#include <stdio.h>
#include <stdlib.h>
#include "fraction.h"

int main() {
    int  a, b;

    printf("\nInput some number for A: \n");
    scanf("%d",&a);

    printf("\nInput some number for B: \n");
    scanf("%d",&b);
    printf("\n-----------------------------\n");
    printf("\nResult:\n");
    printf("\n-----------------------------\n");

    improper(a,b);
    own(a,b);
    decimal(a,b);

    return 0;

}