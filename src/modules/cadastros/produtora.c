#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastros/produtora.h"
#include "config.h"
#include "utils.h"
#include "structs.h"

#define PRODUTORA_DATA_FILE "../data/produtora.dat"

// Cadastra os dados da produtora.
void adicionarProdutora(Sistema *sistema)
{
    // Verifica se o ponteiro para dados_produtora existe
    // Só tenta acessar os dados se o ponteiro não for NULL
    if (sistema->dados_produtora != NULL)
    {
        printf("\nUma produtora ja foi cadastrada. Exclua a existente para cadastrar uma nova.\n");
        return;
    }

    sistema->dados_produtora = (Produtora *)malloc(sizeof(Produtora));
    if (sistema->dados_produtora == NULL)
    {
        printf("Erro fatal: Nao foi possivel alocar memoria para a produtora.\n");
        return;
    }

    printf("\n--- Cadastro dos Dados da Produtora ---\n");

    printf("Nome Fantasia: ");
    fgets(sistema->dados_produtora->nome_fantasia, sizeof(sistema->dados_produtora->nome_fantasia), stdin);
    sistema->dados_produtora->nome_fantasia[strcspn(sistema->dados_produtora->nome_fantasia, "\n")] = 0;

    printf("Razao Social: ");
    fgets(sistema->dados_produtora->razao_social, sizeof(sistema->dados_produtora->razao_social), stdin);
    sistema->dados_produtora->razao_social[strcspn(sistema->dados_produtora->razao_social, "\n")] = 0;

    printf("Nome do Responsavel: ");
    fgets(sistema->dados_produtora->nome_do_responsavel, sizeof(sistema->dados_produtora->nome_do_responsavel), stdin);
    sistema->dados_produtora->nome_do_responsavel[strcspn(sistema->dados_produtora->nome_do_responsavel, "\n")] = 0;

    printf("CNPJ: ");
    fgets(sistema->dados_produtora->cnpj, sizeof(sistema->dados_produtora->cnpj), stdin);
    sistema->dados_produtora->cnpj[strcspn(sistema->dados_produtora->cnpj, "\n")] = 0;

    printf("Inscricao Estadual: ");
    fgets(sistema->dados_produtora->inscricao_estadual, sizeof(sistema->dados_produtora->inscricao_estadual), stdin);
    sistema->dados_produtora->inscricao_estadual[strcspn(sistema->dados_produtora->inscricao_estadual, "\n")] = 0;

    printf("Endereco: ");
    fgets(sistema->dados_produtora->endereco, sizeof(sistema->dados_produtora->endereco), stdin);
    sistema->dados_produtora->endereco[strcspn(sistema->dados_produtora->endereco, "\n")] = 0;

    printf("Telefone: ");
    fgets(sistema->dados_produtora->telefone, sizeof(sistema->dados_produtora->telefone), stdin);
    sistema->dados_produtora->telefone[strcspn(sistema->dados_produtora->telefone, "\n")] = 0;

    printf("Telefone do Responsavel: ");
    fgets(sistema->dados_produtora->telefone_responsavel, sizeof(sistema->dados_produtora->telefone_responsavel), stdin);
    sistema->dados_produtora->telefone_responsavel[strcspn(sistema->dados_produtora->telefone_responsavel, "\n")] = 0;

    printf("E-mail: ");
    fgets(sistema->dados_produtora->email, sizeof(sistema->dados_produtora->email), stdin);
    sistema->dados_produtora->email[strcspn(sistema->dados_produtora->email, "\n")] = 0;

    printf("Margem de Lucro (%%): ");
    scanf("%f", &sistema->dados_produtora->margem_lucro);
    limpar_buffer();

    printf("\nDados da produtora '%s' cadastrados com sucesso!\n", sistema->dados_produtora->nome_fantasia);
    salvarProdutora(sistema);
}

