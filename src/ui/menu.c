#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "utils.h"
#include "ui/menu.h"
#include "structs.h"

// Includes dos módulos de cadastro
#include "cadastros/produtora.h"
#include "cadastros/cliente.h"
#include "cadastros/equipe.h"
#include "cadastros/recurso.h"
#include "cadastros/fornecedor.h"
#include "cadastros/operador.h"

// Protótipos das funções de menu internas a este arquivo
void menuGestaoDeDados(Sistema *sistema);
void menuProdutora(Sistema *sistema);
void menuClientes(Sistema *sistema);
void menuEquipeInterna(Sistema *sistema);
void menuRecursos(Sistema *sistema);
void menuFornecedores(Sistema *sistema);
void menuOperadores(Sistema *sistema);

// Exibe o menu para o usuário escolher o modo de armazenamento.
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


// Exibe o menu principal do sistema.
void menuPrincipal(Sistema *sistema)
{
    int menu_de_opcoes;
    do
    {
        limpar_tela();
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
            menuGestaoDeDados(sistema);
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


// Exibe o menu de gestão de dados.
void menuGestaoDeDados(Sistema *sistema)
{
    int opcao_gestao;
    do
    {
        limpar_tela();
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
        limpar_buffer();

        switch (opcao_gestao)
        {
        case 1:
            menuProdutora(sistema);
            break;
        case 2:
            menuClientes(sistema);
            break;
        case 3:
            menuEquipeInterna(sistema);
            break;
        case 4:
            menuRecursos(sistema);
            break;
        case 5:
            menuFornecedores(sistema);
            break;
        case 6:
            menuOperadores(sistema);
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

// Exibe o menu de gerenciamento da produtora.
void menuProdutora(Sistema *sistema)
{
    int op_prod;
    do
    {
        limpar_tela();
        printf("\n--- Menu Produtora ---\n");
        printf("1. Cadastrar Dados\n");
        printf("2. Alterar Dados\n");
        printf("3. Ver Detalhes\n");
        printf("4. Excluir Dados\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op_prod);
        limpar_buffer();

        switch (op_prod)
        {
        case 1: adicionarProdutora(sistema); break;
        case 2: alterarProdutora(sistema); break;
        case 3: verDetalhesProdutora(sistema); break;
        case 4: excluirProdutora(sistema); break;
        case 0: break;
        default: printf("\nOpcao invalida!\n"); break;
        }
        if (op_prod != 0) pausar();
    } while (op_prod != 0);
}

// Exibe o menu de gerenciamento de clientes.
void menuClientes(Sistema *sistema)
{
    int op_cli;
    do
    {
        limpar_tela();
        printf("\n--- Menu Clientes ---\n");
        printf("1. Adicionar Novo Cliente\n");
        printf("2. Alterar Cliente Existente\n");
        printf("3. Listar Todos os Clientes\n");
        printf("4. Excluir Cliente\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op_cli);
        limpar_buffer();

        switch (op_cli)
        {
        case 1: adicionarCliente(sistema); break;
        case 2: alterarCliente(sistema); break;
        case 3: listarClientes(sistema); break;
        case 4: excluirCliente(sistema); break;
        case 0: break;
        default: printf("\nOpcao invalida!\n"); break;
        }
        if (op_cli != 0) pausar();
    } while (op_cli != 0);
}

// Exibe o menu de gerenciamento da equipe interna.
void menuEquipeInterna(Sistema *sistema)
{
    int op_eq;
    do
    {
        limpar_tela();
        printf("\n--- Menu Equipe Interna ---\n");
        printf("1. Adicionar Novo Membro\n");
        printf("2. Alterar Membro Existente\n");
        printf("3. Listar Todos os Membros\n");
        printf("4. Excluir Membro\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op_eq);
        limpar_buffer();

        switch (op_eq)
        {
        case 1: adicionarEquipeInterna(sistema); break;
        case 2: alterarEquipeInterna(sistema); break;
        case 3: listarEquipeInterna(sistema); break;
        case 4: excluirEquipeInterna(sistema); break;
        case 0: break;
        default: printf("\nOpcao invalida!\n"); break;
        }
        if (op_eq != 0) pausar();
    } while (op_eq != 0);
}

// Exibe o menu de gerenciamento de recursos.
void menuRecursos(Sistema *sistema)
{
    int op_rec;
    do
    {
        limpar_tela();
        printf("\n--- Menu Recursos e Equipamentos ---\n");
        printf("1. Adicionar Novo Recurso\n");
        printf("2. Alterar Recurso Existente\n");
        printf("3. Listar Todos os Recursos\n");
        printf("4. Excluir Recurso\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op_rec);
        limpar_buffer();

        switch (op_rec)
        {
        case 1: adicionarRecurso(sistema); break;
        case 2: alterarRecurso(sistema); break;
        case 3: listarRecursos(sistema); break;
        case 4: excluirRecurso(sistema); break;
        case 0: break;
        default: printf("\nOpcao invalida!\n"); break;
        }
        if (op_rec != 0) pausar();
    } while (op_rec != 0);
}


// Exibe o menu de gerenciamento de fornecedores.
void menuFornecedores(Sistema *sistema)
{
    int op_forn;
    do
    {
        limpar_tela();
        printf("\n--- Menu Fornecedores e Parceiros ---\n");
        printf("1. Adicionar Novo Fornecedor\n");
        printf("2. Alterar Fornecedor Existente\n");
        printf("3. Listar Todos os Fornecedores\n");
        printf("4. Excluir Fornecedor\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op_forn);
        limpar_buffer();

        switch (op_forn)
        {
        case 1: adicionarFornecedor(sistema); break;
        case 2: alterarFornecedor(sistema); break;
        case 3: listarFornecedores(sistema); break;
        case 4: excluirFornecedor(sistema); break;
        case 0: break;
        default: printf("\nOpcao invalida!\n"); break;
        }
        if (op_forn != 0) pausar();
    } while (op_forn != 0);
}

// Exibe o menu de gerenciamento de operadores.
void menuOperadores(Sistema *sistema)
{
    int op_op;
    do
    {
        limpar_tela();
        printf("\n--- Menu Operadores ---\n");
        printf("1. Adicionar Novo Operador\n");
        printf("2. Alterar Operador Existente\n");
        printf("3. Listar Todos os Operadores\n");
        printf("4. Excluir Operador\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op_op);
        limpar_buffer();

        switch (op_op)
        {
        case 1: adicionarOperador(sistema); break;
        case 2: alterarOperador(sistema); break;
        case 3: listarOperadores(sistema); break;
        case 4: excluirOperador(sistema); break;
        case 0: break;
        default: printf("\nOpcao invalida!\n"); break;
        }
        if (op_op != 0) pausar();
    } while (op_op != 0);
}