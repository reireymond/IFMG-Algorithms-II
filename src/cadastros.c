#include <stdio.h>
#include <stdlib.h>

#include "cadastros.h"

void adicionarCliente() {
    Cliente novo_cliente; 

    printf("\n--- Cadastro de Novo Cliente ---\n");

    printf("Digite o codigo: ");
    scanf("%d", &novo_cliente.codigo);
    getchar();

    printf("Digite o Nome / Razao Social: ");
    fgets(novo_cliente.nome, sizeof(novo_cliente.nome), stdin);
    
    novo_cliente.nome[strcspn(novo_cliente.nome, "\n")] = 0;

    printf("Digite o CPF / CNPJ: ");
    fgets(novo_cliente.cnpj, sizeof(novo_cliente.cnpj), stdin);
    novo_cliente.cnpj[strcspn(novo_cliente.cnpj, "\n")] = 0;
    
    printf("Digite o E-mail: ");
    fgets(novo_cliente.email, sizeof(novo_cliente.email), stdin);
    novo_cliente.email[strcspn(novo_cliente.email, "\n")] = 0;

    printf("\nCliente '%s' cadastrado com sucesso!\n", novo_cliente.nome);
}

void listarTodosClientes() {
    printf("\n--- Lista de Clientes Cadastrados ---\n");
    
    int total = 0;
}

void adicionarEquipamento() {
    Equipamento novo_equipamento;

    printf("\n--- Cadastro de Novo Equipamento ---\n");

    printf("\nEquipamento cadastrado com sucesso!\n");
}