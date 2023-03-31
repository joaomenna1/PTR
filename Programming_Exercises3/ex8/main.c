#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_AGENDA 100

int main() {
    struct contato agenda[MAX_AGENDA];
    int n = 0;

    lerAgenda(agenda, &n);

    printf("--- Contatos na agenda ---\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %s - %d anos\n", agenda[i].nome, agenda[i].telefone, agenda[i].idade);
    }

    return 0;
}