// Altera os dados da produtora existente.
void alterarProdutora(Sistema *sistema)
{
    if (sistema->dados_produtora == NULL)
    {
        printf("\nNenhuma produtora cadastrada para alterar. Por favor, adicione uma primeiro.\n");
        return;
    }

    int opcao_alterar;
    do
    {
        limpar_tela();
        printf("--- Alterar Dados da Produtora ---\n\n");
        verDetalhesProdutora(sistema);

        printf("\n\nQual campo deseja alterar?\n");
        printf("1. Nome Fantasia\n");
        printf("2. Razao Social\n");
        printf("3. Nome do Responsavel\n");
        printf("4. CNPJ\n");
        printf("5. Inscricao Estadual\n");
        printf("6. Endereco\n");
        printf("7. Telefone\n");
        printf("8. Telefone do Responsavel\n");
        printf("9. E-mail\n");
        printf("10. Margem de Lucro\n");
        printf("0. Salvar e Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao_alterar);
        limpar_buffer();

        switch (opcao_alterar)
        {
        case 1:
            printf("Digite o novo Nome Fantasia: ");
            fgets(sistema->dados_produtora->nome_fantasia, sizeof(sistema->dados_produtora->nome_fantasia), stdin);
            sistema->dados_produtora->nome_fantasia[strcspn(sistema->dados_produtora->nome_fantasia, "\n")] = 0;
            break;
        case 2:
            printf("Digite a nova Razao Social: ");
            fgets(sistema->dados_produtora->razao_social, sizeof(sistema->dados_produtora->razao_social), stdin);
            sistema->dados_produtora->razao_social[strcspn(sistema->dados_produtora->razao_social, "\n")] = 0;
            break;
        case 3:
            printf("Digite o novo Nome do Responsavel: ");
            fgets(sistema->dados_produtora->nome_do_responsavel, sizeof(sistema->dados_produtora->nome_do_responsavel), stdin);
            sistema->dados_produtora->nome_do_responsavel[strcspn(sistema->dados_produtora->nome_do_responsavel, "\n")] = 0;
            break;
        case 4:
            printf("Digite o novo CNPJ: ");
            fgets(sistema->dados_produtora->cnpj, sizeof(sistema->dados_produtora->cnpj), stdin);
            sistema->dados_produtora->cnpj[strcspn(sistema->dados_produtora->cnpj, "\n")] = 0;
            break;
        case 5:
            printf("Digite a nova Inscricao Estadual: ");
            fgets(sistema->dados_produtora->inscricao_estadual, sizeof(sistema->dados_produtora->inscricao_estadual), stdin);
            sistema->dados_produtora->inscricao_estadual[strcspn(sistema->dados_produtora->inscricao_estadual, "\n")] = 0;
            break;
        case 6:
            printf("Digite o novo Endereco: ");
            fgets(sistema->dados_produtora->endereco, sizeof(sistema->dados_produtora->endereco), stdin);
            sistema->dados_produtora->endereco[strcspn(sistema->dados_produtora->endereco, "\n")] = 0;
            break;
        case 7:
            printf("Digite o novo Telefone: ");
            fgets(sistema->dados_produtora->telefone, sizeof(sistema->dados_produtora->telefone), stdin);
            sistema->dados_produtora->telefone[strcspn(sistema->dados_produtora->telefone, "\n")] = 0;
            break;
        case 8:
            printf("Digite o novo Telefone do Responsavel: ");
            fgets(sistema->dados_produtora->telefone_responsavel, sizeof(sistema->dados_produtora->telefone_responsavel), stdin);
            sistema->dados_produtora->telefone_responsavel[strcspn(sistema->dados_produtora->telefone_responsavel, "\n")] = 0;
            break;
        case 9:
            printf("Digite o novo E-mail: ");
            fgets(sistema->dados_produtora->email, sizeof(sistema->dados_produtora->email), stdin);
            sistema->dados_produtora->email[strcspn(sistema->dados_produtora->email, "\n")] = 0;
            break;
        case 10:
            printf("Digite a nova Margem de Lucro (%%): ");
            scanf("%f", &sistema->dados_produtora->margem_lucro);
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

    salvarProdutora(sistema);
}

// Mostra os detalhes da produtora.
void verDetalhesProdutora(Sistema *sistema)
{
    if (sistema->dados_produtora == NULL)
    {
        printf("\nNenhuma produtora cadastrada para exibir.\n");
        return;
    }
    printf("\n--- Detalhes da Produtora Cadastrada ---\n");
    printf("Nome Fantasia: %s\n", sistema->dados_produtora->nome_fantasia);
    printf("Razao Social: %s\n", sistema->dados_produtora->razao_social);
    printf("Nome do Responsavel: %s\n", sistema->dados_produtora->nome_do_responsavel);
    printf("CNPJ: %s\n", sistema->dados_produtora->cnpj);
    printf("Inscricao Estadual: %s\n", sistema->dados_produtora->inscricao_estadual);
    printf("Endereco: %s\n", sistema->dados_produtora->endereco);
    printf("Telefone: %s\n", sistema->dados_produtora->telefone);
    printf("Telefone do Responsavel: %s\n", sistema->dados_produtora->telefone_responsavel);
    printf("E-mail: %s\n", sistema->dados_produtora->email);
    printf("Margem de Lucro: %.2f%%\n", sistema->dados_produtora->margem_lucro);
}

// Exclui os dados da produtora.
void excluirProdutora(Sistema *sistema)
{
    if (sistema->dados_produtora == NULL)
    {
        printf("\nNenhuma produtora cadastrada para excluir.\n");
        return;
    }

    char confirmacao;
    printf("\nTem certeza que deseja excluir os dados da produtora %s? (s/n): ", sistema->dados_produtora->razao_social);
    scanf(" %c", &confirmacao);
    limpar_buffer();

    if (confirmacao == 's' || confirmacao == 'S')
    {
        free(sistema->dados_produtora);
        sistema->dados_produtora = NULL;

        salvarProdutora(sistema);

        printf("\nDados da produtora excluidos com sucesso!\n");
    }
    else
    {
        printf("\nExclusao cancelada.\n");
    }
}

// Salva os dados da produtora em arquivo.
void salvarProdutora(Sistema *sistema)
{
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA)
        return;

    int produtora_existe = (sistema->dados_produtora != NULL);

    FILE *arquivo = fopen(PRODUTORA_DATA_FILE, "wb"); //abre o arquivo para escrita em modo binário
    if (arquivo == NULL)
    {
        perror("Nao foi possivel abrir o arquivo da produtora");
        return;
    }

    fwrite(&produtora_existe, sizeof(int), 1, arquivo);
    if (produtora_existe)
    {
        fwrite(sistema->dados_produtora, sizeof(Produtora), 1, arquivo);
    }

    fclose(arquivo);
}

// Carrega os dados da produtora do arquivo.
void carregarProdutora(Sistema *sistema)
{
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA)
        return;

    int produtora_existe = 0;
    FILE *arquivo = fopen(PRODUTORA_DATA_FILE, "rb"); // abre o arquivo para leitura em binário
    if (arquivo != NULL)
    {
        fread(&produtora_existe, sizeof(int), 1, arquivo);
        if (produtora_existe)
        {
            sistema->dados_produtora = (Produtora *)malloc(sizeof(Produtora));
            if (sistema->dados_produtora != NULL)
            {
                fread(sistema->dados_produtora, sizeof(Produtora), 1, arquivo);
            }
        }
        fclose(arquivo);
    }
}

// Libera a memória alocada para a produtora.
void liberarMemoriaProdutora(Sistema *sistema)
{
    if (sistema->dados_produtora != NULL)
    {
        free(sistema->dados_produtora);
        sistema->dados_produtora = NULL;
    }
}