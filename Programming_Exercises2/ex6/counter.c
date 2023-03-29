#include <stdio.h>

#define SEQUENCE_SIZE 1000 // tamanho da sequência

int counter() {
    char sequence[SEQUENCE_SIZE];
    int count_A = 0, count_C = 0, count_G = 0, count_T = 0;
    int i;

    // abre o arquivo para leitura
    FILE *f = fopen("sequencia.txt", "r");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // lê a sequência de bases nitrogenadas do arquivo
    fgets(sequence, SEQUENCE_SIZE, f);
    fclose(f);

    // conta a quantidade de cada base nitrogenada
    for (i = 0; i < SEQUENCE_SIZE && sequence[i] != '\0'; i++) {
        switch (sequence[i]) {
            case 'A':
                count_A++;
                break;
            case 'C':
                count_C++;
                break;
            case 'G':
                count_G++;
                break;
            case 'T':
                count_T++;
                break;
        }
    }

    // imprime os resultados
    printf("Quantidade de bases nitrogenadas:\n");
    printf("A: %d\n", count_A);
    printf("C: %d\n", count_C);
    printf("G: %d\n", count_G);
    printf("T: %d\n", count_T);

    return 0;
}
