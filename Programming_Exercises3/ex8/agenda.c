#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_AGENDA 100

struct contato {
    char nome[MAX_NOME];
    char telefone[15];
    int idade;
};


void lerAgenda(struct contato *agenda, int *n) {
    FILE *arquivo;
    arquivo = fopen("agenda.txt", "r");

    if (arquivo == NULL) {
        printf("Falha ao abrir o arquivo, pois esta vazia!\n");
        return;
    }

    while (!feof(arquivo) && *n < MAX_AGENDA) {
        fscanf(arquivo, "%s %s %d", agenda[*n].nome, agenda[*n].telefone, &agenda[*n].idade);
        (*n)++;
    }

    fclose(arquivo);
}