## Descrição
- Levantamento das principais funções da biblioteca padrão de C, notadamente da entrada e saída padrão.<br>

## Principais funções

-**`printf e scanf`**: são as funções de saída e entrada padrão, respectivamente. A função "printf" é usada para imprimir dados na saída padrão (normalmente o console), enquanto a função "scanf" é usada para ler dados da entrada padrão (também normalmente o console). Essas funções permitem que o programa se comunique com o usuário por meio de entrada e saída de dados. <br>

-**`fopen, fclose", fread" e fwrite`**: Essas funções são usadas para manipular arquivos. A função "fopen" é usada para abrir um arquivo, enquanto a função "fclose" é usada para fechá-lo. As funções "fread" e "fwrite" são usadas para ler e escrever dados em um arquivo, respectivamente.<br>

-**`fgets e fputs`**: Essas funções são usadas para ler e escrever strings em arquivos. A função "fgets" lê uma string do arquivo e a armazena em um buffer, enquanto a função "fputs" escreve uma string em um arquivo.<br>

-**`getchar e putchar`**: Essas funções são usadas para ler e escrever caracteres na entrada e saída padrão. A função "getchar" lê um caractere da entrada padrão e a função "putchar" escreve um caractere na saída padrão.<br>

-**`strlen()`**: Para obter o tamanho de uma string.<br>

-**`strcpy()`**: Para copiar uma string para outra.<br>

-**`strcat()`**: Para concatenar duas strings.<br>

-**`strcmp()`**: para comparar duas strings.<br>

-**`malloc()`**:Para alocar memória dinamicamente<br>

-**`calloc()`**:Para alocar memória dinamicamente e inicializá-la com zeros<br>

-**`realloc()`**: Para redimensionar uma área de memória alocada dinamicamente;<br>

-**`free()`**: Para liberar a memória alocada dinamicamente.<br>

-**`time()`**: para obter a data e horário atual em segundos desde 1 de janeiro de 1970<br>

-**`localtime()`**: para converter o tempo em segundos para uma estrutura struct tm contendo informações de data e hora locais.<br>

-**`strftime()`**: para formatar uma estrutura struct tm em uma string de data e hora.<br>

-**`rand()`**: para gerar números aleatórios;<br>

-**`system()`**: para executar comandos do sistema operacional;<br>

-**`exit()`**: para encerrar um programa.<br>


## Exemplos
### printf:
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

### scanf:
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

### fopen, fclose, fread e fwrite:

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

### fgets e fputs:
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

### fgets e fputs:
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

### strlen, strcpy, strcat e strcmp:

```bash
#include <stdio.h>
#include <string.h>

int main() {
  char str1[20] = "Hello";
  char str2[20] = "World";

  // usando a função strlen() para obter o tamanho de uma string
  printf("O tamanho de str1 é %d\n", strlen(str1));

  // usando a função strcpy() para copiar uma string para outra
  strcpy(str1, str2);
  printf("str1 agora é: %s\n", str1);

  // usando a função strcat() para concatenar duas strings
  strcat(str1, str2);
  printf("str1 agora é: %s\n", str1);

  // usando a função strcmp() para comparar duas strings
  int result = strcmp(str1, str2);
  if (result == 0) {
    printf("str1 e str2 são iguais\n");
  } else if (result < 0) {
    printf("str1 vem antes de str2 no dicionário\n");
  } else {
    printf("str1 vem depois de str2 no dicionário\n");
  }

  return 0;
}
```
Neste exemplo, strlen() é usada para obter o tamanho da string str1, strcpy() é usada para copiar o conteúdo da string str2 para a string str1, strcat() é usada para concatenar a string str2 na string str1 e strcmp() é usada para comparar as strings str1 e str2. As saídas do programa seriam:

```bash
O tamanho de str1 é 5
str1 agora é: World
str1 agora é: WorldWorld
str1 vem depois de str2 no dicionário
```
<br>


### malloc, realloc e free:

