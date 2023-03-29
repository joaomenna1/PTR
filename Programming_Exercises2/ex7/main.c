#include <stdio.h>
#include <stdarg.h>
#include "print_value.h"

int main()
{
    // vetor de inteiros e seu tamanho
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // chama a função de impressão passando cada elemento do vetor como argumento
    print_values(n, arr[0], arr[1], arr[2], arr[3], arr[4]);

    return 0;
}