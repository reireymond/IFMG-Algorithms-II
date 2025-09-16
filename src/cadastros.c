#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Necessário para a função strcspn

#include "cadastros.h"

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

static Produtora dados_produtora;
static int produtora_cadastrada = 0;

void adicionarProdutora()
{
    if (produtora_cadastrada)
    {
        printf("\nUma produtora ja foi cadastrada. Para cadastrar uma nova, exclua a existente.\n");
        return;
    }

    printf("\n--- Cadastro dos Dados da Produtora ---\n");

    printf("Razao Social: ");
    fgets(dados_produtora.razao_social, sizeof(dados_produtora.razao_social), stdin);
    dados_produtora.razao_social[strcspn(dados_produtora.razao_social, "\n")] = 0;

    printf("Nome do Responsavel: ");
    fgets(dados_produtora.nome_do_responsavel, sizeof(dados_produtora.nome_do_responsavel), stdin);
    dados_produtora.nome_do_responsavel[strcspn(dados_produtora.nome_do_responsavel, "\n")] = 0;

    printf("CNPJ (formato XX.XXX.XXX/XXXX-XX): ");
    fgets(dados_produtora.cnpj, sizeof(dados_produtora.cnpj), stdin);
    dados_produtora.cnpj[strcspn(dados_produtora.cnpj, "\n")] = 0;

    printf("Inscricao Estadual: ");
    fgets(dados_produtora.inscricao_estadual, sizeof(dados_produtora.inscricao_estadual), stdin);
    dados_produtora.inscricao_estadual[strcspn(dados_produtora.inscricao_estadual, "\n")] = 0;

    printf("Endereco Completo: ");
    fgets(dados_produtora.endereco, sizeof(dados_produtora.endereco), stdin);
    dados_produtora.endereco[strcspn(dados_produtora.endereco, "\n")] = 0;

    printf("Telefone (formato (XX) XXXXX-XXXX): ");
    fgets(dados_produtora.telefone, sizeof(dados_produtora.telefone), stdin);
    dados_produtora.telefone[strcspn(dados_produtora.telefone, "\n")] = 0;

    printf("Telefone do Responsavel (formato (XX) XXXXX-XXXX): ");
    fgets(dados_produtora.telefone_responsavel, sizeof(dados_produtora.telefone_responsavel), stdin);
    dados_produtora.telefone_responsavel[strcspn(dados_produtora.telefone_responsavel, "\n")] = 0;

    printf("E-mail: ");
    fgets(dados_produtora.email, sizeof(dados_produtora.email), stdin);
    dados_produtora.email[strcspn(dados_produtora.email, "\n")] = 0;

    printf("Margem de Lucro (%%): ");
    scanf("%f", &dados_produtora.margem_lucro);
    limpar_buffer();

    produtora_cadastrada = 1;
    printf("\nDados da produtora '%s' cadastrados com sucesso!\n", dados_produtora.razao_social);
}

void verDetalhesProdutora()
{
    if (!produtora_cadastrada)
    {
        printf("\nNenhuma produtora cadastrada para exibir.\n");
        return;
    }

    printf("\n--- Detalhes da Produtora Cadastrada ---\n");
    printf("Razao Social: %s\n", dados_produtora.razao_social);
    printf("Responsavel: %s\n", dados_produtora.nome_do_responsavel);
    printf("CNPJ: %s\n", dados_produtora.cnpj);
    printf("Inscricao Estadual: %s\n", dados_produtora.inscricao_estadual);
    printf("Endereco: %s\n", dados_produtora.endereco);
    printf("Telefone: %s\n", dados_produtora.telefone);
    printf("Telefone do Responsavel: %s\n", dados_produtora.telefone_responsavel);
    printf("E-mail: %s\n", dados_produtora.email);
    printf("Margem de Lucro: %.2f%%\n", dados_produtora.margem_lucro);
}

void alterarProdutora()
{
    printf("\nModulo de alteracao de produtora em construcao...\n");
}

void excluirProdutora()
{
    if (!produtora_cadastrada)
    {
        printf("\nNenhuma produtora cadastrada para excluir.\n");
        return;
    }

    char confirmacao;
    printf("\nTem certeza que deseja excluir os dados da produtora %s? (s/n): ", dados_produtora.razao_social);
    scanf(" %c", &confirmacao);
    limpar_buffer();

    if (confirmacao == 's' || confirmacao == 'S')
    {
        strcpy(dados_produtora.razao_social, "");

        produtora_cadastrada = 0;
        printf("\nDados da produtora excluidos com sucesso!\n");
    }
    else
    {
        printf("\nExclusao cancelada.\n");
    }
}