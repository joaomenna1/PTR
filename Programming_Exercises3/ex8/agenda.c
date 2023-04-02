#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 100

// Estrutura para armazenar os dados de um contato
typedef struct {
    char nome[50];
    char telefone[20];
    int idade;
} Contato;

// Estrutura para armazenar a agenda
typedef struct {
    Contato contatos[MAX_CONTATOS];
    int tamanho;
} Agenda;

// Função que lê os contatos de um arquivo e os adiciona na agenda
void lerContatos(Agenda* agenda, char* arquivo) {
    FILE* f = fopen(arquivo, "r");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", arquivo);
        exit(1);
    }
    char linha[100];
    while (fgets(linha, 100, f) != NULL) {
        char* nome = strtok(linha, ",");
        char* telefone = strtok(NULL, ",");
        int idade = atoi(strtok(NULL, ","));
        Contato contato = { "", "", 0 };
        strcpy(contato.nome, nome);
        strcpy(contato.telefone, telefone);
        contato.idade = idade;
        agenda->contatos[agenda->tamanho] = contato;
        agenda->tamanho++;
    }
    fclose(f);
}

// Função que exibe os contatos da agenda
void exibirContatos(Agenda* agenda) {
    printf("Contatos na agenda:\n");
    for (int i = 0; i < agenda->tamanho; i++) {
        Contato contato = agenda->contatos[i];
        printf("Nome: %s\nTelefone: %s\nIdade: %d\n\n", contato.nome, contato.telefone, contato.idade);
    }
}

// Função que adiciona um novo contato na agenda
void adicionarContato(Agenda* agenda, char* nome, char* telefone, int idade) {
    if (agenda->tamanho < MAX_CONTATOS) {
        Contato contato = { "", "", 0 };
        strcpy(contato.nome, nome);
        strcpy(contato.telefone, telefone);
        contato.idade = idade;
        agenda->contatos[agenda->tamanho] = contato;
        agenda->tamanho++;
        printf("Contato %s adicionado com sucesso.\n", nome);
    } else {
        printf("Não foi possível adicionar o contato. A agenda está cheia.\n");
    }
}

// Função que exclui um contato da agenda
void excluirContato(Agenda* agenda, char* nome) {
    int i;
    for (i = 0; i < agenda->tamanho; i++) {
        if (strcmp(agenda->contatos[i].nome, nome) == 0) {
            // Remove o contato da agenda
            for (int j = i; j < agenda->tamanho - 1; j++) {
                agenda->contatos[j] = agenda->contatos[j+1];
            }
            agenda->tamanho--;
            printf("Contato %s removido com sucesso.\n", nome);
            return;
        }
    }
    printf("Contato %s não encontrado na agenda.\n", nome);
}

// Função que modifica os dados de um contato na agenda
void modificarContato(Agenda* agenda, char* nome) {
    int i;
    for (i = 0; i < agenda->tamanho; i++) {
        if (strcmp(agenda->contatos[i].nome, nome) == 0) {
            char novoNome[50];
            char novoTelefone[20];
            int novaIdade;
            printf("Digite o novo nome do contato: ");
            scanf("%s", novoNome);
            printf("Digite o novo telefone do contato: ");
            scanf("%s", novoTelefone);
            printf("Digite a nova idade do contato: ");
            scanf("%d", &novaIdade);
            strcpy(agenda->contatos[i].nome, novoNome);
            strcpy(agenda->contatos[i].telefone, novoTelefone);
            agenda->contatos[i].idade = novaIdade;
            printf("Contato %s modificado com sucesso.\n", nome);
            return;
        }
    }
    printf("Contato %s não encontrado na agenda.\n", nome);
}