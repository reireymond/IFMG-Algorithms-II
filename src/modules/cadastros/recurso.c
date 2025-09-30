#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastros/recurso.h"
#include "config.h"
#include "utils.h"
#include "structs.h"

#define RECURSOS_DATA_FILE "../data/recursos.dat"

// Adiciona um novo recurso.
void adicionarRecurso(Sistema *sistema)
{
    // Verifica se o array de recursos está cheio
    // Se estiver cheio, será necessário aumentar a capacidade antes de adicionar um novo recurso
if (sistema->num_recursos == sistema->capacidade_recursos)
{

    if (sistema->num_recursos == sistema->capacidade_recursos)
    {
        int nova_capacidade = (sistema->capacidade_recursos == 0) ? 10 : sistema->capacidade_recursos * 2;
        Recurso *temp = realloc(sistema->lista_recursos, nova_capacidade * sizeof(Recurso));

        if (temp == NULL)
        {
            printf("\nErro critico de alocacao de memoria para recursos!\n");
            return;
        }
        sistema->lista_recursos = temp;
        sistema->capacidade_recursos = nova_capacidade;
    }
}
    Recurso novo_recurso;
    printf("\n--- Cadastro de Novo Recurso/Equipamento ---\n");

    novo_recurso.codigo = sistema->num_recursos + 1;
    printf("Codigo do Recurso: %d\n", novo_recurso.codigo);

    printf("Descricao (Ex: Caixa de Som Ativa): ");
    fgets(novo_recurso.descricao, sizeof(novo_recurso.descricao), stdin);
    novo_recurso.descricao[strcspn(novo_recurso.descricao, "\n")] = 0;

    printf("Categoria (Ex: Sonorizacao): ");
    fgets(novo_recurso.categoria, sizeof(novo_recurso.categoria), stdin);
    novo_recurso.categoria[strcspn(novo_recurso.categoria, "\n")] = 0;

    printf("Quantidade em Estoque: ");
    scanf("%d", &novo_recurso.quantidade_estoque);
    limpar_buffer();

    printf("Preco de Custo (unitario): R$ ");
    scanf("%f", &novo_recurso.preco_custo);
    limpar_buffer();

    printf("Valor da Locacao (diaria): R$ ");
    scanf("%f", &novo_recurso.valor_locacao);
    limpar_buffer();

    sistema->lista_recursos[sistema->num_recursos] = novo_recurso;
    sistema->num_recursos++;

    printf("\nRecurso '%s' cadastrado com sucesso!\n", novo_recurso.descricao);
    salvarRecursos(sistema);
}

