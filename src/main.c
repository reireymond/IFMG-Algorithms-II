#include <stdio.h>
#include <stdlib.h>

#include <structs.h>

int main() {
    int menu_de_opcoes;
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Gestao de Dados\n");
        printf("2. Gestao de Eventos\n");
        printf("3. Transacoes\n");
        printf("4. FeedBack\n");
        printf("5. Importar ou Exportar Dados\n");
        printf("0. Sair\n");
        printf("\nEscolha sua opcao de modulo desejada: ");
        scanf("%d", &menu_de_opcoes);

        switch (menu_de_opcoes) {
            case 1:
                menuGestaoDeDados();
                break;
            case 2:
                printf("\nModulo em construcao...\n");
                break;
            case 0:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                break;
        }

    } while (menu_de_opcoes != 0);
    return 0;
}