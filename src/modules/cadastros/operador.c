#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastros/operador.h"
#include "config.h"
#include "utils.h"
#include "structs.h"

#define OPERADORES_DATA_FILE "../data/operadores.dat"

// Adiciona um novo operador.
void adicionarOperador(Sistema *sistema)
{
    // Verifica se o array de operador está cheio
    // Se estiver, será necessário aumentar a capacidade antes de adicionar um novo operador
    if (sistema->num_operadores == sistema->capacidade_operadores)
    {
        int nova_capacidade = (sistema->capacidade_operadores == 0) ? 10 : sistema->capacidade_operadores * 2;
        Operador *temp = realloc(sistema->lista_operadores, nova_capacidade * sizeof(Operador));
        if (temp == NULL)
        {
            printf("\nErro de alocacao de memoria para operadores!\n");
            return;
        }
        sistema->lista_operadores = temp;
        sistema->capacidade_operadores = nova_capacidade;
    }

    Operador novo;
    printf("\n--- Cadastro de Novo Operador ---\n");
    // Gera o código do novo operador automaticamente.
    novo.codigo = sistema->num_operadores + 1;
    printf("Codigo: %d\n", novo.codigo);

    printf("Nome: ");
    // Lê o nome do operador.
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = 0;

    printf("Usuario: ");
    // Lê o nome de usuário do operador.
    fgets(novo.usuario, sizeof(novo.usuario), stdin);
    novo.usuario[strcspn(novo.usuario, "\n")] = 0;

    printf("Senha: ");
    // Lê a senha do operador.
    fgets(novo.senha, sizeof(novo.senha), stdin);
    novo.senha[strcspn(novo.senha, "\n")] = 0;

    sistema->lista_operadores[sistema->num_operadores] = novo;
    sistema->num_operadores++;

    printf("\nOperador '%s' cadastrado com sucesso!\n", novo.usuario);
    salvarOperadores(sistema);
}

// Lista todos os operadores.
void listarOperadores(Sistema *sistema)
{
    if (sistema->num_operadores == 0)
    {
        printf("\nNenhum operador cadastrado.\n");
        return;
    }
    printf("\n--- Lista de Operadores ---\n");
    // Percorre e exibe os dados de todos os operadores cadastrados.
    for (int i = 0; i < sistema->num_operadores; i++)
    {
        printf("----------------------------------\n");
        printf("Codigo: %d\n", sistema->lista_operadores[i].codigo);
        printf("Nome: %s\n", sistema->lista_operadores[i].nome);
        printf("Usuario: %s\n", sistema->lista_operadores[i].usuario);
        // Por segurança, não exibimos a senha.
        // printf("Senha: %s\n", sistema->lista_operadores[i].senha);
    }
    printf("----------------------------------\n");
}

