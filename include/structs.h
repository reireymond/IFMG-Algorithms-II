#ifndef STRUCTS_H
#define STRUCTS_H

/* =========================================================
   Arquivo: structs.h
   Objetivo: Define as estruturas de dados principais do
   sistema, conforme especificado no enunciado do trabalho.
   ========================================================= */

// ----------------- ESTRUTURA: PRODUTORA -----------------
typedef struct
{
    char nome_fantasia[100];
    char razao_social[100];
    char nome_do_responsavel[100];
    char cnpj[20];
    char inscricao_estadual[20];
    char endereco[150];
    char telefone[20];
    char telefone_responsavel[20];
    char email[50];
    float margem_lucro;
} Produtora;

// ----------------- ESTRUTURA: CLIENTE -----------------
typedef struct
{
    int codigo;
    char razao_social[100];
    char cnpj[20];
    char endereco[150];
    char telefone[20];
    char email[50];
    char nome_do_contato[100];
} Cliente;

// ----------------- ESTRUTURA: EQUIPE INTERNA -----------------
typedef struct
{
    int codigo;
    char nome[100];
    char cpf[15];
    char funcao[50];
    float valor_diaria;
} EquipeInterna;

// ----------------- ESTRUTURA: RECURSO E EQUIPAMENTO -----------------
typedef struct
{
    int codigo;
    char descricao[150];
    char categoria[50];
    int quantidade_estoque;
    float preco_custo;
    float valor_locacao;
} Recurso;

// ----------------- ESTRUTURA: FORNECEDOR E PARCEIRO -----------------
typedef struct
{
    int codigo;
    char nome_fantasia[100];
    char razao_social[100];
    char cnpj[20];
    char endereco[150];
    char telefone[20];
    char tipo_servico[100];
} Fornecedor;

// ----------------- ESTRUTURA: OPERADOR DO SISTEMA -----------------
typedef struct
{
    int codigo;
    char nome[100];
    char usuario[50];
    char senha[65];
} Operador;

#endif