```bash
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);

  // usando a função malloc() para alocar memória para um vetor de inteiros
  int *vetor = (int*) malloc(n * sizeof(int));

  // preenchendo o vetor com valores informados pelo usuário
  for (int i = 0; i < n; i++) {
    printf("Digite o valor para a posição %d: ", i);
    scanf("%d", &vetor[i]);
  }

  // imprimindo os valores do vetor
  printf("Valores do vetor: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  // usando a função realloc() para redimensionar o vetor
  n += 3;
  vetor = (int*) realloc(vetor, n * sizeof(int));

  // preenchendo as novas posições do vetor com valores aleatórios
  for (int i = n - 3; i < n; i++) {
    vetor[i] = rand() % 100;
  }

  // imprimindo os valores do vetor após a realocação
  printf("Valores do vetor após realocação: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  // usando a função free() para liberar a memória alocada para o vetor
  free(vetor);

  return 0;
}
```

Neste exemplo, malloc() é usada para alocar memória para um vetor de inteiros com um tamanho definido pelo usuário. Em seguida, o vetor é preenchido com valores também informados pelo usuário. Depois, realloc() é usada para aumentar o tamanho do vetor em mais 3 posições e preencher essas novas posições com valores aleatórios. Por fim, free() é usada para liberar a memória alocada para o vetor. A saída do programa seria algo parecido com:<br>

```bash
Digite o tamanho do vetor: 5
Digite o valor para a posição 0: 10
Digite o valor para a posição 1: 20
Digite o valor para a posição 2: 30
Digite o valor para a posição 3: 40
Digite o valor para a posição 4: 50
Valores do vetor: 10 20 30 40 50
Valores do vetor após realocação: 10 20 30 40 50 25 76 14
```
<br>

### time, localtime e strftime:
```bash
#include <stdio.h>
#include <time.h>

int main() {
  time_t t;
  struct tm *info;
  char buffer[80];

  // obtendo a hora atual do sistema
  time(&t);

  // convertendo a hora atual em uma estrutura de tempo local
  info = localtime(&t);

  // formatando a hora atual como uma string
  strftime(buffer, 80, "Hoje é %A, %d de %B de %Y, e são %H:%M:%S.", info);

  // imprimindo a hora formatada
  printf("%s\n", buffer);

  return 0;
}
```

Neste exemplo, time() é usada para obter a hora atual do sistema, que é armazenada na variável t. Em seguida, localtime() é usada para converter a hora atual em uma estrutura de tempo local, que é armazenada na variável info. Finalmente, strftime() é usada para formatar a hora atual como uma string, usando a formatação especificada no segundo argumento. A string formatada é armazenada no array de caracteres buffer. A saída do programa seria algo parecido com:

```bash
Hoje é domingo, 20 de março de 2022, e são 14:30:00.
```
<br>

A formatação utilizada em strftime() pode ser personalizada de acordo com as necessidades do programa. No exemplo acima, %A representa o nome completo do dia da semana, %d representa o dia do mês com dois dígitos, %B representa o nome completo do mês, %Y representa o ano com quatro dígitos, %H representa a hora em formato 24 horas com dois dígitos, %M representa os minutos com dois dígitos e %S representa os segundos com dois dígitos.


### rand, system e exit:

```bash
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num;
  
  // gerando um número aleatório entre 1 e 10
  srand(time(NULL));
  num = rand() % 10 + 1;
  
  printf("O número gerado é %d\n", num);

  // executando um comando do sistema operacional
  printf("Pressione qualquer tecla para limpar a tela...");
  system("pause");
  system("cls");

  // encerrando o programa com um código de retorno
  exit(0);
}
```

Neste exemplo, rand() é usada para gerar um número aleatório entre 1 e 10, que é armazenado na variável num. Observe que, antes de usar a função rand(), a função srand() é chamada com o valor time(NULL) como argumento. Isso inicializa o gerador de números aleatórios com uma semente baseada no tempo atual do sistema, garantindo que números diferentes sejam gerados a cada execução do programa.

Em seguida, a função system() é usada para executar um comando do sistema operacional. No exemplo acima, o comando pause é usado para esperar que o usuário pressione qualquer tecla antes de continuar, e em seguida, o comando cls é usado para limpar a tela do console.

Por fim, a função exit() é usada para encerrar o programa com um código de retorno. No exemplo acima, o código de retorno é 0, indicando que o programa foi encerrado com sucesso. O código de retorno pode ser usado por outros programas ou scripts que chamam este programa para determinar se o programa foi executado com sucesso ou não.
<br>