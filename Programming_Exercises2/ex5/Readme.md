## Descrição
- Levantamento das principais funções da biblioteca padrão de C, notadamente da entrada e saída padrão.<br>

## Principais funções
-**`printf e scanf`**: são as funções de saída e entrada padrão, respectivamente. A função "printf" é usada para imprimir dados na saída padrão (normalmente o console), enquanto a função "scanf" é usada para ler dados da entrada padrão (também normalmente o console). Essas funções permitem que o programa se comunique com o usuário por meio de entrada e saída de dados. <br>
-**`fopen, fclose", fread" e fwrite`**: Essas funções são usadas para manipular arquivos. A função "fopen" é usada para abrir um arquivo, enquanto a função "fclose" é usada para fechá-lo. As funções "fread" e "fwrite" são usadas para ler e escrever dados em um arquivo, respectivamente.<br>
-**`fgets" e fputs`**: Essas funções são usadas para ler e escrever strings em arquivos. A função "fgets" lê uma string do arquivo e a armazena em um buffer, enquanto a função "fputs" escreve uma string em um arquivo.<br>
-**`getchar e putchar`**: Essas funções são usadas para ler e escrever caracteres na entrada e saída padrão. A função "getchar" lê um caractere da entrada padrão e a função "putchar" escreve um caractere na saída padrão.<br>
-**`strlen()`**: Para obter o tamanho de uma string;
-**`strcpy()`**: Para copiar uma string para outra;
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:
-**`getchar e putchar`**:


## Exemplos
# printf:
```bash
#include <stdio.h>

int main() {
    int idade = 30;
    float altura = 1.75;
    printf("Minha idade é %d anos e minha altura é %.2f metros.\n", idade, altura);
    return 0;
}
```
Nesse exemplo, a função printf é utilizada para imprimir a idade e altura da pessoa. Note que são utilizados especificadores de formato, como %d e %.2f, para indicar que o valor das variáveis idade e altura deve ser inserido na string.<br>

# scanf:
```bash
#include <stdio.h>

int main() {
    int idade;
    float altura;
    printf("Digite sua idade e altura, separados por um espaço:\n");
    scanf("%d %f", &idade, &altura);
    printf("Sua idade é %d anos e sua altura é %.2f metros.\n", idade, altura);
    return 0;
}
```
Nesse exemplo, a função scanf é utilizada para ler a idade e altura da pessoa a partir da entrada padrão. Note que, assim como na função printf, são utilizados especificadores de formato, como %d e %f, para indicar que o valor lido deve ser armazenado nas variáveis idade e altura. É importante notar também que os endereços de memória das variáveis idade e altura são passados como argumentos para a função scanf, utilizando o operador &.<br>

# fopen, fclose, fread e fwrite:

```bash
#include <stdio.h>

int main() {
    FILE *arquivo;
    int vetor[5] = {1, 2, 3, 4, 5};
    int vetor_lido[5];

    // Abrir arquivo para escrita
    arquivo = fopen("meu_arquivo.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    // Escrever o vetor no arquivo
    fwrite(vetor, sizeof(int), 5, arquivo);

    // Fechar arquivo
    fclose(arquivo);

    // Abrir arquivo para leitura
    arquivo = fopen("meu_arquivo.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    // Ler o vetor do arquivo
    fread(vetor_lido, sizeof(int), 5, arquivo);

    // Fechar arquivo
    fclose(arquivo);

    // Imprimir vetor lido
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor_lido[i]);
    }
    printf("\n");

    return 0;
}

```

Nesse exemplo, é criado um vetor de inteiros vetor com 5 elementos, que é escrito em um arquivo chamado "meu_arquivo.bin" utilizando a função fwrite. Em seguida, o arquivo é fechado com a função fclose.

Depois, o mesmo arquivo é aberto novamente para leitura utilizando a função fopen, e o vetor é lido do arquivo utilizando a função fread. Finalmente, o arquivo é fechado novamente com a função fclose e o vetor lido é impresso na tela com um loop for.

