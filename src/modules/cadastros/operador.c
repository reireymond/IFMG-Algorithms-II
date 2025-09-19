#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastros/operador.h"
#include "config.h"
#include "utils.h"

// Ponteiro para a lista de operadores.
static Operador *lista_operadores = NULL;
// Número de operadores cadastrados.
static int num_operadores = 0;
// Capacidade atual do array de operadores.
static int capacidade_operadores = 0;

/*
  Adiciona um novo operador.
 */
void adicionarOperador() {
    if (num_operadores == capacidade_operadores) {
        int nova_capacidade = (capacidade_operadores == 0) ? 10 : capacidade_operadores * 2;
        Operador *temp = realloc(lista_operadores, nova_capacidade * sizeof(Operador));
        if (temp == NULL) {
            printf("\nErro de alocacao de memoria para operadores!\n");
            return;
        }
        lista_operadores = temp;
        capacidade_operadores = nova_capacidade;
    }

    Operador novo;
    printf("\n--- Cadastro de Novo Operador ---\n");
    novo.codigo = num_operadores + 1;
    printf("Codigo: %d\n", novo.codigo);

    printf("Nome: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = 0;

    printf("Usuario: ");
    fgets(novo.usuario, sizeof(novo.usuario), stdin);
    novo.usuario[strcspn(novo.usuario, "\n")] = 0;

    printf("Senha: ");
    fgets(novo.senha, sizeof(novo.senha), stdin);
    novo.senha[strcspn(novo.senha, "\n")] = 0;

    lista_operadores[num_operadores] = novo;
    num_operadores++;

    printf("\nOperador '%s' cadastrado com sucesso!\n", novo.usuario);
    salvarOperadores();
}

/*
  Lista todos os operadores.
 */
void listarOperadores() {
    if (num_operadores == 0) {
        printf("\nNenhum operador cadastrado.\n");
        return;
    }
    printf("\n--- Lista de Operadores ---\n");
    for (int i = 0; i < num_operadores; i++) {
        printf("----------------------------------\n");
        printf("Codigo: %d\n", lista_operadores[i].codigo);
        printf("Nome: %s\n", lista_operadores[i].nome);
        printf("Usuario: %s\n", lista_operadores[i].usuario);
        printf("Senha: %s\n", lista_operadores[i].senha);
    }
    printf("----------------------------------\n");
}

/*
  Altera os dados de um operador.
 */
void alterarOperador() {
    listarOperadores();
    if (num_operadores == 0) return;

    int codigo, indice = -1;
    printf("\nDigite o codigo do operador que deseja alterar: ");
    scanf("%d", &codigo);
    limpar_buffer();

    for (int i = 0; i < num_operadores; i++) {
        if (lista_operadores[i].codigo == codigo) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\nOperador com codigo %d nao encontrado.\n", codigo);
        return;
    }

    int opcao;
    do {
        limpar_tela();
        printf("--- Alterando Operador: %s ---\n", lista_operadores[indice].usuario);
        printf("1. Alterar Nome\n");
        printf("2. Alterar Usuario\n");
        printf("3. Alterar Senha\n");
        printf("0. Salvar e Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1:
                printf("Novo Nome: ");
                fgets(lista_operadores[indice].nome, sizeof(lista_operadores[indice].nome), stdin);
                lista_operadores[indice].nome[strcspn(lista_operadores[indice].nome, "\n")] = 0;
                break;
            case 2:
                printf("Novo Usuario: ");
                fgets(lista_operadores[indice].usuario, sizeof(lista_operadores[indice].usuario), stdin);
                lista_operadores[indice].usuario[strcspn(lista_operadores[indice].usuario, "\n")] = 0;
                break;
            case 3:
                printf("Nova Senha: ");
                fgets(lista_operadores[indice].senha, sizeof(lista_operadores[indice].senha), stdin);
                lista_operadores[indice].senha[strcspn(lista_operadores[indice].senha, "\n")] = 0;
                printf("Senha alterada com sucesso.\n");
                break;
            case 0:
                printf("\nAlteracoes salvas!\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);
    salvarOperadores();
}

/*
  Exclui um operador.
 */
void excluirOperador() {
    listarOperadores();
    if (num_operadores == 0) return;

    int codigo, i;
    printf("\nDigite o codigo do operador que deseja excluir: ");
    scanf("%d", &codigo);
    limpar_buffer();

    for (i = 0; i < num_operadores; i++) {
        if (lista_operadores[i].codigo == codigo) {
            char confirmacao;
            printf("Tem certeza que deseja excluir o operador %s? (s/n): ", lista_operadores[i].usuario);
            scanf(" %c", &confirmacao);
            limpar_buffer();

            if (confirmacao == 's' || confirmacao == 'S') {
                lista_operadores[i] = lista_operadores[num_operadores - 1];
                num_operadores--;
                printf("\nOperador excluido com sucesso!\n");
                salvarOperadores();
            } else {
                printf("\nExclusao cancelada.\n");
            }
            return;
        }
    }
    printf("\nOperador com codigo %d nao encontrado.\n", codigo);
}

/*
  Salva os dados dos operadores em um arquivo binário.
 */
void salvarOperadores() {
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA) return;

    FILE *arquivo = fopen("../data/operadores.dat", "wb");
    if (arquivo == NULL) {
        perror("Nao foi possivel abrir o arquivo de operadores");
        return;
    }
    fwrite(&num_operadores, sizeof(int), 1, arquivo);
    fwrite(lista_operadores, sizeof(Operador), num_operadores, arquivo);
    fclose(arquivo);
}

/*
  Carrega os dados dos operadores de um arquivo binário.
 */
void carregarOperadores() {
    TipoArmazenamento modo = obterModoDeArmazenamento();
    if (modo == MEMORIA) return;

    FILE *arquivo = fopen("../data/operadores.dat", "rb");
    if (arquivo != NULL) {
        fread(&num_operadores, sizeof(int), 1, arquivo);
        if (num_operadores > 0) {
            lista_operadores = malloc(num_operadores * sizeof(Operador));
            if (lista_operadores != NULL) {
                fread(lista_operadores, sizeof(Operador), num_operadores, arquivo);
                capacidade_operadores = num_operadores;
            }
        }
        fclose(arquivo);
    }
}

/*
  Libera a memória alocada para a lista de operadores.
 */
void liberarMemoriaOperadores() {
    if (lista_operadores != NULL) {
        free(lista_operadores);
        lista_operadores = NULL;
    }
}