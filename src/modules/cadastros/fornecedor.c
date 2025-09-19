#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastros/fornecedor.h"
#include "config.h"
#include "utils.h"

// Ponteiro para a lista de fornecedores.
static Fornecedor *lista_fornecedores = NULL;
// Número de fornecedores cadastrados.
static int num_fornecedores = 0;
// Capacidade atual do array de fornecedores.
static int capacidade_fornecedores = 0;

/*
  Adiciona um novo fornecedor.
 */
void adicionarFornecedor()
{
    if (num_fornecedores == capacidade_fornecedores)
    {
        int nova_capacidade = (capacidade_fornecedores == 0) ? 10 : capacidade_fornecedores * 2;
        Fornecedor *temp = realloc(lista_fornecedores, nova_capacidade * sizeof(Fornecedor));

        if (temp == NULL)
        {
            printf("\nErro critico de alocacao de memoria para fornecedores!\n");
            return;
        }
        lista_fornecedores = temp;
        capacidade_fornecedores = nova_capacidade;
    }

    Fornecedor novo_fornecedor;
    printf("\n--- Cadastro de Novo Fornecedor/Parceiro ---\n");

    novo_fornecedor.codigo = num_fornecedores + 1;
    printf("Codigo do Fornecedor: %d\n", novo_fornecedor.codigo);

    printf("Nome Fantasia: ");
    fgets(novo_fornecedor.nome_fantasia, sizeof(novo_fornecedor.nome_fantasia), stdin);
    novo_fornecedor.nome_fantasia[strcspn(novo_fornecedor.nome_fantasia, "\n")] = 0;

    printf("Razao Social: ");
    fgets(novo_fornecedor.razao_social, sizeof(novo_fornecedor.razao_social), stdin);
    novo_fornecedor.razao_social[strcspn(novo_fornecedor.razao_social, "\n")] = 0;

    printf("CNPJ / CPF: ");
    fgets(novo_fornecedor.cnpj, sizeof(novo_fornecedor.cnpj), stdin);
    novo_fornecedor.cnpj[strcspn(novo_fornecedor.cnpj, "\n")] = 0;

    printf("Endereco Completo: ");
    fgets(novo_fornecedor.endereco, sizeof(novo_fornecedor.endereco), stdin);
    novo_fornecedor.endereco[strcspn(novo_fornecedor.endereco, "\n")] = 0;

    printf("Telefone: ");
    fgets(novo_fornecedor.telefone, sizeof(novo_fornecedor.telefone), stdin);
    novo_fornecedor.telefone[strcspn(novo_fornecedor.telefone, "\n")] = 0;

    printf("Tipo de Servico (Ex: Buffet, Seguranca): ");
    fgets(novo_fornecedor.tipo_servico, sizeof(novo_fornecedor.tipo_servico), stdin);
    novo_fornecedor.tipo_servico[strcspn(novo_fornecedor.tipo_servico, "\n")] = 0;


    lista_fornecedores[num_fornecedores] = novo_fornecedor;
    num_fornecedores++;

    printf("\nFornecedor '%s' cadastrado com sucesso!\n", novo_fornecedor.nome_fantasia);
    salvarFornecedores();
}

/*
  Lista todos os fornecedores.
 */
