#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

#define MAX_NOME 50
#define MAX_AGENDA 1000

// Definição da estrutura Contato
typedef struct {
    char nome[50];
    char telefone[20];
    int idade;
} Agenda;

int main() {
    Agenda listaContatos[MAX_AGENDA];
    int numContatos = 0;
    char nome[50];
    Agenda agenda;
    int opcao;

    lerAgenda(agenda, &n);

    do {
        printf("\n--- AGENDA ---\n");
        printf("1. Exibir contatos\n");
        printf("2. Inserir novo contato\n");
        printf("3. Excluir contato\n");
        printf("4. Excluir Modificar o contato\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n--- Contatos na agenda ---\n");
                for (int i = 0; i < n; i++) {
                    printf("%s - %s - %d anos\n", agenda[i].nome, agenda[i].telefone, agenda[i].idade);
                }
                break;
            case 2:
                inserirContato(agenda, &nome);
                break;
            case 3:
                excluirContato(agenda, &nome);
                break;
            case 4:
                printf("Nome: ");
                scanf("%s", nome);
                modificarContato(listaContatos, numContatos, nome);
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}