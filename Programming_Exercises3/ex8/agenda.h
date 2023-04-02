#ifndef AGENDA_H
#define AGENDA_H

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
void lerContatos(Agenda* agenda, char* arquivo);

// Função que exibe os contatos da agenda
void exibirContatos(Agenda* agenda);

// Função que adiciona um novo contato na agenda
void adicionarContato(Agenda* agenda, char* nome, char* telefone, int idade);

// Função que exclui um contato da agenda
void excluirContato(Agenda* agenda, char* nome);

// Função que modifica os dados de um contato na agenda
void modificarContato(Agenda* agenda, char* nome);

#endif

