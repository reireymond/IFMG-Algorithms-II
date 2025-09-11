#include <stdio.h>
#include <string.h>
#include "../include/persistencia.h"

int main() {
    // Declara a nossa "interface" de persistência
    Persistencia p;

    // Configura a interface para usar as funções de MEMÓRIA
    inicializar_persistencia_memoria(&p);

    printf("--- Realizando Testes ---\n");

    // Teste 1: Listar (deve estar vazio)
    printf("\n[Teste 1: Listar Clientes no Início]\n");
    p.listar_todos_clientes();

    // Teste 2: Cadastrar dois clientes
    printf("\n[Teste 2: Cadastrando dois clientes]\n");
    Cliente c1 = {1, "ACME Corporation S.A.", "11.222.333/0001-44"};
    Cliente c2 = {2, "Wayne Enterprises", "44.555.666/0001-77"};
    p.salvar_cliente(c1);
    p.salvar_cliente(c2);
    p.listar_todos_clientes();

    // Teste 3: Alterar o cliente de código 1
    printf("\n[Teste 3: Alterando o cliente de código 1]\n");
    strcpy(c1.nome_razao_social, "ACME Corp (Alterado)");
    p.alterar_cliente(c1);
    p.listar_todos_clientes();

    // Teste 4: Excluir o cliente de código 2
    printf("\n[Teste 4: Excluindo o cliente de código 2]\n");
    p.excluir_cliente(2);
    p.listar_todos_clientes();

    printf("\n--- Fim dos Testes ---\n");

    return 0;
}