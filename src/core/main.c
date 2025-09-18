#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "menu.h"
#include "utils.h"

#include "cadastros/produtora.h"
#include "cadastros/cliente.h"
// #include "cadastros/equipe.h"
// #include "cadastros/recurso.h"
// #include "cadastros/fornecedor.h"
#include "cadastros/operador.h"


/* =========================================================
   Arquivo: main.c
   Objetivo: Ponto de entrada do sistema. Responsável por
   inicializar os dados, controlar o loop principal do
   programa e liberar os recursos ao finalizar.
   ========================================================= */

// --- DECLARAÇÕES DE FUNÇÕES EXTERNAS ---
// Funções implementadas em outros arquivos que são chamadas aqui.
void menuGestaoDeDados();

// --- FUNÇÕES UTILITÁRIAS ---

/* =========================================================
   Função: pausar
   Objetivo: Serve para segurar a tela até que o usuário
   pressione Enter.
   ========================================================= */
void pausar()
{
    printf("\nPressione Enter para continuar...");
    // Limpa o buffer de entrada para aguardar o Enter
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    getchar();
}

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
   Função: main
   Objetivo: Função principal do programa.
   ========================================================= */
int main()
{
    menuEscolherArmazenamento();

    // Carrega todos os dados dos arquivos
    carregarProdutora();
    carregarClientes();
    // carregarEquipeInterna();
    // carregarRecursos();
    // carregarFornecedores();
    carregarOperadores();

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

    // Libera toda a memória alocada antes de sair
    liberarMemoriaProdutora();
    liberarMemoriaClientes();
    // liberarMemoriaEquipe();
    // liberarMemoriaRecursos();
    // liberarMemoriaFornecedores();
    liberarMemoriaOperadores();

    return 0;
}