É importante notar que, ao utilizar as funções fwrite e fread, é preciso especificar o tamanho do elemento que está sendo escrito/lido (no caso, sizeof(int)) e o número de elementos a serem escritos/lidos (no caso, 5). Isso é importante para garantir que o arquivo seja lido e escrito corretamente. Além disso, ao utilizar a função fopen, é possível especificar o modo de abertura do arquivo (no caso, "wb" para escrita binária e "rb" para leitura binária).<br>

# fgets e fputs:
```bash
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

int main() {
    FILE *arquivo;
    char linha[MAX_LEN];

    // Abrir arquivo para escrita
    arquivo = fopen("meu_arquivo.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    // Escrever algumas linhas no arquivo
    fputs("Esta é a primeira linha.\n", arquivo);
    fputs("Esta é a segunda linha.\n", arquivo);
    fputs("Esta é a terceira linha.\n", arquivo);

    // Fechar arquivo
    fclose(arquivo);

    // Abrir arquivo para leitura
    arquivo = fopen("meu_arquivo.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    // Ler as linhas do arquivo e imprimir na tela
    while (fgets(linha, MAX_LEN, arquivo) != NULL) {
        printf("%s", linha);
    }

    // Fechar arquivo
    fclose(arquivo);

    return 0;
}
```

Nesse exemplo, é criado um arquivo chamado "meu_arquivo.txt" utilizando a função fopen com modo de abertura "w" (escrita). Em seguida, algumas linhas de texto são escritas no arquivo utilizando a função fputs. O arquivo é fechado com a função fclose.

Depois, o mesmo arquivo é aberto novamente para leitura utilizando a função fopen com modo de abertura "r" (leitura). Em seguida, as linhas do arquivo são lidas utilizando a função fgets e impressas na tela com um loop while. É importante notar que a função fgets lê uma linha por vez (até encontrar um caractere de nova linha ou atingir o limite de caracteres especificado), e que o caractere de nova linha é mantido no final da linha lida. Por isso, ao imprimir a linha na tela, é preciso utilizar o comando printf("%s", linha) em vez de simplesmente printf(linha).

Por fim, o arquivo é fechado novamente com a função fclose.

# fgets e fputs:
```bash
#include <stdio.h>

int main() {
    char c;

    printf("Digite um caractere: ");
    c = getchar();

    printf("O caractere digitado foi: ");
    putchar(c);
    printf("\n");

    return 0;
}
```
Nesse exemplo, é solicitado que o usuário digite um caractere utilizando a função getchar. O caractere digitado é armazenado na variável c. Em seguida, o caractere é impresso na tela utilizando a função putchar. É importante notar que a função putchar imprime apenas um único caractere (no caso, o valor de c), e que é preciso utilizar o comando printf("\n") para imprimir uma quebra de linha no final da saída.

Caso você queira ler e imprimir uma sequência de caracteres (uma string), pode utilizar a função gets para ler a entrada e a função puts para imprimir a saída. Entretanto, é importante notar que a função gets não é segura e pode causar problemas de segurança. Uma alternativa mais segura é utilizar a função fgets. Segue abaixo um exemplo simples:<br>

```bash
#include <stdio.h>

#define MAX_LEN 100

int main() {
    char linha[MAX_LEN];

    printf("Digite uma linha de texto: ");
    fgets(linha, MAX_LEN, stdin);

    printf("A linha digitada foi: ");
    puts(linha);

    return 0;
}
```
Nesse exemplo, é solicitado que o usuário digite uma linha de texto utilizando a função fgets. A linha de texto é armazenada na variável linha. Em seguida, a linha é impressa na tela utilizando a função puts. É importante notar que a função fgets lê uma linha de texto (até encontrar um caractere de nova linha ou atingir o limite de caracteres especificado), e que o caractere de nova linha é mantido no final da linha lida. Por isso, ao imprimir a linha na tela, é preciso utilizar a função puts em vez de simplesmente printf.

