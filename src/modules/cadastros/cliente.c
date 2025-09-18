#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastros/cliente.h"
#include "config.h"
#include "utils.h"

// --- VARIÁVEIS GLOBAIS PARA CLIENTES ---
static Cliente *lista_clientes = NULL; // ponteiro para a lista de clientes
static int num_clientes = 0;           // contador de clientes cadastrados
static int capacidade_clientes = 0;    // capacidade atual do array alocado

// =========================================================
//           SEÇÃO: CLIENTES
// =========================================================

/* =========================================================
   Função: adicionarCliente
   Objetivo: Cadastra um novo cliente, alocando memória
   dinamicamente quando necessário.
   ========================================================= */
void adicionarCliente()
{
    if (num_clientes == capacidade_clientes)
    {
        int nova_capacidade = (capacidade_clientes == 0) ? 10 : capacidade_clientes * 2;
        Cliente *temp = realloc(lista_clientes, nova_capacidade * sizeof(Cliente));

        if (temp == NULL)
        {
            printf("\nErro critico de alocacao de memoria para clientes!\n");
            return;
        }
        lista_clientes = temp;
        capacidade_clientes = nova_capacidade;
    }

    Cliente novo_cliente;
    printf("\n--- Cadastro de Novo Cliente ---\n");

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

/* =========================================================
   Função: listarClientes
   Objetivo: Exibe todos os clientes cadastrados.
   ========================================================= */
void listarClientes()
{
    if (num_clientes == 0)
    {
        printf("\nNenhum cliente cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Clientes ---\n");
    for (int i = 0; i < num_clientes; i++)
    {
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

/* =========================================================
   Função: alterarCliente
   Objetivo: Permite editar os dados de um cliente
   existente, localizado pelo seu código.
   ========================================================= */
void alterarCliente()
{
    listarClientes();
    if (num_clientes == 0)
        return;

    int codigo;
    int indice_cliente = -1; // Usaremos o índice para evitar procurar o cliente repetidamente

    printf("\nDigite o codigo do cliente que deseja alterar: ");
    scanf("%d", &codigo);
    limpar_buffer();

    // Primeiro, encontra o índice do cliente na lista
    for (int i = 0; i < num_clientes; i++)
    {
        if (lista_clientes[i].codigo == codigo)
        {
            indice_cliente = i;
            break;
        }
    }

    // Se o cliente não foi encontrado, informa o usuário e sai da função
    if (indice_cliente == -1)
    {
        printf("\nCliente com codigo %d nao encontrado.\n", codigo);
        return;
    }

    int opcao_alterar;
    do
    {
        system("cls");
        printf("--- Alterando Cliente: %s ---\n", lista_clientes[indice_cliente].razao_social);
        printf("Codigo: %d\n\n", lista_clientes[indice_cliente].codigo);

        printf("Qual campo deseja alterar?\n");
        printf("1. Nome / Razao Social\n");
        printf("2. CPF / CNPJ\n");
        printf("3. Endereco Completo\n");
        printf("4. Telefone\n");
        printf("5. E-mail\n");
        printf("6. Nome do Contato\n");
        printf("0. Salvar e Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao_alterar);
        limpar_buffer();

        switch (opcao_alterar)
        {
        case 1:
            printf("Digite o novo Nome / Razao Social: ");
            fgets(lista_clientes[indice_cliente].razao_social, sizeof(lista_clientes[indice_cliente].razao_social), stdin);
            lista_clientes[indice_cliente].razao_social[strcspn(lista_clientes[indice_cliente].razao_social, "\n")] = 0;
            break;
        case 2:
            printf("Digite o novo CPF / CNPJ: ");
            fgets(lista_clientes[indice_cliente].cnpj, sizeof(lista_clientes[indice_cliente].cnpj), stdin);
            lista_clientes[indice_cliente].cnpj[strcspn(lista_clientes[indice_cliente].cnpj, "\n")] = 0;
            break;
        case 3:
            printf("Digite o novo Endereco Completo: ");
            fgets(lista_clientes[indice_cliente].endereco, sizeof(lista_clientes[indice_cliente].endereco), stdin);
            lista_clientes[indice_cliente].endereco[strcspn(lista_clientes[indice_cliente].endereco, "\n")] = 0;
            break;
        case 4:
            printf("Digite o novo Telefone: ");
            fgets(lista_clientes[indice_cliente].telefone, sizeof(lista_clientes[indice_cliente].telefone), stdin);
            lista_clientes[indice_cliente].telefone[strcspn(lista_clientes[indice_cliente].telefone, "\n")] = 0;
            break;
        case 5:
            printf("Digite o novo E-mail: ");
            fgets(lista_clientes[indice_cliente].email, sizeof(lista_clientes[indice_cliente].email), stdin);
            lista_clientes[indice_cliente].email[strcspn(lista_clientes[indice_cliente].email, "\n")] = 0;
            break;
        case 6:
            printf("Digite o novo Nome do Contato: ");
            fgets(lista_clientes[indice_cliente].nome_do_contato, sizeof(lista_clientes[indice_cliente].nome_do_contato), stdin);
            lista_clientes[indice_cliente].nome_do_contato[strcspn(lista_clientes[indice_cliente].nome_do_contato, "\n")] = 0;
            break;
        case 0:
            printf("\nAlteracoes salvas com sucesso!\n");
            break;
        default:
            printf("\nOpcao invalida!\n");
            // Adiciona uma pequena pausa para o usuário ler a mensagem de erro
            printf("Pressione Enter para tentar novamente...");
            getchar();
            break;
        }

    } while (opcao_alterar != 0);

    // Salva todas as alterações no arquivo de uma só vez, após sair do menu
    salvarClientes();
}

/* =========================================================
   Função: excluirCliente
   Objetivo: Remove um cliente da lista, realocando os
   elementos do array para não deixar "buracos".
   ========================================================= */
void excluirCliente()
{
    listarClientes();
    if (num_clientes == 0)
        return;

    int codigo, i;
    printf("\nDigite o codigo do cliente que deseja excluir: ");
    scanf("%d", &codigo);
    limpar_buffer();

    for (i = 0; i < num_clientes; i++)
    {
        if (lista_clientes[i].codigo == codigo)
        {
            char confirmacao;
            printf("Tem certeza que deseja excluir o cliente %s? (s/n): ", lista_clientes[i].razao_social);
            scanf(" %c", &confirmacao);
            limpar_buffer();

            if (confirmacao == 's' || confirmacao == 'S')
            {
                lista_clientes[i] = lista_clientes[num_clientes - 1]; // substitui pelo último
                num_clientes--;
                printf("\nCliente excluido com sucesso!\n");
                salvarClientes();
            }
            else
            {
                printf("\nExclusao cancelada.\n");
            }
            return;
        }
    }
    printf("\nCliente com codigo %d nao encontrado.\n", codigo);
}

/* =========================================================
   Função: salvarClientes
   Objetivo: Persiste os dados de clientes em disco de
   acordo com o modo de armazenamento escolhido.
   ========================================================= */
void salvarClientes()
{
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA)
        return;

    FILE *arquivo = NULL;
    if (modo == ARQUIVO_BINARIO)
    {
        arquivo = fopen("../data/clientes.dat", "wb");
        if (arquivo == NULL)
            return;
        fwrite(&num_clientes, sizeof(int), 1, arquivo);
        fwrite(lista_clientes, sizeof(Cliente), num_clientes, arquivo);
    }
    else if (modo == ARQUIVO_TEXTO)
    {
        arquivo = fopen("../data/clientes.txt", "w");
        if (arquivo == NULL)
            return;
        fprintf(arquivo, "%d\n", num_clientes);
        for (int i = 0; i < num_clientes; i++)
        {
            fprintf(arquivo, "%d\n", lista_clientes[i].codigo);
            fprintf(arquivo, "%s\n", lista_clientes[i].razao_social);
            fprintf(arquivo, "%s\n", lista_clientes[i].cnpj);
            fprintf(arquivo, "%s\n", lista_clientes[i].endereco);
            fprintf(arquivo, "%s\n", lista_clientes[i].telefone);
            fprintf(arquivo, "%s\n", lista_clientes[i].email);
            fprintf(arquivo, "%s\n", lista_clientes[i].nome_do_contato);
        }
    }
    if (arquivo != NULL)
        fclose(arquivo);
}

/* =========================================================
   Função: carregarClientes
   Objetivo: Lê os clientes de um arquivo (texto ou binário)
   e carrega na memória ao iniciar o sistema.
   ========================================================= */
void carregarClientes()
{
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA)
        return;

    FILE *arquivo = NULL;
    if (modo == ARQUIVO_BINARIO)
    {
        arquivo = fopen("../data/clientes.dat", "rb");
        if (arquivo != NULL)
        {
            fread(&num_clientes, sizeof(int), 1, arquivo);
            if (num_clientes > 0)
            {
                lista_clientes = malloc(num_clientes * sizeof(Cliente));
                if (lista_clientes == NULL)
                {
                    printf("Erro ao alocar memoria para carregar clientes.\n");
                    num_clientes = 0;
                    return;
                }
                fread(lista_clientes, sizeof(Cliente), num_clientes, arquivo);
                capacidade_clientes = num_clientes;
            }
        }
    }
    else if (modo == ARQUIVO_TEXTO)
    {
        arquivo = fopen("../data/clientes.txt", "r");
        if (arquivo != NULL)
        {
            fscanf(arquivo, "%d\n", &num_clientes);
            if (num_clientes > 0)
            {
                lista_clientes = malloc(num_clientes * sizeof(Cliente));
                capacidade_clientes = num_clientes;
                for (int i = 0; i < num_clientes; i++)
                {
                    fscanf(arquivo, "%d\n", &lista_clientes[i].codigo);
                    fgets(lista_clientes[i].razao_social, sizeof(lista_clientes[i].razao_social), arquivo);
                    lista_clientes[i].razao_social[strcspn(lista_clientes[i].razao_social, "\n")] = 0;
                    fgets(lista_clientes[i].cnpj, sizeof(lista_clientes[i].cnpj), arquivo);
                    lista_clientes[i].cnpj[strcspn(lista_clientes[i].cnpj, "\n")] = 0;
                    fgets(lista_clientes[i].endereco, sizeof(lista_clientes[i].endereco), arquivo);
                    lista_clientes[i].endereco[strcspn(lista_clientes[i].endereco, "\n")] = 0;
                    fgets(lista_clientes[i].telefone, sizeof(lista_clientes[i].telefone), arquivo);
                    lista_clientes[i].telefone[strcspn(lista_clientes[i].telefone, "\n")] = 0;
                    fgets(lista_clientes[i].email, sizeof(lista_clientes[i].email), arquivo);
                    lista_clientes[i].email[strcspn(lista_clientes[i].email, "\n")] = 0;
                    fgets(lista_clientes[i].nome_do_contato, sizeof(lista_clientes[i].nome_do_contato), arquivo);
                    lista_clientes[i].nome_do_contato[strcspn(lista_clientes[i].nome_do_contato, "\n")] = 0;
                }
            }
        }
    }
    if (arquivo != NULL)
        fclose(arquivo);
}

/* =========================================================
   Função: liberarMemoriaClientes
   Objetivo: Libera a memória alocada dinamicamente para
   a lista de clientes.
   ========================================================= */
void liberarMemoriaClientes()
{
    if (lista_clientes != NULL)
    {
        free(lista_clientes);
        lista_clientes = NULL;
    }
}