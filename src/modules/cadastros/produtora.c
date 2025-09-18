#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastros/produtora.h"
#include "config.h"
#include "utils.h"

// --- VARIÁVEL GLOBAL PARA PRODUTORA (AGORA UM PONTEIRO) ---
static Produtora *dados_produtora = NULL; // Alterado de static Produtora para um ponteiro

// =========================================================
//           SEÇÃO: PRODUTORA
// =========================================================

void alterarProdutora()
{
    if (dados_produtora == NULL) // Verifica se o ponteiro é nulo
    {
        printf("\nNenhuma produtora cadastrada para alterar. Por favor, adicione uma primeiro.\n");
        return;
    }

    int opcao_alterar;
    do
    {
        system("cls");
        printf("--- Alterar Dados da Produtora ---\n");
        verDetalhesProdutora();

        // O menu de alteração continua o mesmo...
        printf("\nQual campo deseja alterar?\n");
        printf("1. Nome Fantasia\n");
        // ... (outras opções)
        printf("0. Salvar e Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao_alterar);
        limpar_buffer();

        switch (opcao_alterar)
        {
        case 1:
            printf("Digite o novo Nome Fantasia: ");
            fgets(dados_produtora->nome_fantasia, sizeof(dados_produtora->nome_fantasia), stdin);
            dados_produtora->nome_fantasia[strcspn(dados_produtora->nome_fantasia, "\n")] = 0;
            break;
        // --- IMPORTANTE: Note o uso de '->' em vez de '.' para aceder aos campos ---
        case 2:
            printf("Digite a nova Razao Social: ");
            fgets(dados_produtora->razao_social, sizeof(dados_produtora->razao_social), stdin);
            dados_produtora->razao_social[strcspn(dados_produtora->razao_social, "\n")] = 0;
            break;
        // ... (repita o padrão '->' para todos os outros cases)
        case 10:
            printf("Digite a nova Margem de Lucro (%%): ");
            scanf("%f", &dados_produtora->margem_lucro);
            limpar_buffer();
            break;
        case 0:
            printf("\nAlteracoes salvas com sucesso!\n");
            break;
        default:
            printf("\nOpcao invalida!\n");
            pausar();
            break;
        }

    } while (opcao_alterar != 0);

    salvarProdutora();
}

void adicionarProdutora()
{
    if (dados_produtora != NULL)
    {
        printf("\nUma produtora ja foi cadastrada. Exclua a existente para cadastrar uma nova.\n");
        return;
    }

    // Aloca memória para a produtora
    dados_produtora = (Produtora *)malloc(sizeof(Produtora));
    if (dados_produtora == NULL) {
        printf("Erro fatal: Nao foi possivel alocar memoria para a produtora.\n");
        return;
    }

    printf("\n--- Cadastro dos Dados da Produtora ---\n");
    // Note o uso de '->' para aceder aos campos do ponteiro
    printf("Nome Fantasia: ");
    fgets(dados_produtora->nome_fantasia, sizeof(dados_produtora->nome_fantasia), stdin);
    dados_produtora->nome_fantasia[strcspn(dados_produtora->nome_fantasia, "\n")] = 0;

    // ... (faça o mesmo para todos os outros campos: razao_social, cnpj, etc.)

    printf("Margem de Lucro (%%): ");
    scanf("%f", &dados_produtora->margem_lucro);
    limpar_buffer();
    
    printf("\nDados da produtora '%s' cadastrados com sucesso!\n", dados_produtora->razao_social);
    salvarProdutora();
}

void verDetalhesProdutora()
{
    if (dados_produtora == NULL)
    {
        printf("\nNenhuma produtora cadastrada para exibir.\n");
        return;
    }
    printf("\n--- Detalhes da Produtora Cadastrada ---\n");
    printf("Nome Fantasia: %s\n", dados_produtora->nome_fantasia);
    // ... (use '->' para todos os outros campos)
    printf("Margem de Lucro: %.2f%%\n", dados_produtora->margem_lucro);
}

void excluirProdutora()
{
    if (dados_produtora == NULL)
    {
        printf("\nNenhuma produtora cadastrada para excluir.\n");
        return;
    }

    char confirmacao;
    printf("\nTem certeza que deseja excluir os dados da produtora %s? (s/n): ", dados_produtora->razao_social);
    scanf(" %c", &confirmacao);
    limpar_buffer();

    if (confirmacao == 's' || confirmacao == 'S')
    {
        free(dados_produtora); // Liberta a memória
        dados_produtora = NULL; // Aponta o ponteiro para NULL
        
        salvarProdutora(); // Salva o estado "vazio"

        printf("\nDados da produtora excluidos com sucesso!\n");
    }
    else
    {
        printf("\nExclusao cancelada.\n");
    }
}

void salvarProdutora()
{
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA) return;
    
    int produtora_existe = (dados_produtora != NULL);

    FILE *arquivo = fopen("../data/produtora.dat", "wb");
    if (arquivo == NULL) {
        perror("Nao foi possivel abrir o arquivo da produtora");
        return;
    }
    
    fwrite(&produtora_existe, sizeof(int), 1, arquivo);
    if (produtora_existe) {
        fwrite(dados_produtora, sizeof(Produtora), 1, arquivo);
    }
    
    fclose(arquivo);
}

void carregarProdutora()
{
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA) return;
    
    int produtora_existe = 0;
    FILE *arquivo = fopen("../data/produtora.dat", "rb");
    if (arquivo != NULL) {
        fread(&produtora_existe, sizeof(int), 1, arquivo);
        if (produtora_existe) {
            dados_produtora = (Produtora *)malloc(sizeof(Produtora));
            if (dados_produtora != NULL) {
                fread(dados_produtora, sizeof(Produtora), 1, arquivo);
            }
        }
        fclose(arquivo);
    }
}

void liberarMemoriaProdutora() {
    if (dados_produtora != NULL) {
        free(dados_produtora);
        dados_produtora = NULL;
    }
}