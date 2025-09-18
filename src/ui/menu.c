#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "utils.h"
#include "ui/menu.h"

#include "cadastros/produtora.h"
#include "cadastros/cliente.h"
#include "cadastros/equipe.h"
#include "cadastros/recurso.h"
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
void menuEquipeInterna();
void menuRecursos();
void menuOperadores();

/* =========================================================
   Função: menuEscolherArmazenamento
   Objetivo: Permite ao usuário escolher como os dados serão
   salvos no sistema.
   ========================================================= */
void menuEscolherArmazenamento()
{
    int opcao;
    printf("\n--- Configuracao de Armazenamento ---\n");
    printf("Escolha como os dados devem ser salvos:\n");
    printf("1. Arquivo Binario (Mais rapido)\n");
    printf("2. Arquivo de Texto (Legivel)\n");
    printf("3. Apenas em Memoria (Dados nao serao salvos)\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    limpar_buffer();

    switch (opcao)
    {
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
        definirModoDeArmazenamento(ARQUIVO_BINARIO);
        break;
    }
    pausar();
}

/* =========================================================
   Função: menuPrincipal
   Objetivo: Exibe o menu principal e controla a navegação.
   ========================================================= */
void menuPrincipal()
{
    int menu_de_opcoes;
    do
    {
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
        limpar_buffer();

        switch (menu_de_opcoes)
        {
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
}

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
            menuEquipeInterna();
            break;
        case 4:
            menuRecursos();
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

/* =========================================================
   Função: menuEquipeInterna
   Objetivo: Permite ao usuário gerenciar a equipe interna
   do sistema: adicionar, alterar, listar e excluir.
   ========================================================= */
void menuEquipeInterna()
{
    int op_eq;
    do
    {
        system("cls");
        printf("\n--- Menu Equipe Interna ---\n");
        printf("1. Adicionar Novo Membro\n");
        printf("2. Alterar Membro Existente\n");
        printf("3. Listar Todos os Membros\n");
        printf("4. Excluir Membro\n");
        printf("0. Voltar ao Menu Anterior\n");
        printf("Escolha: ");
        scanf("%d", &op_eq);
        limpar_buffer();

        switch (op_eq)
        {
        case 1:
            adicionarEquipeInterna();
            break;
        case 2:
            alterarEquipeInterna();
            break;
        case 3:
            listarEquipeInterna();
            break;
        case 4:
            excluirEquipeInterna();
            break;
        case 0:
            break;
        default:
            printf("\nOpcao invalida para Equipe!\n");
            break;
        }

        if (op_eq != 0)
        {
            pausar();
        }

    } while (op_eq != 0);
}

/* =========================================================
   Função: menuRecursos
   Objetivo: Permite ao usuário gerenciar os recursos e do
   equipamentos do sistema: adicionar, alterar, listar e excluir.
   ========================================================= */

void menuRecursos()
{
    int op_rec;
    do
    {
        system("cls");
        printf("\n--- Menu Recursos e Equipamentos ---\n");
        printf("1. Adicionar Novo Recurso\n");
        printf("2. Alterar Recurso Existente\n");
        printf("3. Listar Todos os Recursos\n");
        printf("4. Excluir Recurso\n");
        printf("0. Voltar ao Menu Anterior\n");
        printf("Escolha: ");
        scanf("%d", &op_rec);
        limpar_buffer();

        switch (op_rec)
        {
        case 1:
            adicionarRecurso();
            break;
        case 2:
            alterarRecurso();
            break;
        case 3:
            listarRecursos();
            break;
        case 4:
            excluirRecurso();
            break;
        case 0:
            break;
        default:
            printf("\nOpcao invalida para Recursos!\n");
            break;
        }

        if (op_rec != 0)
        {
            pausar();
        }

    } while (op_rec != 0);
}