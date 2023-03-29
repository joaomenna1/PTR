## Descrição
- Procure por Variadic Functions na biblioteca padrão. Estude as
macros e funções para funções de argumentos variáveis e faça
uma descrição delas.
<br>
### As principais funçoes<br>
- A principal função variádica da biblioteca padrão C é a função printf(), que é usada para imprimir valores formatados na saída padrão.
- va_start(): essa função é usada para inicializar um objeto do tipo va_list, que é usado para percorrer a lista de argumentos variáveis passados para uma função variádica.
- va_arg(): essa função é usada para obter o próximo argumento na lista de argumentos variáveis passados para uma função variádica. O tipo do argumento a ser obtido é especificado como um parâmetro para a função.
- va_copy(): essa função é usada para criar uma cópia de um objeto do tipo va_list.
- va_end(): essa função é usada para finalizar o processamento da lista de argumentos variáveis passados para uma função variádica.

Além disso, a biblioteca padrão C fornece macros para facilitar o uso de funções variádicas, como a macro va_start(), que é usada para inicializar um objeto do tipo va_list, e a macro va_arg(), que é usada para obter o próximo argumento na lista de argumentos variáveis.
<br>

- Neste exemplo, a função print_values aceita uma quantidade variável de valores inteiros, representados pelo parâmetro count e os argumentos variáveis que seguem o count. A função usa a função va_list para percorrer a lista de argumentos variáveis.

A função começa chamando va_start para inicializar ap e ap_copy, passando count como último parâmetro fixo. Em seguida, ela usa o va_arg para percorrer a lista de argumentos variáveis, imprimindo os valores passados. A função também imprime a quantidade de valores passados e a soma dos valores passados.

Observe que a função usa o va_copy para criar uma cópia de ap em ap_copy. Isso é necessário porque o va_arg modifica o ap à medida que a função percorre a lista de argumentos variáveis. Portanto, para calcular a soma dos valores passados, precisamos percorrer a lista novamente, usando a cópia ap_copy.

Finalmente, a função usa o va_end para finalizar ap e ap_copy.

```bash
#include <stdio.h>
#include <stdarg.h>

void print_values(int count, ...)
{
    va_list ap, ap_copy;

    // inicializa ap e ap_copy
    va_start(ap, count);
    va_copy(ap_copy, ap);

    // imprime os valores passados para a função
    printf("Values: ");
    for (int i = 0; i < count; i++) {
        int val = va_arg(ap, int);
        printf("%d ", val);
    }
    printf("\n");

    // imprime a quantidade de valores passados para a função
    printf("Count: %d\n", count);

    // imprime a soma dos valores passados para a função
    int sum = 0;
    for (int i = 0; i < count; i++) {
        int val = va_arg(ap_copy, int);
        sum += val;
    }
    printf("Sum: %d\n", sum);

    // finaliza ap e ap_copy
    va_end(ap);
    va_end(ap_copy);
}

int main()
{
    // chama a função passando uma lista variável de valores
    print_values(5, 1, 2, 3, 4, 5);

    return 0;
}

```

A saída do programa será:

```bash
Values: 1 2 3 4 5
Count: 5
Sum: 15
```

Isso indica que a função recebeu 5 valores como argumentos variáveis, que a soma desses valores é 15 e que a função conseguiu imprimir todos os valores passados.
<br>


### Macros
- O macro va_start() é usado para inicializar um objeto do tipo va_list, que é usado para percorrer a lista de argumentos variáveis passados para uma função variádica. 
  O macro va_arg() é usado para obter o próximo argumento na lista de argumentos variáveis.
Para usar esses macros, você deve incluir a biblioteca stdarg.h e seguir as seguintes etapas:
 1 - Declare a função variádica e seus argumentos fixos normalmente.
 2 - Use o macro va_list para declarar um objeto do tipo va_list que será usado para percorrer a lista de argumentos variáveis.
 3 - Use o macro va_start para inicializar o objeto va_list, especificando o último parâmetro fixo da função como argumento. Por exemplo:
```bash
        va_list args;
        va_start(args, last_fixed_arg);
```
<br>
 4 - Use o macro va_arg para obter o próximo argumento na lista de argumentos variáveis. Especificar o tipo do argumento como o segundo argumento do macro. Por exemplo:
 ```bash
        int arg1 = va_arg(args, int);
        double arg2 = va_arg(args, double);
```
<br>
 5 - Repita o passo 4 para obter todos os argumentos variáveis da lista.
 6 -Quando terminar de processar os argumentos variáveis, use o macro va_end para finalizar o objeto va_list. Por exemplo:

```bash
   va_end(args);
```
<br>

Segue um exemplo completo de como usar o va_start() e va_arg() para imprimir uma lista variável de números inteiros usando a função printf():

  ```bash
#include <stdio.h>
#include <stdarg.h>

void print_ints(int num, ...)
{
    va_list args;
    va_start(args, num);

    for (int i = 0; i < num; i++) {
        int val = va_arg(args, int);
        printf("%d ", val);
    }

    va_end(args);
}

int main()
{
    print_ints(3, 1, 2, 3);
    return 0;
}
```

Nesse exemplo, a função print_ints() recebe um argumento inteiro (num) seguido por uma lista variável de inteiros. O objeto va_list args é inicializado usando o macro va_start() e a lista de argumentos variáveis é processada usando o macro va_arg(). Finalmente, o objeto va_list é finalizado usando o macro va_end(). A função main() chama a função print_ints() passando três inteiros como argumentos variáveis. A saída do programa será:

```bash
   1 2 3
```