void listarFornecedores()
{
    if (num_fornecedores == 0)
    {
        printf("\nNenhum fornecedor cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Fornecedores e Parceiros ---\n");
    for (int i = 0; i < num_fornecedores; i++)
    {
        printf("----------------------------------\n");
        printf("Codigo: %d\n", lista_fornecedores[i].codigo);
        printf("Nome Fantasia: %s\n", lista_fornecedores[i].nome_fantasia);
        printf("Razao Social: %s\n", lista_fornecedores[i].razao_social);
        printf("CNPJ / CPF: %s\n", lista_fornecedores[i].cnpj);
        printf("Endereco: %s\n", lista_fornecedores[i].endereco);
        printf("Telefone: %s\n", lista_fornecedores[i].telefone);
        printf("Tipo de Servico: %s\n", lista_fornecedores[i].tipo_servico);
    }
    printf("----------------------------------\n");
}

/*
  Altera os dados de um fornecedor.
 */
void alterarFornecedor()
{
    listarFornecedores();
    if (num_fornecedores == 0)
        return;

    int codigo;
    int indice = -1;

    printf("\nDigite o codigo do fornecedor que deseja alterar: ");
    scanf("%d", &codigo);
    limpar_buffer();

    for (int i = 0; i < num_fornecedores; i++)
    {
        if (lista_fornecedores[i].codigo == codigo)
        {
            indice = i;
            break;
        }
    }

    if (indice == -1)
    {
        printf("\nFornecedor com codigo %d nao encontrado.\n", codigo);
        return;
    }

    int opcao;
    do
    {
        limpar_tela();
        printf("--- Alterando Fornecedor: %s ---\n", lista_fornecedores[indice].nome_fantasia);
        printf("1. Alterar Nome Fantasia\n");
        printf("2. Alterar Razao Social\n");
        printf("3. Alterar CNPJ / CPF\n");
        printf("4. Alterar Endereco\n");
        printf("5. Alterar Telefone\n");
        printf("6. Alterar Tipo de Servico\n");
        printf("0. Salvar e Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao)
        {
        case 1:
            printf("Novo Nome Fantasia: ");
            fgets(lista_fornecedores[indice].nome_fantasia, sizeof(lista_fornecedores[indice].nome_fantasia), stdin);
            lista_fornecedores[indice].nome_fantasia[strcspn(lista_fornecedores[indice].nome_fantasia, "\n")] = 0;
            break;
        case 2:
            printf("Nova Razao Social: ");
            fgets(lista_fornecedores[indice].razao_social, sizeof(lista_fornecedores[indice].razao_social), stdin);
            lista_fornecedores[indice].razao_social[strcspn(lista_fornecedores[indice].razao_social, "\n")] = 0;
            break;
        case 3:
            printf("Novo CNPJ / CPF: ");
            fgets(lista_fornecedores[indice].cnpj, sizeof(lista_fornecedores[indice].cnpj), stdin);
            lista_fornecedores[indice].cnpj[strcspn(lista_fornecedores[indice].cnpj, "\n")] = 0;
            break;
        case 4:
            printf("Novo Endereco: ");
            fgets(lista_fornecedores[indice].endereco, sizeof(lista_fornecedores[indice].endereco), stdin);
            lista_fornecedores[indice].endereco[strcspn(lista_fornecedores[indice].endereco, "\n")] = 0;
            break;
        case 5:
            printf("Novo Telefone: ");
            fgets(lista_fornecedores[indice].telefone, sizeof(lista_fornecedores[indice].telefone), stdin);
            lista_fornecedores[indice].telefone[strcspn(lista_fornecedores[indice].telefone, "\n")] = 0;
            break;
        case 6:
            printf("Novo Tipo de Servico: ");
            fgets(lista_fornecedores[indice].tipo_servico, sizeof(lista_fornecedores[indice].tipo_servico), stdin);
            lista_fornecedores[indice].tipo_servico[strcspn(lista_fornecedores[indice].tipo_servico, "\n")] = 0;
            break;
        case 0:
            printf("\nAlteracoes salvas!\n");
            break;
        default:
            printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);
    salvarFornecedores();
}

/*
  Exclui um fornecedor.
 */
void excluirFornecedor()
{
    listarFornecedores();
    if (num_fornecedores == 0)
        return;

    int codigo;
    printf("\nDigite o codigo do fornecedor que deseja excluir: ");
    scanf("%d", &codigo);
    limpar_buffer();

    int indice = -1;
    for (int i = 0; i < num_fornecedores; i++)
    {
        if (lista_fornecedores[i].codigo == codigo)
        {
            indice = i;
            break;
        }
    }

    if (indice != -1)
    {
        char confirmacao;
        printf("Tem certeza que deseja excluir o fornecedor %s? (s/n): ", lista_fornecedores[indice].nome_fantasia);
        scanf(" %c", &confirmacao);
        limpar_buffer();

        if (confirmacao == 's' || confirmacao == 'S')
        {
            lista_fornecedores[indice] = lista_fornecedores[num_fornecedores - 1];
            num_fornecedores--;
            printf("\nFornecedor excluido com sucesso!\n");
            salvarFornecedores();
        }
        else
        {
            printf("\nExclusao cancelada.\n");
        }
    }
    else
    {
        printf("\nFornecedor com codigo %d nao encontrado.\n", codigo);
    }
}

/*
  Salva os dados dos fornecedores em um arquivo binário.
 */
void salvarFornecedores()
{
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA)
        return;

    FILE *arquivo = fopen("../data/fornecedores.dat", "wb");
    if (arquivo == NULL)
    {
        perror("Nao foi possivel abrir o arquivo de fornecedores");
        return;
    }
    fwrite(&num_fornecedores, sizeof(int), 1, arquivo);
    fwrite(lista_fornecedores, sizeof(Fornecedor), num_fornecedores, arquivo);
    fclose(arquivo);
}

/*
  Carrega os dados dos fornecedores de um arquivo binário.
 */
void carregarFornecedores()
{
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA)
        return;

    FILE *arquivo = fopen("../data/fornecedores.dat", "rb");
    if (arquivo != NULL)
    {
        fread(&num_fornecedores, sizeof(int), 1, arquivo);
        if (num_fornecedores > 0)
        {
            lista_fornecedores = malloc(num_fornecedores * sizeof(Fornecedor));
            if (lista_fornecedores != NULL)
            {
                fread(lista_fornecedores, sizeof(Fornecedor), num_fornecedores, arquivo);
                capacidade_fornecedores = num_fornecedores;
            }
        }
        fclose(arquivo);
    }
}

/*
  Libera a memória alocada para a lista de fornecedores.
 */
void liberarMemoriaFornecedores()
{
    if (lista_fornecedores != NULL)
    {
        free(lista_fornecedores);
        lista_fornecedores = NULL;
    }
}