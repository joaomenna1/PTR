#ifndef AGENDA_H
#define AGENDA_H

#define MAX_NOME 50
#define MAX_AGENDA 1000

struct contato {
    char nome[MAX_NOME];
    char telefone[15];
    int idade;
};

/*
Este programa lê os dados da agenda a partir do arquivo agenda.txt e exibe na tela os contatos 
salvos na agenda. Para cada contato, é exibido o nome, telefone e idade. A função lerAgenda lê os 
dados do arquivo e armazena na estrutura de dados agenda, que é um vetor de contatos. 
O parâmetro n é passado por referência para a função, pois a função precisa saber quantos contatos 
foram lidos do arquivo e atualizar o valor de n para que seja utilizado posteriormente 
pelo programa.*/
void lerAgenda(struct contato *agenda, int *n);

/*
inserirContato, que recebe como parâmetros o vetor de contatos agenda e o número atual de contatos n. 
A função solicita ao usuário que digite o nome, telefone e idade do novo contato, 
e armazena esses dados na próxima posição livre do vetor agenda. 
Caso a agenda já esteja cheia, a função exibe uma mensagem de erro.
*/
void inserirContato(struct contato *agenda, int *n);

void excluirContato(struct contato *agenda, int *n);

void modificarContato(struct contato *agenda, int n);

#endif

