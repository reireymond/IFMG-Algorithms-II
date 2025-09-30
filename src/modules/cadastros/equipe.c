#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastros/equipe.h"
#include "config.h"
#include "utils.h"
#include "structs.h"

#define EQUIPE_DATA_FILE "../data/equipe.dat"

// Adiciona um novo membro da equipe.
void adicionarEquipeInterna(Sistema *sistema)
{
    // Verifica se o array de equipe está cheio
   // Se estiver, será necessário aumentar a capacidade antes de adicionar  uma nova equipe
    if (sistema->num_equipe == sistema->capacidade_equipe)
    {
        int nova_capacidade = (sistema->capacidade_equipe == 0) ? 10 : sistema->capacidade_equipe * 2;
        EquipeInterna *temp = realloc(sistema->lista_equipe, nova_capacidade * sizeof(EquipeInterna));
        if (temp == NULL)
        {
            printf("\nErro crítico de alocação de memória para equipe!\n");
            return;
        }
        sistema->lista_equipe = temp;
        sistema->capacidade_equipe = nova_capacidade;
    }

    EquipeInterna novo_membro;
    printf("\n--- Cadastro de Novo Membro da Equipe ---\n");
    novo_membro.codigo = sistema->num_equipe + 1;
    printf("Codigo do Membro: %d\n", novo_membro.codigo);

    printf("Nome: ");
    fgets(novo_membro.nome, sizeof(novo_membro.nome), stdin);
    novo_membro.nome[strcspn(novo_membro.nome, "\n")] = 0;

    printf("CPF: ");
    fgets(novo_membro.cpf, sizeof(novo_membro.cpf), stdin);
    novo_membro.cpf[strcspn(novo_membro.cpf, "\n")] = 0;

    printf("Funcao: ");
    fgets(novo_membro.funcao, sizeof(novo_membro.funcao), stdin);
    novo_membro.funcao[strcspn(novo_membro.funcao, "\n")] = 0;

    printf("Valor da diaria: R$ ");
    scanf("%f", &novo_membro.valor_diaria);
    limpar_buffer();

    sistema->lista_equipe[sistema->num_equipe] = novo_membro;
    sistema->num_equipe++;

    printf("\nMembro '%s' cadastrado com sucesso!!\n", novo_membro.nome);
    salvarEquipeInterna(sistema);
}

// Lista todos os membros da equipe.
void listarEquipeInterna(Sistema *sistema)
{
    if (sistema->num_equipe == 0)
    {
        printf("\nNenhum membro da equipe cadastrado.\n");
        return;
    }

    printf("\n--- Lista de membros da equipe interna ---\n");
    for (int i = 0; i < sistema->num_equipe; i++)
    {
        printf("----------------------------------\n");
        printf("Codigo: %d\n", sistema->lista_equipe[i].codigo);
        printf("Nome: %s\n", sistema->lista_equipe[i].nome);
        printf("CPF: %s\n", sistema->lista_equipe[i].cpf);
        printf("Funcao: %s\n", sistema->lista_equipe[i].funcao);
        printf("Diaria: R$ %.2f\n", sistema->lista_equipe[i].valor_diaria);
    }
    printf("----------------------------------\n");
}

