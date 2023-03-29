#include <stdio.h>
#include <stdarg.h>

void print_values(int count, ...)
{
    va_list ap;

    // inicializa ap
    va_start(ap, count);

    // imprime os valores passados para a função
    for (int i = 0; i < count; i++) {
        int val = va_arg(ap, int);
        printf("%d ", val);
    }
    printf("\n");

    // finaliza ap
    va_end(ap);
}