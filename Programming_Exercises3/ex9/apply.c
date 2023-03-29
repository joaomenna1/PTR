#include <stdio.h>

void apply(void (*function)(int val), int n, int arr[n]) {
    for (int i = 0; i < n; i++) {
        function(arr[i]);
    }
}