#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQUENCE_SIZE 1000 // tamanho da sequência, obs aumentando o valor pode  dar o segmentation fault
/*
Uma falha de segmentação em C++ ou C ocorre quando algum programa tenta acessar uma parte da memória que não tem permissão para acessar. 
Em palavras simples,quando algum programa tenta acessar a memória que está além dos limites permitidos que o sistema operacional alocou para o programa.
*/

int generator_sequence() {
    char sequence[SEQUENCE_SIZE];
    int i;

    // inicializa o gerador de números aleatórios com a hora atual
    srand(time(NULL));

    // gera a sequência de bases nitrogenadas aleatórias
    for (i = 0; i < SEQUENCE_SIZE - 1; i++) {
        switch (rand() % 4) {
            case 0:
                sequence[i] = 'A';
                break;
            case 1:
                sequence[i] = 'C';
                break;
            case 2:
                sequence[i] = 'G';
                break;
            case 3:
                sequence[i] = 'T';
                break;
        }
    }
    sequence[SEQUENCE_SIZE - 1] = '\0'; // adiciona o caractere nulo de término de string

    // escreve a sequência no arquivo
    FILE *f = fopen("sequencia.txt", "w");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fputs(sequence, f);
    fclose(f);

    printf("Sequência gerada com sucesso.\n");

}