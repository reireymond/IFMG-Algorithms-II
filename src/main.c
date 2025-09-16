#include <stdio.h>
#include <stdlib.h>

#include "cadastros.h"

void menuGestaoDeDados();

int main()
{
    int menu_de_opcoes;
    do
    {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Gestao de Dados\n");
        printf("2. Gestao de Eventos\n");
        printf("3. Transacoes\n");
        printf("4. FeedBack\n");
        printf("5. Importar ou Exportar Dados\n");
        printf("0. Sair\n");
        printf("\nEscolha sua opcao de modulo desejada: ");
        scanf("%d", &menu_de_opcoes);

        switch (menu_de_opcoes)
        {
        case 1:
            menuGestaoDeDados();
            break;
        case 2:
            printf("\nModulo em construcao...\n");
            break;
        case 3:
            printf("\nModulo em construcao...\n");
            break;
        case 4:
            printf("\nModulo em construcao...\n");
            break;
        case 5:
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

void menuGestaoDeDados()
{
    int opcao_gestao;
    do
    {
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

        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        switch (opcao_gestao)
        {
            printf("\n--- Menu Produtora ---\n");
            printf("1. Adicionar/Cadastrar\n");
            printf("2. Ver Detalhes\n");
            printf("3. Alterar\n");
            printf("4. Excluir\n");
            printf("Escolha: ");
            int op_prod;
            scanf("%d", &op_prod);
            while ((c = getchar()) != '\n' && c != EOF)
                ;

            if (op_prod == 1)
                adicionarProdutora();
            else if (op_prod == 2)
                verDetalhesProdutora();
            else if (op_prod == 3)
                alterarProdutora();
            else if (op_prod == 4)
                excluirProdutora();
            break;

        case 1:
        {
            printf("\n--- Menu Produtora ---\n");
            printf("1. Adicionar/Cadastrar\n");
            printf("2. Ver Detalhes\n");
            printf("3. Alterar\n");
            printf("4. Excluir\n");
            printf("0. Voltar\n");
            printf("Escolha: ");

            int op_prod;
            scanf("%d", &op_prod);
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;

            switch (op_prod)
            {
            case 1:
                adicionarProdutora();
                break;
            case 2:
                verDetalhesProdutora();
                break;
            case 3:
                alterarProdutora();
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
            break;
        }

        case 2:
            printf("\nModulo de Clientes em construcao...\n"); // Aqui você chamaria um menu para clientes, similar ao da produtora
            break;
        case 0:
            printf("\nVoltando ao menu principal...\n");
            break;
        default:
            printf("\nOpcao invalida!\n");
            break;
        }

    } while (opcao_gestao != 0);
}