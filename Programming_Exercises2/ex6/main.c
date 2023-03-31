#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generator_sequence.h"
#include "counter.h"

/*
    Se assumirmos que o tempo de leitura do disco rígido é o gargalo principal do programa e que as outras operações são insignificantes em comparação, 
    podemos fazer uma estimativa aproximada do tempo de processamento com base na taxa de transferência do disco rígido. 
    Vamos supor que a taxa de transferência do disco rígido seja de 150 MB/s (megabytes por segundo), 
    que é uma taxa típica para discos rígidos modernos. Com um bloco de leitura de 10 milhões de bases nitrogenadas (40 MB), 
    o tempo de leitura seria de aproximadamente 0,27 segundos por bloco.
    Se o programa ler o arquivo em blocos de 10 milhões de bases nitrogenadas e processar um bloco por vez, serão necessárias 100.000 iterações do 
    loop principal para processar todo o arquivo. Nesse caso, o tempo de processamento total seria de aproximadamente 27.000 segundos (ou cerca de 7,5 horas). 
    No entanto, este é apenas um cálculo aproximado e o tempo real de processamento pode variar dependendo de muitos outros fatores
*/

int main() {
    generator_sequence();
    counter();
    return 0;
}

/*
  Quanto tera o tamanho do arquivo?
  Se o arquivo gerado contém uma sequência de 1 trilhão de bases nitrogenadas, e cada base nitrogenada é representada por um único caractere, 
  então o tamanho do arquivo será de 1 trilhão de caracteres.

   Assumindo que estamos trabalhando com um código ASCII padrão, onde cada caractere é representado por 1 byte (8 bits), 
   o tamanho do arquivo seria de aproximadamente 1 terabyte (ou seja, 1000 gigabytes ou 1.000.000 megabytes).

   No entanto, se as bases nitrogenadas são representadas por códigos mais compactos, como códigos de 2 bits, 
   então o tamanho do arquivo seria de cerca de 250 gigabytes. O tamanho real do arquivo pode variar dependendo da codificação utilizada.
*/
