/*
Essa declaração é uma definição de função em C, que recebe três parâmetros:

 - Um ponteiro para uma função que recebe um inteiro como argumento 
   e não retorna nenhum valor (void (*function)(int val)).
 - Um inteiro n (int n).
 - Um ponteiro para um array de inteiros de tamanho n (int arr[n]).
Essa função se chama "apply" e seu objetivo é aplicar a função recebida 
como argumento para cada elemento do array.

O ponteiro para a função é passado como um parâmetro para permitir que a função "apply" 
seja genérica e possa ser usada com diferentes funções que recebem um inteiro como argumento.

Este programa define uma função "doubleVal" que recebe um inteiro e imprime seu dobro na saída padrão. 
Em seguida, ele define uma função "apply" que recebe um ponteiro para uma função, um tamanho de array
e um array de inteiros. A função "apply" aplica a função recebida como argumento a cada elemento do array.

No main, é definido um array de inteiros e o tamanho do array é calculado automaticamente. 
Em seguida, a função "apply" é chamada com a função "doubleVal", o tamanho do array e o array de inteiros. 
O programa imprime o dobro de cada elemento do array na saída padrão.
*/


#include <stdio.h>
#include "lib.h"

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    apply(doubleVal, n, arr);
    return 0;
}