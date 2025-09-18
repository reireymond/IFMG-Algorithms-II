#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastros/operador.h"
#include "config.h"
#include "utils.h"
#include "sha256.h"

// --- VARIÁVEIS GLOBAIS PARA OPERADORES ---
static Operador *lista_operadores = NULL;
static int num_operadores = 0;
static int capacidade_operadores = 0;

/* =========================================================
   Função: adicionarOperador
   Objetivo: Cadastra um novo operador, criptografando a senha.
   ========================================================= */
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

    char senha_temp[100]; // Buffer temporário para a senha
    printf("Senha: ");
    fgets(senha_temp, sizeof(senha_temp), stdin);
    senha_temp[strcspn(senha_temp, "\n")] = 0;

    // CRIPTOGRAFA A SENHA ANTES DE SALVAR
    char hash_senha[65];
    sha256_string(senha_temp, hash_senha);
    strncpy(novo.senha, hash_senha, sizeof(novo.senha) - 1);
    novo.senha[sizeof(novo.senha) - 1] = '\0'; // Garante terminação nula

    lista_operadores[num_operadores] = novo;
    num_operadores++;

    printf("\nOperador '%s' cadastrado com sucesso!\n", novo.usuario);
    salvarOperadores();
}

/* =========================================================
   Função: listarOperadores
   Objetivo: Exibe todos os operadores (sem mostrar a senha).
   ========================================================= */
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
        printf("Senha Hash: (oculto por seguranca)\n");
    }
    printf("----------------------------------\n");
}

// ... Implemente as outras funções (alterar, excluir, salvar, carregar, liberar) ...
// ... seguindo o mesmo padrão do cliente.c ...
// Lembre-se que em 'alterarOperador' você precisará de uma opção "Alterar Senha"
// que também chamará a função sha256_string.

void salvarOperadores() {
    // Implementação idêntica a salvarClientes, mas para operadores.dat
}

void carregarOperadores() {
    // Implementação idêntica a carregarClientes, mas para operadores.dat
}

void liberarMemoriaOperadores() {
    if (lista_operadores != NULL) {
        free(lista_operadores);
        lista_operadores = NULL;
    }
}