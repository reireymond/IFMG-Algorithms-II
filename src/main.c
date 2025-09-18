#include <stdio.h>
#include <stdlib.h>
#include "cadastros.h"
#include "config.h"

/* =========================================================
   Arquivo: main.c
   Objetivo: Este é o ponto de entrada do sistema de gestão
   da Produtora de Eventos. Ele contém o menu principal e
   os submenus de cada módulo (Gestão de Dados, Eventos,
   Transações, etc.), chamando as funções apropriadas que
   estão implementadas em outros arquivos.

   Aqui também é feita a configuração inicial do modo de
   armazenamento (binário, texto ou apenas memória).
   ========================================================= */

// Declarações de funções de menu usadas neste arquivo
void menuGestaoDeDados();
void menuProdutora();
void menuClientes(); // Menu específico de Clientes

// Função utilitária para pausar a execução
void pausar();

/* =========================================================
   Função: menuEscolherArmazenamento
   Objetivo: Permite ao usuário escolher como os dados serão
   salvos no sistema (arquivo binário, texto ou só em memória).
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

    // Define o modo de acordo com a escolha do usuário
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
        break;
    }
    pausar(); // Aguarda antes de prosseguir
}

/* =========================================================
   Função: pausar
   Objetivo: Serve para segurar a tela até que o usuário
   pressione Enter, evitando que o programa volte ao menu
   imediatamente.
   ========================================================= */
void pausar()
{
    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n' && getchar() != EOF)
        ;
    getchar(); // Captura o Enter
}

/* =========================================================
   Função: main
   Objetivo: Função principal do programa. É aqui que tudo
   começa. Carrega os dados do sistema, mostra o menu
   principal e controla o fluxo entre os módulos.
   ========================================================= */
int main()
{

    // Primeiro, pergunta como o usuário quer salvar os dados
    menuEscolherArmazenamento();

    // Carrega dados já existentes (se houver)
    carregarProdutora();
    carregarClientes();

    int menu_de_opcoes;
    do
    {
        system("cls"); // Limpa a tela (funciona no Windows)
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Gestao de Dados\n");
        printf("2. Gestao de Eventos\n");
        printf("3. Transacoes\n");
        printf("4. FeedBack\n");
        printf("5. Importar ou Exportar Dados\n");
        printf("0. Sair\n");
        printf("\nEscolha sua opcao de modulo desejada: ");
        scanf("%d", &menu_de_opcoes);

        // Redireciona para o módulo escolhido
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

    } while (menu_de_opcoes != 0); // Repete até o usuário sair
    return 0;
}

/* =========================================================
   Função: menuGestaoDeDados
   Objetivo: Apresenta as opções de gerenciamento de dados
   da produtora: clientes, equipe, recursos, fornecedores
   e operadores. Algumas partes ainda estão em construção.
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

        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ; // Limpa buffer

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
        limpar_buffer(); // Limpa buffer para evitar erros

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