// Altera os dados de um operador.
void alterarOperador(Sistema *sistema)
{
    listarOperadores(sistema);
    if (sistema->num_operadores == 0)
        return;

    int codigo, indice = -1;
    printf("\nDigite o codigo do operador que deseja alterar: ");
    scanf("%d", &codigo);
    limpar_buffer();

    // Busca o operador pelo código informado.
    for (int i = 0; i < sistema->num_operadores; i++)
    {
        if (sistema->lista_operadores[i].codigo == codigo)
        {
            indice = i;
            break;
        }
    }

    if (indice == -1)
    {
        printf("\nOperador com codigo %d nao encontrado.\n", codigo);
        return;
    }

    int opcao;
    do
    {
        limpar_tela();
        printf("--- Alterando Operador: %s ---\n", sistema->lista_operadores[indice].usuario);
        printf("1. Alterar Nome\n");
        printf("2. Alterar Usuario\n");
        printf("3. Alterar Senha\n");
        printf("0. Salvar e Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        limpar_buffer();

        // Executa a alteração do campo escolhido pelo usuário.
        switch (opcao)
        {
        case 1:
            printf("Novo Nome: ");
            fgets(sistema->lista_operadores[indice].nome, sizeof(sistema->lista_operadores[indice].nome), stdin);
            sistema->lista_operadores[indice].nome[strcspn(sistema->lista_operadores[indice].nome, "\n")] = 0;
            break;
        case 2:
            printf("Novo Usuario: ");
            fgets(sistema->lista_operadores[indice].usuario, sizeof(sistema->lista_operadores[indice].usuario), stdin);
            sistema->lista_operadores[indice].usuario[strcspn(sistema->lista_operadores[indice].usuario, "\n")] = 0;
            break;
        case 3:
            printf("Nova Senha: ");
            fgets(sistema->lista_operadores[indice].senha, sizeof(sistema->lista_operadores[indice].senha), stdin);
            sistema->lista_operadores[indice].senha[strcspn(sistema->lista_operadores[indice].senha, "\n")] = 0;
            printf("Senha alterada com sucesso.\n");
            break;
        case 0:
            printf("\nAlteracoes salvas!\n");
            break;
        default:
            printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);
    salvarOperadores(sistema);
}

// Exclui um operador.
void excluirOperador(Sistema *sistema)
{
    listarOperadores(sistema);
    if (sistema->num_operadores == 0)
        return;

    int codigo, i;
    printf("\nDigite o codigo do operador que deseja excluir: ");
    scanf("%d", &codigo);
    limpar_buffer();

    // Busca o operador pelo código informado para exclusão.
    for (i = 0; i < sistema->num_operadores; i++)
    {
        if (sistema->lista_operadores[i].codigo == codigo)
        {
            char confirmacao;
            printf("Tem certeza que deseja excluir o operador %s? (s/n): ", sistema->lista_operadores[i].usuario);
            scanf(" %c", &confirmacao);
            limpar_buffer();

            if (confirmacao == 's' || confirmacao == 'S')
            {
                sistema->lista_operadores[i] = sistema->lista_operadores[sistema->num_operadores - 1];
                sistema->num_operadores--;
                printf("\nOperador excluido com sucesso!\n");
                salvarOperadores(sistema);
            }
            else
            {
                printf("\nExclusao cancelada.\n");
            }
            return;
        }
    }
    printf("\nOperador com codigo %d nao encontrado.\n", codigo);
}

// Salva os dados dos operadores em arquivo.
void salvarOperadores(Sistema *sistema)
{
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA)
        return;

    FILE *arquivo = fopen(OPERADORES_DATA_FILE, "wb"); //abre o arquivo para escrita em modo binário
    if (arquivo == NULL)
    {
        perror("Nao foi possivel abrir o arquivo de operadores");
        return;
    }
    // Salva a quantidade de operadores no arquivo binário.
    fwrite(&sistema->num_operadores, sizeof(int), 1, arquivo);
    // Salva os dados dos operadores no arquivo binário.
    fwrite(sistema->lista_operadores, sizeof(Operador), sistema->num_operadores, arquivo);
    fclose(arquivo);
}

// Carrega os dados dos operadores do arquivo.
void carregarOperadores(Sistema *sistema)
{
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA)
        return;

    FILE *arquivo = fopen(OPERADORES_DATA_FILE, "rb"); // abre o arquivo para leitura em binário
    if (arquivo != NULL)
    {
    // Lê do arquivo binário a quantidade de operadores cadastrados.
    fread(&sistema->num_operadores, sizeof(int), 1, arquivo);
        if (sistema->num_operadores > 0)
        {
            sistema->lista_operadores = malloc(sistema->num_operadores * sizeof(Operador));
            if (sistema->lista_operadores != NULL)
            {
                // Lê os dados dos operadores do arquivo binário para a memória.
                fread(sistema->lista_operadores, sizeof(Operador), sistema->num_operadores, arquivo);
                sistema->capacidade_operadores = sistema->num_operadores;
            }
        }
        fclose(arquivo);
    }
}

// Libera a memória alocada para a lista de operadores.
void liberarMemoriaOperadores(Sistema *sistema)
{
    if (sistema->lista_operadores != NULL)
    {
        free(sistema->lista_operadores);
        sistema->lista_operadores = NULL;
    }
}