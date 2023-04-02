#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

int main() {
    Agenda agenda = { {0}, 0 };
    lerContatos(&agenda, "dados.txt");

    char novoNome[50];
    char novoTelefone[20];
    int novaIdade;
    char nomeExcluir[50];
    char nomeModificar[50];

    printf("Bem-vindo à agenda!\n\n");
    int opcao = 0;
    while (opcao != 5) {
        printf("Escolha uma opção:\n");
        printf("1. Exibir contatos\n");
        printf("2. Adicionar contato\n");
        printf("3. Excluir contato\n");
        printf("4. Modificar contato\n");
        printf("5. Sair\n");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao) {
            case 1:
                exibirContatos(&agenda);
                break;
            case 2:
                printf("Digite o nome do novo contato: ");
                scanf("%s", novoNome);
                printf("Digite o telefone do novo contato: ");
                scanf("%s", novoTelefone);
                printf("Digite a idade do novo contato: ");
                scanf("%d", &novaIdade);
                adicionarContato(&agenda, novoNome, novoTelefone, novaIdade);
                break;
            case 3:  
                printf("Digite o nome do contato que deseja excluir: ");
                scanf("%s", nomeExcluir);
                excluirContato(&agenda, nomeExcluir);
                break;
            case 4:
                printf("Digite o nome do contato que deseja modificar: ");
                scanf("%s", nomeModificar);
                modificarContato(&agenda, nomeModificar);
                break;
            case 5:
                printf("Obrigado por usar a agenda!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}
