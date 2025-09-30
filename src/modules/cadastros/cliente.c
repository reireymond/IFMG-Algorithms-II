#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastros/cliente.h"
#include "config.h"
#include "utils.h"
#include "structs.h"

#define CLIENTES_DATA_FILE "../data/clientes.dat"
#define CLIENTES_TEXT_FILE "../data/clientes.txt"


// Adiciona um novo cliente ao sistema.
void adicionarCliente(Sistema *sistema)
{ 
    if (sistema->num_clientes == sistema->capacidade_clientes)
    {
        int nova_capacidade = (sistema->capacidade_clientes == 0) ? 10 : sistema->capacidade_clientes * 2;
        Cliente *temp = realloc(sistema->lista_clientes, nova_capacidade * sizeof(Cliente));

        if (temp == NULL)
        {
            printf("\nErro de alocacao de memoria para clientes!\n");
            return;
        }
        sistema->lista_clientes = temp;
        sistema->capacidade_clientes = nova_capacidade;
    }

    Cliente novo_cliente;
    printf("\n--- Cadastro de Novo Cliente ---\n");

    novo_cliente.codigo = sistema->num_clientes + 1;
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

    sistema->lista_clientes[sistema->num_clientes] = novo_cliente;
    sistema->num_clientes++;

    printf("\nCliente '%s' cadastrado com sucesso!\n", novo_cliente.razao_social);
    salvarClientes(sistema);
}

