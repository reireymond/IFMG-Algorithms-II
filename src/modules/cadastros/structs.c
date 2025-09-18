#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"

/* =========================================================
   Arquivo: structs.c
   Objetivo: Contém funções auxiliares para manipulação
   das estruturas de dados principais do sistema
   (Produtora e Cliente).

   Apesar do nome, aqui não estão as definições das
   structs (que ficam em `structs.h`), mas sim funções
   que facilitam a criação e cópia dessas entidades.
   ========================================================= */

/* =========================================================
   Função: criarProdutora
   Objetivo: Constrói uma nova struct Produtora a partir
   dos parâmetros fornecidos. Funciona como um "construtor"
   em linguagens orientadas a objetos.

   Parâmetros: strings e valores referentes a cada campo da
   Produtora.
   Retorno: struct Produtora preenchida.
   ========================================================= */
Produtora criarProdutora(
    char *nome_fantasia,
    char *razao_social,
    char *nome_do_responsavel,
    char *cnpj,
    char *inscricao_estadual,
    char *endereco,
    char *telefone,
    char *telefone_responsavel,
    char *email,
    float margem_lucro)
{
    Produtora nova;

    // Copia campo por campo para dentro da struct
    strncpy(nova.nome_fantasia, nome_fantasia, sizeof(nova.nome_fantasia));
    strncpy(nova.razao_social, razao_social, sizeof(nova.razao_social));
    strncpy(nova.nome_do_responsavel, nome_do_responsavel, sizeof(nova.nome_do_responsavel));
    strncpy(nova.cnpj, cnpj, sizeof(nova.cnpj));
    strncpy(nova.inscricao_estadual, inscricao_estadual, sizeof(nova.inscricao_estadual));
    strncpy(nova.endereco, endereco, sizeof(nova.endereco));
    strncpy(nova.telefone, telefone, sizeof(nova.telefone));
    strncpy(nova.telefone_responsavel, telefone_responsavel, sizeof(nova.telefone_responsavel));
    strncpy(nova.email, email, sizeof(nova.email));

    nova.margem_lucro = margem_lucro;

    return nova;
}

/* =========================================================
   Função: criarCliente
   Objetivo: Constrói uma nova struct Cliente a partir
   dos parâmetros fornecidos. Também funciona como um
   "construtor".

   Parâmetros: código numérico e dados do cliente.
   Retorno: struct Cliente preenchida.
   ========================================================= */
Cliente criarCliente(
    int codigo,
    char *razao_social,
    char *cnpj,
    char *endereco,
    char *telefone,
    char *email,
    char *nome_do_contato)
{
    Cliente novo;

    novo.codigo = codigo;
    strncpy(novo.razao_social, razao_social, sizeof(novo.razao_social));
    strncpy(novo.cnpj, cnpj, sizeof(novo.cnpj));
    strncpy(novo.endereco, endereco, sizeof(novo.endereco));
    strncpy(novo.telefone, telefone, sizeof(novo.telefone));
    strncpy(novo.email, email, sizeof(novo.email));
    strncpy(novo.nome_do_contato, nome_do_contato, sizeof(novo.nome_do_contato));

    return novo;
}
