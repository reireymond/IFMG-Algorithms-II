#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastros/recurso.h"
#include "config.h"
#include "utils.h"

// Ponteiro para a lista de recursos.
static Recurso *lista_recursos = NULL;
// Número de recursos cadastrados.
static int num_recursos = 0;
// Capacidade atual do array de recursos.
static int capacidade_recursos = 0;

/*
  Adiciona um novo recurso.
 */
void adicionarRecurso()
{
    if (num_recursos == capacidade_recursos)
    {
        int nova_capacidade = (capacidade_recursos == 0) ? 10 : capacidade_recursos * 2;
        Recurso *temp = realloc(lista_recursos, nova_capacidade * sizeof(Recurso));

        if (temp == NULL)
        {
            printf("\nErro critico de alocacao de memoria para recursos!\n");
            return;
        }
        lista_recursos = temp;
        capacidade_recursos = nova_capacidade;
    }

    Recurso novo_recurso;
    printf("\n--- Cadastro de Novo Recurso/Equipamento ---\n");

    novo_recurso.codigo = num_recursos + 1;
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

    lista_recursos[num_recursos] = novo_recurso;
    num_recursos++;

    printf("\nRecurso '%s' cadastrado com sucesso!\n", novo_recurso.descricao);
    salvarRecursos();
}

/*
  Lista todos os recursos.
 */
void listarRecursos()
{
    if (num_recursos == 0)
    {
        printf("\nNenhum recurso cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Recursos e Equipamentos ---\n");
    for (int i = 0; i < num_recursos; i++)
    {
        printf("----------------------------------\n");
        printf("Codigo: %d\n", lista_recursos[i].codigo);
        printf("Descricao: %s\n", lista_recursos[i].descricao);
        printf("Categoria: %s\n", lista_recursos[i].categoria);
        printf("Estoque: %d unid.\n", lista_recursos[i].quantidade_estoque);
        printf("Preco de Custo: R$ %.2f\n", lista_recursos[i].preco_custo);
        printf("Valor Locacao (diaria): R$ %.2f\n", lista_recursos[i].valor_locacao);
    }
    printf("----------------------------------\n");
}

/*
  Altera os dados de um recurso.
 */
void alterarRecurso()
{
    listarRecursos();
    if (num_recursos == 0)
        return;

    int codigo;
    int indice = -1;

    printf("\nDigite o codigo do recurso que deseja alterar: ");
    scanf("%d", &codigo);
    limpar_buffer();

    for (int i = 0; i < num_recursos; i++)
    {
        if (lista_recursos[i].codigo == codigo)
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
        printf("--- Alterando Recurso: %s ---\n", lista_recursos[indice].descricao);
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
            fgets(lista_recursos[indice].descricao, sizeof(lista_recursos[indice].descricao), stdin);
            lista_recursos[indice].descricao[strcspn(lista_recursos[indice].descricao, "\n")] = 0;
            break;
        case 2:
            printf("Nova Categoria: ");
            fgets(lista_recursos[indice].categoria, sizeof(lista_recursos[indice].categoria), stdin);
            lista_recursos[indice].categoria[strcspn(lista_recursos[indice].categoria, "\n")] = 0;
            break;
        case 3:
            printf("Nova Quantidade em Estoque: ");
            scanf("%d", &lista_recursos[indice].quantidade_estoque);
            limpar_buffer();
            break;
        case 4:
            printf("Novo Preco de Custo: R$ ");
            scanf("%f", &lista_recursos[indice].preco_custo);
            limpar_buffer();
            break;
        case 5:
            printf("Novo Valor da Locacao: R$ ");
            scanf("%f", &lista_recursos[indice].valor_locacao);
            limpar_buffer();
            break;
        case 0:
            printf("\nAlteracoes salvas!\n");
            break;
        default:
            printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);
    salvarRecursos();
}

/*
  Exclui um recurso.
 */
void excluirRecurso()
{
    listarRecursos();
    if (num_recursos == 0)
        return;

    int codigo;
    printf("\nDigite o codigo do recurso que deseja excluir: ");
    scanf("%d", &codigo);
    limpar_buffer();

    int indice = -1;
    for (int i = 0; i < num_recursos; i++)
    {
        if (lista_recursos[i].codigo == codigo)
        {
            indice = i;
            break;
        }
    }

    if (indice != -1)
    {
        char confirmacao;
        printf("Tem certeza que deseja excluir o recurso %s? (s/n): ", lista_recursos[indice].descricao);
        scanf(" %c", &confirmacao);
        limpar_buffer();

        if (confirmacao == 's' || confirmacao == 'S')
        {
            lista_recursos[indice] = lista_recursos[num_recursos - 1];
            num_recursos--;
            printf("\nRecurso excluido com sucesso!\n");
            salvarRecursos();
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

/*
  Salva os dados dos recursos em um arquivo binário.
 */
void salvarRecursos()
{
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA)
        return;

    FILE *arquivo = fopen("../data/recursos.dat", "wb");
    if (arquivo == NULL)
    {
        perror("Nao foi possivel abrir o arquivo de recursos");
        return;
    }
    fwrite(&num_recursos, sizeof(int), 1, arquivo);
    fwrite(lista_recursos, sizeof(Recurso), num_recursos, arquivo);
    fclose(arquivo);
}

/*
  Carrega os dados dos recursos de um arquivo binário.
 */
void carregarRecursos()
{
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA)
        return;

    FILE *arquivo = fopen("../data/recursos.dat", "rb");
    if (arquivo != NULL)
    {
        fread(&num_recursos, sizeof(int), 1, arquivo);
        if (num_recursos > 0)
        {
            lista_recursos = malloc(num_recursos * sizeof(Recurso));
            if (lista_recursos != NULL)
            {
                fread(lista_recursos, sizeof(Recurso), num_recursos, arquivo);
                capacidade_recursos = num_recursos;
            }
        }
        fclose(arquivo);
    }
}

/*
  Libera a memória alocada para a lista de recursos.
 */
void liberarMemoriaRecursos()
{
    if (lista_recursos != NULL)
    {
        free(lista_recursos);
        lista_recursos = NULL;
    }
}