// Exibe a lista de todos os clientes cadastrados.
void listarClientes(Sistema *sistema)
{
    if (sistema->num_clientes == 0)
    {
        printf("\nNenhum cliente cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Clientes ---\n");
    for (int i = 0; i < sistema->num_clientes; i++)
    {
        printf("----------------------------------\n");
        printf("Codigo: %d\n", sistema->lista_clientes[i].codigo);
        printf("Nome / Razao Social: %s\n", sistema->lista_clientes[i].razao_social);
        printf("CPF / CNPJ: %s\n", sistema->lista_clientes[i].cnpj);
        printf("Endereco: %s\n", sistema->lista_clientes[i].endereco);
        printf("Telefone: %s\n", sistema->lista_clientes[i].telefone);
        printf("E-mail: %s\n", sistema->lista_clientes[i].email);
        printf("Contato: %s\n", sistema->lista_clientes[i].nome_do_contato);
    }
    printf("----------------------------------\n");
}

// Permite a alteração dos dados de um cliente.
void alterarCliente(Sistema *sistema)
{
    listarClientes(sistema);
    if (sistema->num_clientes == 0)
        return;

    int codigo;
    int indice_cliente = -1;

    printf("\nDigite o codigo do cliente que deseja alterar: ");
    scanf("%d", &codigo);
    limpar_buffer();

    for (int i = 0; i < sistema->num_clientes; i++)
    {
        if (sistema->lista_clientes[i].codigo == codigo)
        {
            indice_cliente = i;
            break;
        }
    }

    if (indice_cliente == -1)
    {
        printf("\nCliente com codigo %d nao encontrado.\n", codigo);
        return;
    }

    int opcao_alterar;
    do
    {
        limpar_tela();
        printf("--- Alterando Cliente: %s ---\n", sistema->lista_clientes[indice_cliente].razao_social);
        printf("Codigo: %d\n\n", sistema->lista_clientes[indice_cliente].codigo);

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
            fgets(sistema->lista_clientes[indice_cliente].razao_social, sizeof(sistema->lista_clientes[indice_cliente].razao_social), stdin);
            sistema->lista_clientes[indice_cliente].razao_social[strcspn(sistema->lista_clientes[indice_cliente].razao_social, "\n")] = 0;
            break;
        case 2:
            printf("Digite o novo CPF / CNPJ: ");
            fgets(sistema->lista_clientes[indice_cliente].cnpj, sizeof(sistema->lista_clientes[indice_cliente].cnpj), stdin);
            sistema->lista_clientes[indice_cliente].cnpj[strcspn(sistema->lista_clientes[indice_cliente].cnpj, "\n")] = 0;
            break;
        case 3:
            printf("Digite o novo Endereco Completo: ");
            fgets(sistema->lista_clientes[indice_cliente].endereco, sizeof(sistema->lista_clientes[indice_cliente].endereco), stdin);
            sistema->lista_clientes[indice_cliente].endereco[strcspn(sistema->lista_clientes[indice_cliente].endereco, "\n")] = 0;
            break;
        case 4:
            printf("Digite o novo Telefone: ");
            fgets(sistema->lista_clientes[indice_cliente].telefone, sizeof(sistema->lista_clientes[indice_cliente].telefone), stdin);
            sistema->lista_clientes[indice_cliente].telefone[strcspn(sistema->lista_clientes[indice_cliente].telefone, "\n")] = 0;
            break;
        case 5:
            printf("Digite o novo E-mail: ");
            fgets(sistema->lista_clientes[indice_cliente].email, sizeof(sistema->lista_clientes[indice_cliente].email), stdin);
            sistema->lista_clientes[indice_cliente].email[strcspn(sistema->lista_clientes[indice_cliente].email, "\n")] = 0;
            break;
        case 6:
            printf("Digite o novo Nome do Contato: ");
            fgets(sistema->lista_clientes[indice_cliente].nome_do_contato, sizeof(sistema->lista_clientes[indice_cliente].nome_do_contato), stdin);
            sistema->lista_clientes[indice_cliente].nome_do_contato[strcspn(sistema->lista_clientes[indice_cliente].nome_do_contato, "\n")] = 0;
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

    salvarClientes(sistema);
}

// Remove um cliente do sistema.
void excluirCliente(Sistema *sistema)
{
    listarClientes(sistema);
    if (sistema->num_clientes == 0)
        return;

    int codigo, i;
    printf("\nDigite o codigo do cliente que deseja excluir: ");
    scanf("%d", &codigo);
    limpar_buffer();

    for (i = 0; i < sistema->num_clientes; i++)
    {
        if (sistema->lista_clientes[i].codigo == codigo)
        {
            char confirmacao;
            printf("Tem certeza que deseja excluir o cliente %s? (s/n): ", sistema->lista_clientes[i].razao_social);
            scanf(" %c", &confirmacao);
            limpar_buffer();

            if (confirmacao == 's' || confirmacao == 'S')
            {
                sistema->lista_clientes[i] = sistema->lista_clientes[sistema->num_clientes - 1];
                sistema->num_clientes--;
                printf("\nCliente excluido com sucesso!\n");
                salvarClientes(sistema);
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

// Salva os clientes em arquivo.
void salvarClientes(Sistema *sistema)
{
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA)
        return;

    FILE *arquivo = NULL;
    if (modo == ARQUIVO_BINARIO)
    {
        arquivo = fopen(CLIENTES_DATA_FILE, "wb");
        if (arquivo == NULL)
            return;
        fwrite(&sistema->num_clientes, sizeof(int), 1, arquivo);
        fwrite(sistema->lista_clientes, sizeof(Cliente), sistema->num_clientes, arquivo);
    }
    else if (modo == ARQUIVO_TEXTO)
    {
        arquivo = fopen(CLIENTES_TEXT_FILE, "w");
        if (arquivo == NULL)
            return;
        fprintf(arquivo, "%d\n", sistema->num_clientes);
        for (int i = 0; i < sistema->num_clientes; i++)
        {
            fprintf(arquivo, "%d\n", sistema->lista_clientes[i].codigo);
            fprintf(arquivo, "%s\n", sistema->lista_clientes[i].razao_social);
            fprintf(arquivo, "%s\n", sistema->lista_clientes[i].cnpj);
            fprintf(arquivo, "%s\n", sistema->lista_clientes[i].endereco);
            fprintf(arquivo, "%s\n", sistema->lista_clientes[i].telefone);
            fprintf(arquivo, "%s\n", sistema->lista_clientes[i].email);
            fprintf(arquivo, "%s\n", sistema->lista_clientes[i].nome_do_contato);
        }
    }
    if (arquivo != NULL)
        fclose(arquivo);
}

// Carrega os clientes do arquivo.
void carregarClientes(Sistema *sistema)
{
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA)
        return;

    FILE *arquivo = NULL;
    if (modo == ARQUIVO_BINARIO)
    {
        arquivo = fopen(CLIENTES_DATA_FILE, "rb");
        if (arquivo != NULL)
        {
            fread(&sistema->num_clientes, sizeof(int), 1, arquivo);
            if (sistema->num_clientes > 0)
            {
                sistema->lista_clientes = malloc(sistema->num_clientes * sizeof(Cliente));
                if (sistema->lista_clientes == NULL)
                {
                    printf("Erro ao alocar memoria para carregar clientes.\n");
                    sistema->num_clientes = 0;
                    return;
                }
                fread(sistema->lista_clientes, sizeof(Cliente), sistema->num_clientes, arquivo);
                sistema->capacidade_clientes = sistema->num_clientes;
            }
        }
    }
    else if (modo == ARQUIVO_TEXTO)
    {
        arquivo = fopen(CLIENTES_TEXT_FILE, "r");
        if (arquivo != NULL)
        {
            fscanf(arquivo, "%d\n", &sistema->num_clientes);
            if (sistema->num_clientes > 0)
            {
                sistema->lista_clientes = malloc(sistema->num_clientes * sizeof(Cliente));
                sistema->capacidade_clientes = sistema->num_clientes;
                for (int i = 0; i < sistema->num_clientes; i++)
                {
                    fscanf(arquivo, "%d\n", &sistema->lista_clientes[i].codigo);
                    fgets(sistema->lista_clientes[i].razao_social, sizeof(sistema->lista_clientes[i].razao_social), arquivo);
                    sistema->lista_clientes[i].razao_social[strcspn(sistema->lista_clientes[i].razao_social, "\n")] = 0;
                    fgets(sistema->lista_clientes[i].cnpj, sizeof(sistema->lista_clientes[i].cnpj), arquivo);
                    sistema->lista_clientes[i].cnpj[strcspn(sistema->lista_clientes[i].cnpj, "\n")] = 0;
                    fgets(sistema->lista_clientes[i].endereco, sizeof(sistema->lista_clientes[i].endereco), arquivo);
                    sistema->lista_clientes[i].endereco[strcspn(sistema->lista_clientes[i].endereco, "\n")] = 0;
                    fgets(sistema->lista_clientes[i].telefone, sizeof(sistema->lista_clientes[i].telefone), arquivo);
                    sistema->lista_clientes[i].telefone[strcspn(sistema->lista_clientes[i].telefone, "\n")] = 0;
                    fgets(sistema->lista_clientes[i].email, sizeof(sistema->lista_clientes[i].email), arquivo);
                    sistema->lista_clientes[i].email[strcspn(sistema->lista_clientes[i].email, "\n")] = 0;
                    fgets(sistema->lista_clientes[i].nome_do_contato, sizeof(sistema->lista_clientes[i].nome_do_contato), arquivo);
                    sistema->lista_clientes[i].nome_do_contato[strcspn(sistema->lista_clientes[i].nome_do_contato, "\n")] = 0;
                }
            }
        }
    }
    if (arquivo != NULL)
        fclose(arquivo);
}

// Libera a memória usada pela lista de clientes.
void liberarMemoriaClientes(Sistema *sistema)
{
    if (sistema->lista_clientes != NULL)
    {
        free(sistema->lista_clientes);
        sistema->lista_clientes = NULL;
    }
}