// Lista todos os recursos cadastrados.
void listarRecursos(Sistema *sistema)
{
    if (sistema->num_recursos == 0)
    {
        printf("\nNenhum recurso cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Recursos e Equipamentos ---\n");
    for (int i = 0; i < sistema->num_recursos; i++)
    {
        printf("----------------------------------\n");
        printf("Codigo: %d\n", sistema->lista_recursos[i].codigo);
        printf("Descricao: %s\n", sistema->lista_recursos[i].descricao);
        printf("Categoria: %s\n", sistema->lista_recursos[i].categoria);
        printf("Estoque: %d unid.\n", sistema->lista_recursos[i].quantidade_estoque);
        printf("Preco de Custo: R$ %.2f\n", sistema->lista_recursos[i].preco_custo);
        printf("Valor Locacao (diaria): R$ %.2f\n", sistema->lista_recursos[i].valor_locacao);
    }
    printf("----------------------------------\n");
}

// Altera os dados de um recurso.
void alterarRecurso(Sistema *sistema)
{
    listarRecursos(sistema);
    if (sistema->num_recursos == 0)
        return;

    int codigo;
    int indice = -1;

    printf("\nDigite o codigo do recurso que deseja alterar: ");
    scanf("%d", &codigo);
    limpar_buffer();

    for (int i = 0; i < sistema->num_recursos; i++)
    {
        if (sistema->lista_recursos[i].codigo == codigo)
        {
            indice = i;
            break;
        }
    }

    if (indice == -1)
    {
        printf("\nRecurso com codigo %d nao encontrado.\n", codigo);
        return;
    }

    int opcao;
    do
    {
        limpar_tela();
        printf("--- Alterando Recurso: %s ---\n", sistema->lista_recursos[indice].descricao);
        printf("1. Alterar Descricao\n");
        printf("2. Alterar Categoria\n");
        printf("3. Alterar Quantidade em Estoque\n");
        printf("4. Alterar Preco de Custo\n");
        printf("5. Alterar Valor da Locacao\n");
        printf("0. Salvar e Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao)
        {
        case 1:
            printf("Nova Descricao: ");
            fgets(sistema->lista_recursos[indice].descricao, sizeof(sistema->lista_recursos[indice].descricao), stdin);
            sistema->lista_recursos[indice].descricao[strcspn(sistema->lista_recursos[indice].descricao, "\n")] = 0;
            break;
        case 2:
            printf("Nova Categoria: ");
            fgets(sistema->lista_recursos[indice].categoria, sizeof(sistema->lista_recursos[indice].categoria), stdin);
            sistema->lista_recursos[indice].categoria[strcspn(sistema->lista_recursos[indice].categoria, "\n")] = 0;
            break;
        case 3:
            printf("Nova Quantidade em Estoque: ");
            scanf("%d", &sistema->lista_recursos[indice].quantidade_estoque);
            limpar_buffer();
            break;
        case 4:
            printf("Novo Preco de Custo: R$ ");
            scanf("%f", &sistema->lista_recursos[indice].preco_custo);
            limpar_buffer();
            break;
        case 5:
            printf("Novo Valor da Locacao: R$ ");
            scanf("%f", &sistema->lista_recursos[indice].valor_locacao);
            limpar_buffer();
            break;
        case 0:
            printf("\nAlteracoes salvas!\n");
            break;
        default:
            printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);
    salvarRecursos(sistema);
}

// Exclui um recurso.
void excluirRecurso(Sistema *sistema)
{
    listarRecursos(sistema);
    if (sistema->num_recursos == 0)
        return;

    int codigo;
    printf("\nDigite o codigo do recurso que deseja excluir: ");
    scanf("%d", &codigo);
    limpar_buffer();

    int indice = -1;
    for (int i = 0; i < sistema->num_recursos; i++)
    {
        if (sistema->lista_recursos[i].codigo == codigo)
        {
            indice = i;
            break;
        }
    }

    if (indice != -1)
    {
        char confirmacao;
        printf("Tem certeza que deseja excluir o recurso %s? (s/n): ", sistema->lista_recursos[indice].descricao);
        scanf(" %c", &confirmacao);
        limpar_buffer();

        if (confirmacao == 's' || confirmacao == 'S')
        {
            sistema->lista_recursos[indice] = sistema->lista_recursos[sistema->num_recursos - 1];
            sistema->num_recursos--;
            printf("\nRecurso excluido com sucesso!\n");
            salvarRecursos(sistema);
        }
        else
        {
            printf("\nExclusao cancelada.\n");
        }
    }
    else
    {
        printf("\nRecurso com codigo %d nao encontrado.\n", codigo);
    }
}

// Salva os recursos em arquivo.
void salvarRecursos(Sistema *sistema)
{
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA)
        return;

    FILE *arquivo = fopen(RECURSOS_DATA_FILE, "wb"); // abre o arquivo para escrita em modo binário
    if (arquivo == NULL)
    {
        perror("Nao foi possivel abrir o arquivo de recursos");
        return;
    }
    fwrite(&sistema->num_recursos, sizeof(int), 1, arquivo);
    fwrite(sistema->lista_recursos, sizeof(Recurso), sistema->num_recursos, arquivo);
    fclose(arquivo);
}

// Carrega os recursos do arquivo.
void carregarRecursos(Sistema *sistema)
{
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA)
        return;

    FILE *arquivo = fopen(RECURSOS_DATA_FILE, "rb"); // abre o arquivo para leitura em binário
    if (arquivo != NULL)
    {
        fread(&sistema->num_recursos, sizeof(int), 1, arquivo);
        if (sistema->num_recursos > 0)
        {
            sistema->lista_recursos = malloc(sistema->num_recursos * sizeof(Recurso));
            if (sistema->lista_recursos != NULL)
            {
                fread(sistema->lista_recursos, sizeof(Recurso), sistema->num_recursos, arquivo);
                sistema->capacidade_recursos = sistema->num_recursos;
            }
        }
        fclose(arquivo);
    }
}

// Libera a memória alocada para a lista de recursos.
void liberarMemoriaRecursos(Sistema *sistema)
{
    if (sistema->lista_recursos != NULL)
    {
        free(sistema->lista_recursos);
        sistema->lista_recursos = NULL;
    }
}