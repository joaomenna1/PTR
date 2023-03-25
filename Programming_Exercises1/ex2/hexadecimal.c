#include <stdio.h>
#include <math.h>

void hexadecimal(int n) {
    int vet[50], i = 0, tam = 0;

    while (n > 0) {
        vet[i] = n %16;
        n = n/16;
        i++;
        tam++;
    }

    printf("Hexadecimal: ");
    for (i = tam -1; i >= 0; i--) {
        switch(vet[i])
        {
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                printf("%d", vet[i]);
        }
    }
    
    printf("\n");
}