// Altera dados de um membro da equipe.
void alterarEquipeInterna(Sistema *sistema)
{
    listarEquipeInterna(sistema);
    if (sistema->num_equipe == 0)
    {
        return;
    }
    int codigo;
    int indice = -1;
    printf("\nDigite o codigo do membro que deseja alterar: ");
    scanf("%d", &codigo);
    limpar_buffer();

    for (int i = 0; i < sistema->num_equipe; i++)
    {
        if (sistema->lista_equipe[i].codigo == codigo)
        {
            indice = i;
            break;
        }
    }

    if (indice == -1)
    {
        printf("\nMembro com codigo %d nao encontrado.\n", codigo);
        return;
    }

    int opcao;
    do
    {
        limpar_tela();
        printf("--- Alterando Membro: %s ---\n", sistema->lista_equipe[indice].nome);
        printf("1. Alterar Nome\n");
        printf("2. Alterar CPF\n");
        printf("3. Alterar Funcao\n");
        printf("4. Alterar Valor da Diaria\n");
        printf("0. Salvar e Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao)
        {
        case 1:
            printf("Novo Nome: ");
            fgets(sistema->lista_equipe[indice].nome, sizeof(sistema->lista_equipe[indice].nome), stdin);
            sistema->lista_equipe[indice].nome[strcspn(sistema->lista_equipe[indice].nome, "\n")] = 0;
            break;
        case 2:
            printf("Novo CPF: ");
            fgets(sistema->lista_equipe[indice].cpf, sizeof(sistema->lista_equipe[indice].cpf), stdin);
            sistema->lista_equipe[indice].cpf[strcspn(sistema->lista_equipe[indice].cpf, "\n")] = 0;
            break;
        case 3:
            printf("Nova Funcao: ");
            fgets(sistema->lista_equipe[indice].funcao, sizeof(sistema->lista_equipe[indice].funcao), stdin);
            sistema->lista_equipe[indice].funcao[strcspn(sistema->lista_equipe[indice].funcao, "\n")] = 0;
            break;
        case 4:
            printf("Novo Valor da Diaria: R$ ");
            scanf("%f", &sistema->lista_equipe[indice].valor_diaria);
            limpar_buffer();
            break;
        case 0:
            printf("\nAlteracoes salvas!\n");
            break;
        default:
            printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);
    salvarEquipeInterna(sistema);
}

// Exclui um membro da equipe.
void excluirEquipeInterna(Sistema *sistema)
{
    listarEquipeInterna(sistema);
    if (sistema->num_equipe == 0)
        return;

    int codigo;
    printf("\nDigite o codigo do membro que deseja excluir: ");
    scanf("%d", &codigo);
    limpar_buffer();

    int indice = -1;
    for (int i = 0; i < sistema->num_equipe; i++)
    {
        if (sistema->lista_equipe[i].codigo == codigo)
        {
            indice = i;
            break;
        }
    }

    if (indice != -1)
    {
        char confirmacao;
        printf("Tem certeza que deseja excluir o membro %s? (s/n): ", sistema->lista_equipe[indice].nome);
        scanf(" %c", &confirmacao);
        limpar_buffer();

        if (confirmacao == 's' || confirmacao == 'S')
        {
            sistema->lista_equipe[indice] = sistema->lista_equipe[sistema->num_equipe - 1];
            sistema->num_equipe--;
            printf("\nMembro excluido com sucesso!\n");
            salvarEquipeInterna(sistema);
        }
        else
        {
            printf("\nExclusao cancelada.\n");
        }
    }
    else
    {
        printf("\nMembro com codigo %d nao encontrado.\n", codigo);
    }
}

// Salva os dados da equipe em arquivo.
void salvarEquipeInterna(Sistema *sistema)
{
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA)
        return;

    FILE *arquivo = fopen(EQUIPE_DATA_FILE, "wb"); //abre o arquivo para escrita em modo binário
    if (arquivo == NULL)
    {
        perror("Nao foi possivel abrir o arquivo da equipe");
        return;
    }
    fwrite(&sistema->num_equipe, sizeof(int), 1, arquivo);
    fwrite(sistema->lista_equipe, sizeof(EquipeInterna), sistema->num_equipe, arquivo);
    fclose(arquivo);
}

// Carrega os dados da equipe do arquivo.
void carregarEquipeInterna(Sistema *sistema)
{
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA)
        return;

    FILE *arquivo = fopen(EQUIPE_DATA_FILE, "rb"); // abre o arquivo para leitura em binário
    if (arquivo != NULL)
    {
        fread(&sistema->num_equipe, sizeof(int), 1, arquivo);
        if (sistema->num_equipe > 0)
        {
            sistema->lista_equipe = malloc(sistema->num_equipe * sizeof(EquipeInterna));
            if (sistema->lista_equipe != NULL)
            {
                fread(sistema->lista_equipe, sizeof(EquipeInterna), sistema->num_equipe, arquivo);
                sistema->capacidade_equipe = sistema->num_equipe;
            }
        }
        fclose(arquivo);
    }
}

// Libera a memória alocada para a lista da equipe.
void liberarMemoriaEquipe(Sistema *sistema)
{
    if (sistema->lista_equipe != NULL)
    {
        free(sistema->lista_equipe);
        sistema->lista_equipe = NULL;
    }
}