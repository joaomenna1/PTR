#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Tamanho do blocoo de escrita do arquivo
#define BLOCK_SIZE 10000000  // 10 milhões

// Total de bases nitrogenadas a serem geradas
#define TOTAL_BASES 1000000000000 // 1 TRILHAO

int generator_sequence() {
    // ABRE O ARQUIVO PARA ESCRITA
    FILE *fp;
    fp = fopen("sequencia_aleatoria.txt", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    srand(time(NULL));

    //loop para gerar e escrever os dados em blocos
    for (long i = 0; i < TOTAL_BASES; i += BLOCK_SIZE) {
        // aLOCA O BLOCO DE MEMORIA PARA ARMAZENAR OS DADOS
        char *data = malloc(BLOCK_SIZE * sizeof(char));

        // gera o blco de dados aleatorios
        for (int j = 0; j < BLOCK_SIZE; j++) {
            data[j] = "ACGT"[rand() % 4];
        } 

        //Escreve o bloco no arquivo
        fwrite(data, sizeof(char), BLOCK_SIZE, fp);

        // libera a memoria do bloco
        free(data);
    }

    fclose(fp);

    return 0;   
}
