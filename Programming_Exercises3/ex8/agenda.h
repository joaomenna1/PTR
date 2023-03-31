#ifndef AGENDA_H
#define AGENDA_H


/*
Este programa lê os dados da agenda a partir do arquivo agenda.txt e exibe na tela os contatos 
salvos na agenda. Para cada contato, é exibido o nome, telefone e idade. A função lerAgenda lê os 
dados do arquivo e armazena na estrutura de dados agenda, que é um vetor de contatos. 
O parâmetro n é passado por referência para a função, pois a função precisa saber quantos contatos 
foram lidos do arquivo e atualizar o valor de n para que seja utilizado posteriormente 
pelo programa.*/
void lerAgenda(struct contato *agenda, int *n);

#endif

