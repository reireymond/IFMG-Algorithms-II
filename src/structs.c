#include <stdlib.h>
#include <string.h>

#include "/../include/structs.h/"

Cliente* criarCliente() {
    Cliente* novo_cliente = (Cliente*) malloc(sizeof(Cliente));

    if (novo_cliente != NULL) {
        novo_cliente->codigo = 0;
        strcpy(novo_cliente->nome, "");
        strcpy(novo_cliente->cnpj, "");
        strcpy(novo_cliente->email, "");
    }

    return novo_cliente;
}

Equipamento* criarEquipamento() {
    Equipamento* novo_equipamento = (Equipamento*) malloc(sizeof(Equipamento));
    if (novo_equipamento != NULL) {
        novo_equipamento->codigo = 0;
        strcpy(novo_equipamento->descricao, "");
        novo_equipamento->quantidade_estoque = 0;
        novo_equipamento->preco_custo = 0.0;
        novo_equipamento->valor_locacao = 0.0;
    }
    return novo_equipamento;
}