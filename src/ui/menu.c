#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "ui/menu.h"

#include "cadastros/produtora.h"
#include "cadastros/cliente.h"
// #include "cadastros/equipe.h"
// #include "cadastros/recurso.h"
// #include "cadastros/fornecedor.h"
#include "cadastros/operador.h"

// --- DECLARAÇÕES DE FUNÇÕES EXTERNAS ---
// Funções que estão em outros arquivos mas são usadas aqui.
void pausar();


// --- DECLARAÇÕES DE FUNÇÕES DE MENU ---
// Funções que estão neste arquivo e podem ser chamadas por outras.
void menuGestaoDeDados();
void menuProdutora();
void menuClientes();
// COMPLETAR AQUI //
void menuOperadores();

/* =========================================================
   Função: menuGestaoDeDados
   Objetivo: Apresenta as opções de gerenciamento de dados
   da produtora: clientes, equipe, recursos, fornecedores
   e operadores.
   ========================================================= */
void menuGestaoDeDados()
{
    int opcao_gestao;
    do
    {
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
        limpar_buffer(); // Evita problemas com Enter no buffer

        switch (opcao_gestao)
        {
        case 1:
            menuProdutora();
            break;
        case 2:
            menuClientes();
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
            menuOperadores();
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

/* =========================================================
   Função: menuProdutora
   Objetivo: Permite ao usuário gerenciar os dados da
   produtora de eventos (cadastrar, alterar, ver e excluir).
   ========================================================= */
void menuProdutora()
{
    int op_prod;
    do
    {
        system("cls");
        printf("\n--- Menu Produtora ---\n");
        printf("1. Cadastrar Dados\n");
        printf("2. Alterar Dados\n");
        printf("3. Ver Detalhes\n");
        printf("4. Excluir Dados\n");
        printf("0. Voltar ao Menu Anterior\n");
        printf("Escolha: ");
        scanf("%d", &op_prod);
        limpar_buffer();

        switch (op_prod)
        {
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

        if (op_prod != 0)
        {
            pausar();
        }

    } while (op_prod != 0);
}

/* =========================================================
   Função: menuClientes
   Objetivo: Permite ao usuário gerenciar os clientes do
   sistema: adicionar, alterar, listar e excluir.
   ========================================================= */
void menuClientes()
{
    int op_cli;
    do
    {
        system("cls");
        printf("\n--- Menu Clientes ---\n");
        printf("1. Adicionar Novo Cliente\n");
        printf("2. Alterar Cliente Existente\n");
        printf("3. Listar Todos os Clientes\n");
        printf("4. Excluir Cliente\n");
        printf("0. Voltar ao Menu Anterior\n");
        printf("Escolha: ");
        scanf("%d", &op_cli);
        limpar_buffer();

        switch (op_cli)
        {
        case 1:
            adicionarCliente();
            break;
        case 2:
            alterarCliente();
            break;
        case 3:
            listarClientes();
            break;
        case 4:
            excluirCliente();
            break;
        case 0:
            break;
        default:
            printf("\nOpcao invalida para Clientes!\n");
            break;
        }

        if (op_cli != 0)
        {
            pausar();
        }

    } while (op_cli != 0);
}

/* =========================================================
   Função: menuOperadores
   Objetivo: Permite ao usuário gerenciar os operadores do
   sistema: adicionar, alterar, listar e excluir.
   ========================================================= */
void menuOperadores()
{
    int op_op;
    do
    {
        system("cls");
        printf("\n--- Menu Operadores ---\n");
        printf("1. Adicionar Novo Operador\n");
        printf("2. Alterar Operador Existente\n");
        printf("3. Listar Todos os Operadores\n");
        printf("4. Excluir Operador\n");
        printf("0. Voltar ao Menu Anterior\n");
        printf("Escolha: ");
        scanf("%d", &op_op);
        limpar_buffer();

        switch (op_op)
        {
        case 1:
            adicionarOperador();
            break;
        case 2:
            alterarOperador();
            break;
        case 3:
            listarOperadores();
            break;
        case 4:
            excluirOperador();
            break;
        case 0:
            break;
        default:
            printf("\nOpcao invalida para Operadores!\n");
            break;
        }

        if (op_op != 0)
        {
            pausar();
        }

    } while (op_op != 0);
}