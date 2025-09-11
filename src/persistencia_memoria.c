#include <stdio.h>
#include <string.h>

#include "../include/persistencia.h"

// --- ARMAZENAMENTO EM MEMÓRIA ---
#define MAX_CLIENTES 100
static Cliente clientes_em_memoria[MAX_CLIENTES];
static int num_clientes = 0;

// --- FUNÇÕES DO CRUD DE CLIENTE ---

void memoria_salvar_cliente(Cliente c) {
    if (num_clientes < MAX_CLIENTES) {
        clientes_em_memoria[num_clientes] = c;
        num_clientes++;
    } else {
        printf("ERRO: Limite de clientes na memoria atingido.\n");
    }
}

void memoria_listar_todos_clientes() {
    printf("\n--- Lista de Clientes (Armazenados em Memoria) ---\n");
    if (num_clientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
    } else {
        for (int i = 0; i < num_clientes; i++) {
            printf("Cod: %d | Nome: %s | CNPJ/CPF: %s\n",
                   clientes_em_memoria[i].codigo,
                   clientes_em_memoria[i].nome_razao_social,
                   clientes_em_memoria[i].cpf_cnpj);
        }
    }
    printf("--------------------------------------------------\n");
}

Cliente memoria_buscar_cliente_por_codigo(int codigo) {
    for (int i = 0; i < num_clientes; i++) {
        if (clientes_em_memoria[i].codigo == codigo) {
            return clientes_em_memoria[i];
        }
    }
    // Se não encontrar, retorna um cliente com código -1 (indicando erro)
    Cliente c_nulo = {-1};
    return c_nulo;
}

void memoria_alterar_cliente(Cliente c) {
    for (int i = 0; i < num_clientes; i++) {
        if (clientes_em_memoria[i].codigo == c.codigo) {
            clientes_em_memoria[i] = c; // Sobrescreve o cliente antigo
            return;
        }
    }
}

void memoria_excluir_cliente(int codigo) {
    int indice_para_excluir = -1;
    // Primeiro, encontra o índice do cliente a ser excluído
    for (int i = 0; i < num_clientes; i++) {
        if (clientes_em_memoria[i].codigo == codigo) {
            indice_para_excluir = i;
            break;
        }
    }

    // Se encontrou, "puxa" todos os elementos seguintes uma posição para trás
    if (indice_para_excluir != -1) {
        for (int i = indice_para_excluir; i < num_clientes - 1; i++) {
            clientes_em_memoria[i] = clientes_em_memoria[i + 1];
        }
        num_clientes--; // Diminui o contador de clientes
    }
}

// --- FUNÇÃO DE INICIALIZAÇÃO ---

void inicializar_persistencia_memoria(Persistencia* p) {
    printf("LOG: Iniciando persistencia em MEMORIA.\n");

    p->salvar_cliente = memoria_salvar_cliente;
    p->listar_todos_clientes = memoria_listar_todos_clientes;
    p->buscar_cliente_por_codigo = memoria_buscar_cliente_por_codigo;
    p->alterar_cliente = memoria_alterar_cliente;
    p->excluir_cliente = memoria_excluir_cliente;
}