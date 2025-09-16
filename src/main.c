#include <stdio.h>
#include <stdlib.h>
#include "cadastros.h"

// Protótipos das funções de menu
void menuGestaoDeDados();
void menuProdutora();

// Função para pausar a tela e esperar o usuário pressionar Enter
void pausar() {
    printf("\nPressione Enter para continuar...");
    // Limpa o buffer de qualquer caractere restante
    while(getchar() != '\n' && getchar() != EOF);
    // Espera o usuário pressionar Enter
    getchar();
}

int main() {
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
            case 3:
            case 4:
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
            
            // --- ESTA É A PARTE IMPORTANTE PARA OS SUBMENUS ---
            // Todos os casos em construção agora levam para a mesma mensagem e pausa
            case 2: // Clientes
            case 3: // Equipe Interna
            case 4: // Recursos
            case 5: // Fornecedores
            case 6: // Operadores
                printf("\nModulo em construcao...\n");
                pausar(); // A pausa agora funciona para todos estes submenus
                break;
            
            case 0:
                // Não faz nada, apenas volta ao menu principal
                break;
            default:
                printf("\nOpcao invalida!\n");
                pausar();
                break;
        }

    } while (opcao_gestao != 0);
}

// A função menuProdutora() continua a mesma, pois já está completa
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