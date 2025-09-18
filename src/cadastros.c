#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastros.h"
#include "config.h"

// --- VARIÁVEIS GLOBAIS PARA ARMAZENAMENTO ---

// Produtora (registro único)
static Produtora dados_produtora;
static int produtora_cadastrada = 0;

// Clientes (múltiplos registros)
#define MAX_CLIENTES 100
static Cliente lista_clientes[MAX_CLIENTES];
static int num_clientes = 0;


// --- FUNÇÕES AUXILIARES ---

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// --- SETOR PRODUTORA (implementação anterior) ---

void alterarProdutora()
{
    if (!produtora_cadastrada)
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

        switch (opcao_alterar)
        {
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
            if (strchr(dados_produtora.cnpj, '\n') == NULL)
                limpar_buffer();
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
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            break;
        }

    } while (opcao_alterar != 0);
    salvarProdutora();
}

void adicionarProdutora()
{
    if (produtora_cadastrada)
    {
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

void verDetalhesProdutora()
{
    if (!produtora_cadastrada)
    {
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
        // Limpa a estrutura em memória
        strcpy(dados_produtora.nome_fantasia, "");
        strcpy(dados_produtora.razao_social, "");
        strcpy(dados_produtora.nome_do_responsavel, "");
        strcpy(dados_produtora.cnpj, "");
        strcpy(dados_produtora.inscricao_estadual, "");
        strcpy(dados_produtora.endereco, "");
        strcpy(dados_produtora.telefone, "");
        strcpy(dados_produtora.telefone_responsavel, "");
        strcpy(dados_produtora.email, "");
        dados_produtora.margem_lucro = 0;


        produtora_cadastrada = 0;

        // Salva a estrutura "vazia" para limpar o arquivo
        salvarProdutora();

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

    if (modo == MEMORIA)
    {
        //printf("\nModo 'Memoria': Dados da produtora nao serao salvos em arquivo.\n");
        return;
    }

    FILE *arquivo = NULL;

    if (modo == ARQUIVO_BINARIO)
    {
        arquivo = fopen("../data/produtora.dat", "wb");
        if (arquivo == NULL)
        {
            perror("Nao foi possivel abrir o arquivo para escrita");
            return;
        }
        // Salva a flag e a struct
        fwrite(&produtora_cadastrada, sizeof(int), 1, arquivo);
        fwrite(&dados_produtora, sizeof(Produtora), 1, arquivo);
    }
    else if (modo == ARQUIVO_TEXTO)
    {
        arquivo = fopen("../data/produtora.txt", "w");
        if (arquivo == NULL)
        {
            perror("Nao foi possivel abrir o arquivo para escrita");
            return;
        }
        // Se não houver produtora, salva um arquivo vazio
        if (produtora_cadastrada) {
            fprintf(arquivo, "%s\n", dados_produtora.nome_fantasia);
            fprintf(arquivo, "%s\n", dados_produtora.razao_social);
            fprintf(arquivo, "%s\n", dados_produtora.nome_do_responsavel);
            fprintf(arquivo, "%s\n", dados_produtora.cnpj);
            fprintf(arquivo, "%s\n", dados_produtora.inscricao_estadual);
            fprintf(arquivo, "%s\n", dados_produtora.endereco);
            fprintf(arquivo, "%s\n", dados_produtora.telefone);
            fprintf(arquivo, "%s\n", dados_produtora.telefone_responsavel);
            fprintf(arquivo, "%s\n", dados_produtora.email);
            fprintf(arquivo, "%.2f\n", dados_produtora.margem_lucro);
        }
    }

    if (arquivo != NULL)
    {
        fclose(arquivo);
    }
}

void carregarProdutora()
{
    TipoArmazenamento modo = obterModoDeArmazenamento();

    if (modo == MEMORIA)
    {
        produtora_cadastrada = 0;
        return;
    }

    FILE *arquivo = NULL;

    if (modo == ARQUIVO_BINARIO)
    {
        arquivo = fopen("../data/produtora.dat", "rb");
        if (arquivo != NULL)
        {
            // Lê primeiro a flag
            fread(&produtora_cadastrada, sizeof(int), 1, arquivo);
            // Se a flag for verdadeira, lê a struct
            if (produtora_cadastrada) {
                fread(&dados_produtora, sizeof(Produtora), 1, arquivo);
            }
        }
    }
    else if (modo == ARQUIVO_TEXTO)
    {
        arquivo = fopen("../data/produtora.txt", "r");
        if (arquivo != NULL)
        {
            // Tenta ler o primeiro campo. Se falhar (EOF), o arquivo está vazio.
            if (fgets(dados_produtora.nome_fantasia, sizeof(dados_produtora.nome_fantasia), arquivo) != NULL)
            {
                // Remove a quebra de linha
                dados_produtora.nome_fantasia[strcspn(dados_produtora.nome_fantasia, "\n")] = 0;

                fgets(dados_produtora.razao_social, sizeof(dados_produtora.razao_social), arquivo);
                dados_produtora.razao_social[strcspn(dados_produtora.razao_social, "\n")] = 0;

                fgets(dados_produtora.nome_do_responsavel, sizeof(dados_produtora.nome_do_responsavel), arquivo);
                dados_produtora.nome_do_responsavel[strcspn(dados_produtora.nome_do_responsavel, "\n")] = 0;

                fgets(dados_produtora.cnpj, sizeof(dados_produtora.cnpj), arquivo);
                dados_produtora.cnpj[strcspn(dados_produtora.cnpj, "\n")] = 0;

                fgets(dados_produtora.inscricao_estadual, sizeof(dados_produtora.inscricao_estadual), arquivo);
                dados_produtora.inscricao_estadual[strcspn(dados_produtora.inscricao_estadual, "\n")] = 0;

                fgets(dados_produtora.endereco, sizeof(dados_produtora.endereco), arquivo);
                dados_produtora.endereco[strcspn(dados_produtora.endereco, "\n")] = 0;

                fgets(dados_produtora.telefone, sizeof(dados_produtora.telefone), arquivo);
                dados_produtora.telefone[strcspn(dados_produtora.telefone, "\n")] = 0;

                fgets(dados_produtora.telefone_responsavel, sizeof(dados_produtora.telefone_responsavel), arquivo);
                dados_produtora.telefone_responsavel[strcspn(dados_produtora.telefone_responsavel, "\n")] = 0;

                fgets(dados_produtora.email, sizeof(dados_produtora.email), arquivo);
                dados_produtora.email[strcspn(dados_produtora.email, "\n")] = 0;

                fscanf(arquivo, "%f", &dados_produtora.margem_lucro);

                produtora_cadastrada = 1; // Marca que os dados foram carregados
            } else {
                produtora_cadastrada = 0; // Arquivo vazio
            }
        }
    }

    if (arquivo != NULL)
    {
        fclose(arquivo);
    }
}


// --- SETOR CLIENTE ---

void adicionarCliente() {
    if (num_clientes >= MAX_CLIENTES) {
        printf("\nLimite de clientes atingido!\n");
        return;
    }

    Cliente novo_cliente;
    printf("\n--- Cadastro de Novo Cliente ---\n");

    // Lógica para gerar código único (pode ser melhorada)
    novo_cliente.codigo = num_clientes + 1;
    printf("Codigo do Cliente: %d\n", novo_cliente.codigo);

    printf("Nome / Razao Social: ");
    fgets(novo_cliente.razao_social, sizeof(novo_cliente.razao_social), stdin);
    novo_cliente.razao_social[strcspn(novo_cliente.razao_social, "\n")] = 0;

    printf("CPF / CNPJ: ");
    fgets(novo_cliente.cnpj, sizeof(novo_cliente.cnpj), stdin);
    novo_cliente.cnpj[strcspn(novo_cliente.cnpj, "\n")] = 0;

    printf("Endereco Completo: ");
    fgets(novo_cliente.endereco, sizeof(novo_cliente.endereco), stdin);
    novo_cliente.endereco[strcspn(novo_cliente.endereco, "\n")] = 0;

    printf("Telefone: ");
    fgets(novo_cliente.telefone, sizeof(novo_cliente.telefone), stdin);
    novo_cliente.telefone[strcspn(novo_cliente.telefone, "\n")] = 0;

    printf("E-mail: ");
    fgets(novo_cliente.email, sizeof(novo_cliente.email), stdin);
    novo_cliente.email[strcspn(novo_cliente.email, "\n")] = 0;

    printf("Nome do Contato: ");
    fgets(novo_cliente.nome_do_contato, sizeof(novo_cliente.nome_do_contato), stdin);
    novo_cliente.nome_do_contato[strcspn(novo_cliente.nome_do_contato, "\n")] = 0;

    lista_clientes[num_clientes] = novo_cliente;
    num_clientes++;

    printf("\nCliente '%s' cadastrado com sucesso!\n", novo_cliente.razao_social);
    salvarClientes();
}

void listarClientes() {
    if (num_clientes == 0) {
        printf("\nNenhum cliente cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Clientes ---\n");
    for (int i = 0; i < num_clientes; i++) {
        printf("----------------------------------\n");
        printf("Codigo: %d\n", lista_clientes[i].codigo);
        printf("Nome / Razao Social: %s\n", lista_clientes[i].razao_social);
        printf("CPF / CNPJ: %s\n", lista_clientes[i].cnpj);
        printf("Endereco: %s\n", lista_clientes[i].endereco);
        printf("Telefone: %s\n", lista_clientes[i].telefone);
        printf("E-mail: %s\n", lista_clientes[i].email);
        printf("Contato: %s\n", lista_clientes[i].nome_do_contato);
    }
    printf("----------------------------------\n");
}

void alterarCliente() {
    listarClientes();
    if (num_clientes == 0) return;

    int codigo, i;
    printf("\nDigite o codigo do cliente que deseja alterar: ");
    scanf("%d", &codigo);
    limpar_buffer();

    for (i = 0; i < num_clientes; i++) {
        if (lista_clientes[i].codigo == codigo) {
             printf("\n--- Alterando Cliente: %s ---\n", lista_clientes[i].razao_social);
             printf("Novo Nome / Razao Social: ");
             fgets(lista_clientes[i].razao_social, sizeof(lista_clientes[i].razao_social), stdin);
             lista_clientes[i].razao_social[strcspn(lista_clientes[i].razao_social, "\n")] = 0;

             // ... (adicionar a lógica para alterar os outros campos) ...

             printf("\nCliente alterado com sucesso!\n");
             salvarClientes();
             return;
        }
    }
    printf("\nCliente com codigo %d nao encontrado.\n", codigo);
}

void excluirCliente() {
    listarClientes();
    if (num_clientes == 0) return;

    int codigo, i;
    printf("\nDigite o codigo do cliente que deseja excluir: ");
    scanf("%d", &codigo);
    limpar_buffer();

    for (i = 0; i < num_clientes; i++) {
        if (lista_clientes[i].codigo == codigo) {
            char confirmacao;
            printf("Tem certeza que deseja excluir o cliente %s? (s/n): ", lista_clientes[i].razao_social);
            scanf(" %c", &confirmacao);
            limpar_buffer();

            if (confirmacao == 's' || confirmacao == 'S') {
                // Move o último cliente para a posição do cliente a ser excluído
                lista_clientes[i] = lista_clientes[num_clientes - 1];
                num_clientes--; // Diminui o contador de clientes
                printf("\nCliente excluido com sucesso!\n");
                salvarClientes();
            } else {
                printf("\nExclusao cancelada.\n");
            }
            return;
        }
    }
    printf("\nCliente com codigo %d nao encontrado.\n", codigo);
}


void salvarClientes() {
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA) return;

    FILE *arquivo = NULL;
    if (modo == ARQUIVO_BINARIO) {
        arquivo = fopen("../data/clientes.dat", "wb");
        if (arquivo == NULL) return;
        // Salva o número de clientes e depois o array
        fwrite(&num_clientes, sizeof(int), 1, arquivo);
        fwrite(lista_clientes, sizeof(Cliente), num_clientes, arquivo);
    } else if (modo == ARQUIVO_TEXTO) {
        arquivo = fopen("../data/clientes.txt", "w");
        if (arquivo == NULL) return;
        // Salva cada cliente campo a campo
        fprintf(arquivo, "%d\n", num_clientes);
        for (int i = 0; i < num_clientes; i++) {
            fprintf(arquivo, "%d\n", lista_clientes[i].codigo);
            fprintf(arquivo, "%s\n", lista_clientes[i].razao_social);
            fprintf(arquivo, "%s\n", lista_clientes[i].cnpj);
            fprintf(arquivo, "%s\n", lista_clientes[i].endereco);
            fprintf(arquivo, "%s\n", lista_clientes[i].telefone);
            fprintf(arquivo, "%s\n", lista_clientes[i].email);
            fprintf(arquivo, "%s\n", lista_clientes[i].nome_do_contato);
        }
    }
    if (arquivo != NULL) fclose(arquivo);
}

void carregarClientes() {
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA) return;

    FILE *arquivo = NULL;
    if (modo == ARQUIVO_BINARIO) {
        arquivo = fopen("../data/clientes.dat", "rb");
        if (arquivo != NULL) {
            // Lê o número de clientes e depois o array
            fread(&num_clientes, sizeof(int), 1, arquivo);
            fread(lista_clientes, sizeof(Cliente), num_clientes, arquivo);
        }
    } else if (modo == ARQUIVO_TEXTO) {
        arquivo = fopen("../data/clientes.txt", "r");
        if (arquivo != NULL) {
            fscanf(arquivo, "%d\n", &num_clientes);
            for (int i = 0; i < num_clientes; i++) {
                fscanf(arquivo, "%d\n", &lista_clientes[i].codigo);
                fgets(lista_clientes[i].razao_social, sizeof(lista_clientes[i].razao_social), arquivo);
                lista_clientes[i].razao_social[strcspn(lista_clientes[i].razao_social, "\n")] = 0;
                fgets(lista_clientes[i].cnpj, sizeof(lista_clientes[i].cnpj), arquivo);
                 lista_clientes[i].cnpj[strcspn( lista_clientes[i].cnpj, "\n")] = 0;
                fgets(lista_clientes[i].endereco, sizeof(lista_clientes[i].endereco), arquivo);
                 lista_clientes[i].endereco[strcspn( lista_clientes[i].endereco, "\n")] = 0;
                fgets(lista_clientes[i].telefone, sizeof(lista_clientes[i].telefone), arquivo);
                 lista_clientes[i].telefone[strcspn( lista_clientes[i].telefone, "\n")] = 0;
                fgets(lista_clientes[i].email, sizeof(lista_clientes[i].email), arquivo);
                 lista_clientes[i].email[strcspn( lista_clientes[i].email, "\n")] = 0;
                fgets(lista_clientes[i].nome_do_contato, sizeof(lista_clientes[i].nome_do_contato), arquivo);
                 lista_clientes[i].nome_do_contato[strcspn( lista_clientes[i].nome_do_contato, "\n")] = 0;
            }
        }
    }
    if (arquivo != NULL) fclose(arquivo);
}