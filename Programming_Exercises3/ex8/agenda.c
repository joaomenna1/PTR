#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_AGENDA 1000

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

void inserirContato(struct contato *agenda, int *n) {
    if (*n == MAX_AGENDA) {
        printf("Agenda cheia! Impossível inserir novo contato.\n");
        return;
    }

    printf("Digite o nome do novo contato: ");
    scanf("%s", agenda[*n].nome);

    printf("Digite o telefone do novo contato: ");
    scanf("%s", agenda[*n].telefone);

    printf("Digite a idade do novo contato: ");
    scanf("%d", &agenda[*n].idade);

    (*n)++;
}

void excluirContato(struct contato *agenda, int *n) {
    char nomeExcluir[MAX_NOME];
    int i, posicaoExcluir = -1;

    printf("Digite o nome do contato a ser excluído: ");
    scanf("%s", nomeExcluir);

    for (i = 0; i < *n; i++) {
        if (strcmp(nomeExcluir, agenda[i].nome) == 0) {
            posicaoExcluir = i;
            break;
        }
    }

    if (posicaoExcluir == -1) {
        printf("Contato não encontrado na agenda.\n");
        return;
    }

    for (i = posicaoExcluir; i < (*n) - 1; i++) {
        strcpy(agenda[i].nome, agenda[i + 1].nome);
        strcpy(agenda[i].telefone, agenda[i + 1].telefone);
        agenda[i].idade = agenda[i + 1].idade;
    }

    (*n)--;
    printf("Contato excluído com sucesso!\n");
}

void modificarContato(struct contato *agenda, int n) {
    char nomeModificar[MAX_NOME];
    int i, posicaoModificar = -1;

    printf("Digite o nome do contato a ser modificado: ");
    scanf("%s", nomeModificar);

    for (i = 0; i < n; i++) {
        if (strcmp(nomeModificar, agenda[i].nome) == 0) {
            posicaoModificar = i;
            break;
        }
    }

    if (posicaoModificar == -1) {
        printf("Contato não encontrado na agenda.\n");
        return;
    }

    printf("Digite o novo telefone do contato: ");
    scanf("%s", agenda[posicaoModificar].telefone);

    printf("Digite a nova idade do contato: ");
    scanf("%d", &agenda[posicaoModificar].idade);

    printf("Contato modificado com sucesso!\n");
}
