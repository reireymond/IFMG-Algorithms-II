#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastros.h"

static Produtora dados_produtora;
static int produtora_cadastrada = 0;

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void alterarProdutora() {
    if (!produtora_cadastrada) {
        printf("\nNenhuma produtora cadastrada para alterar. Por favor, adicione uma primeiro.\n");
        return;
    }

    int opcao_alterar;
    do {
        system("cls");
        printf("--- Alterar Dados da Produtora ---\n");
        verDetalhesProdutora(); 

        printf("\nQual campo deseja alterar?\n");
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

        switch (opcao_alterar) {
            case 1:
            printf("Digite o novo Nome Fantasia: ");
            fgets(dados_produtora.nome_fantasia, sizeof(dados_produtora.nome_fantasia), stdin);
            dados_produtora.nome_fantasia[strcspn(dados_produtora.nome_fantasia, "\n")] = 0;
            break;
            case 2:
                printf("Digite a nova Razao Social: ");
                fgets(dados_produtora.razao_social, sizeof(dados_produtora.razao_social), stdin);
                dados_produtora.razao_social[strcspn(dados_produtora.razao_social, "\n")] = 0;
                break;
            case 3:
                printf("Digite o novo Nome do Responsavel: ");
                fgets(dados_produtora.nome_do_responsavel, sizeof(dados_produtora.nome_do_responsavel), stdin);
                dados_produtora.nome_do_responsavel[strcspn(dados_produtora.nome_do_responsavel, "\n")] = 0;
                break;
            case 4:
                printf("Digite o novo CNPJ: ");
                fgets(dados_produtora.cnpj, sizeof(dados_produtora.cnpj), stdin);
                if (strchr(dados_produtora.cnpj, '\n') == NULL) limpar_buffer();
                dados_produtora.cnpj[strcspn(dados_produtora.cnpj, "\n")] = 0;
                break;
            case 5:
                printf("Digite a nova Inscricao Estadual: ");
                fgets(dados_produtora.inscricao_estadual, sizeof(dados_produtora.inscricao_estadual), stdin);
                dados_produtora.inscricao_estadual[strcspn(dados_produtora.inscricao_estadual, "\n")] = 0;
                break;
            case 6:
                printf("Digite o novo Endereco: ");
                fgets(dados_produtora.endereco, sizeof(dados_produtora.endereco), stdin);
                dados_produtora.endereco[strcspn(dados_produtora.endereco, "\n")] = 0;
                break;
            case 7:
                printf("Digite o novo Telefone: ");
                fgets(dados_produtora.telefone, sizeof(dados_produtora.telefone), stdin);
                dados_produtora.telefone[strcspn(dados_produtora.telefone, "\n")] = 0;
                break;
            case 8:
                printf("Digite o novo Telefone do Responsavel: ");
                fgets(dados_produtora.telefone_responsavel, sizeof(dados_produtora.telefone_responsavel), stdin);
                dados_produtora.telefone_responsavel[strcspn(dados_produtora.telefone_responsavel, "\n")] = 0;
                break;
            case 9:
                printf("Digite o novo E-mail: ");
                fgets(dados_produtora.email, sizeof(dados_produtora.email), stdin);
                dados_produtora.email[strcspn(dados_produtora.email, "\n")] = 0;
                break;
            case 10:
                printf("Digite a nova Margem de Lucro (%%): ");
                scanf("%f", &dados_produtora.margem_lucro);
                limpar_buffer();
                break;
            case 0:
                printf("\nAlteracoes salvas com sucesso!\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
                int c; while ((c = getchar()) != '\n' && c != EOF);
                break;
        }

    } while (opcao_alterar != 0);
    salvarProdutora();
}

void salvarProdutora() {
    FILE *arquivo = fopen("../data/produtora.dat", "wb");
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo para salvar!\n");
        return;
    }

    fwrite(&dados_produtora, sizeof(Produtora), 1, arquivo);
    fclose(arquivo);
}

void carregarProdutora() {
    FILE *arquivo = fopen("../data/produtora.dat", "rb");
    if (arquivo == NULL) {
        produtora_cadastrada = 0;
        return;
    }

    if (fread(&dados_produtora, sizeof(Produtora), 1, arquivo) == 1) {
        produtora_cadastrada = 1;
    } else {
        produtora_cadastrada = 0;
    }
    
    fclose(arquivo);
}

void adicionarProdutora() {
    if (produtora_cadastrada) {
        printf("\nUma produtora ja foi cadastrada. Exclua a existente para cadastrar uma nova.\n");
        return;
    }

    printf("\n--- Cadastro dos Dados da Produtora ---\n");
    
    printf("Nome Fantasia: ");
    fgets(dados_produtora.nome_fantasia, sizeof(dados_produtora.nome_fantasia), stdin);
    dados_produtora.nome_fantasia[strcspn(dados_produtora.nome_fantasia, "\n")] = 0;

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

    salvarProdutora();
}

void verDetalhesProdutora() {
    if (!produtora_cadastrada) {
        printf("\nNenhuma produtora cadastrada para exibir.\n");
        return;
    }
    printf("\n--- Detalhes da Produtora Cadastrada ---\n");
    printf("Nome Fantasia: %s\n", dados_produtora.nome_fantasia);
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

void excluirProdutora() {
    if (!produtora_cadastrada) {
        printf("\nNenhuma produtora cadastrada para excluir.\n");
        return;
    }
    
    char confirmacao;
    printf("\nTem certeza que deseja excluir os dados da produtora %s? (s/n): ", dados_produtora.razao_social);
    scanf(" %c", &confirmacao);
    limpar_buffer();

    if (confirmacao == 's' || confirmacao == 'S') {
        strcpy(dados_produtora.razao_social, "");
        
        produtora_cadastrada = 0;
        
        salvarProdutora();
        
        printf("\nDados da produtora excluidos com sucesso!\n");
    } else {
        printf("\nExclusao cancelada.\n");
    }
}