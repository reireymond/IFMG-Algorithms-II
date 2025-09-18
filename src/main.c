#include <stdio.h>
#include <stdlib.h>
#include "cadastros.h"
#include "config.h"

void menuGestaoDeDados();

void menuProdutora();

void pausar(); 

void menuEscolherArmazenamento() {
    int opcao;
    printf("\n--- Configuracao de Armazenamento ---\n");
    printf("Escolha como os dados devem ser salvos:\n");
    printf("1. Arquivo Binario (Mais rapido)\n");
    printf("2. Arquivo de Texto (Legivel)\n");
    printf("3. Apenas em Memoria (Dados nao serao salvos)\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            definirModoDeArmazenamento(ARQUIVO_BINARIO);
            printf("Modo de armazenamento definido para: Binario.\n");
            break;
        case 2:
            definirModoDeArmazenamento(ARQUIVO_TEXTO);
            printf("Modo de armazenamento definido para: Texto.\n");
            break;
        case 3:
            definirModoDeArmazenamento(MEMORIA);
            printf("Modo de armazenamento definido para: Memoria.\n");
            break;
        default:
            printf("Opcao invalida. Usando o modo padrao (Binario).\n");
            break;
    }
    pausar();
}

void pausar() {
    printf("\nPressione Enter para continuar...");
    while(getchar() != '\n' && getchar() != EOF);
    getchar();
}

int main() {

    menuEscolherArmazenamento();

    carregarProdutora(); 

    int menu_de_opcoes;
    do {
        system("cls");
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
                pausar();
                break;
            case 3:
                printf("\nModulo em construcao...\n");
                pausar();
                break;
            case 4:
                printf("\nModulo em construcao...\n");
                pausar();
                break;
            case 5:
                printf("\nModulo em construcao...\n");
                pausar();
                break;
            case 0:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                pausar();
                break;
        }

    } while (menu_de_opcoes != 0);
    return 0;
}

void menuGestaoDeDados() {
    int opcao_gestao;
    do {
        system("cls");
        printf("\n--- GESTAO DE DADOS ---\n");
        printf("1. Gerenciar Produtora\n");
        printf("2. Gerenciar Clientes\n");
        printf("3. Gerenciar Equipe Interna\n");
        printf("4. Gerenciar Recursos\n");
        printf("5. Gerenciar Fornecedores\n");
        printf("6. Gerenciar Operadores\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao_gestao);

        switch (opcao_gestao) {
            case 1:
                menuProdutora();
                break;
            case 2:
                printf("\nModulo em construcao...\n");
                pausar();
                break;
            case 3:
                printf("\nModulo em construcao...\n");
                pausar();
                break;
            case 4:
                printf("\nModulo em construcao...\n");
                pausar();
                break;
            case 5:
                printf("\nModulo em construcao...\n");
                pausar();
                break;
            case 6:
                printf("\nModulo em construcao...\n");
                pausar();
                break;
            case 0:
                break;
            default:
                printf("\nOpcao invalida!\n");
                pausar();
                break;
        }

    } while (opcao_gestao != 0);
}

void menuProdutora() {
    int op_prod;
    do {
        system("cls");
        printf("\n--- Menu Produtora ---\n");
        printf("1. Cadastrar Dados\n");
        printf("2. Alterar Dados\n");
        printf("3. Ver Detalhes\n");
        printf("4. Excluir Dados\n");
        printf("0. Voltar ao Menu Anterior\n");
        printf("Escolha: ");
        scanf("%d", &op_prod);

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        switch (op_prod) {
            case 1:
                adicionarProdutora();
                break;
            case 2:
                alterarProdutora();
                break;
            case 3:
                verDetalhesProdutora();
                break;
            case 4:
                excluirProdutora();
                break;
            case 0:
                break;
            default:
                printf("\nOpcao invalida para Produtora!\n");
                break;
        }
        
        if (op_prod != 0) {
            pausar();
        }

    } while (op_prod != 0);
}