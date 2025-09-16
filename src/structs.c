#include <stdlib.h>
#include <string.h>

#include "structs.h"

Produtora *criar_produtora()
{
    Produtora *nova_produtora = (Produtora *)malloc(sizeof(Produtora));

    if (nova_produtora != NULL)
    {
        strcpy(nova_produtora->razao_social, "");
        strcpy(nova_produtora->nome_do_responsavel, "");
        strcpy(nova_produtora->cnpj, "");
        strcpy(nova_produtora->inscricao_estadual, "");
        strcpy(nova_produtora->endereco, "");
        strcpy(nova_produtora->telefone, "");
        strcpy(nova_produtora->telefone_responsavel, "");
        strcpy(nova_produtora->email, "");
        nova_produtora->margem_lucro = 0;
    }

    return nova_produtora;
}

Cliente *criar_cliente()
{
    Cliente *novo_cliente = (Cliente *)malloc(sizeof(Cliente));

    if (novo_cliente != NULL)
    {
        novo_cliente->codigo = 0;
        strcpy(novo_cliente->razao_social, "");
        strcpy(novo_cliente->nome_do_cliente, "");
        strcpy(novo_cliente->cnpj, "");
        strcpy(novo_cliente->cpf, "");
        strcpy(novo_cliente->endereco, "");
        strcpy(novo_cliente->telefone, "");
        strcpy(novo_cliente->email, "");
        strcpy(novo_cliente->nome_do_contato, "");
    }

    return novo_cliente;
}