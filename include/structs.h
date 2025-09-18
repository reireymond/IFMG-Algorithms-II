#ifndef STRUCTS_H
#define STRUCTS_H

/* =========================================================
   Arquivo: structs.h
   Objetivo: Define as estruturas de dados principais do
   sistema (Produtora, Cliente, Equipe Interna, Recursos,
   Fornecedores e Operadores).

   Cada struct representa uma entidade real do sistema.
   ========================================================= */

// ----------------- ESTRUTURA: PRODUTORA -----------------

/**
 * Estrutura: Produtora
 * Representa a empresa responsável pelos eventos.
 */
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

/**
 * Estrutura: Cliente
 * Representa um cliente da produtora (pessoa física ou jurídica).
 */
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
// (Futuro desenvolvimento: gerenciar funcionários)
typedef struct
{
    int id;
    char nome[100];
    char cargo[50];
    float salario;
} EquipeInterna;

// ----------------- ESTRUTURA: RECURSO -----------------
// (Futuro desenvolvimento: recursos materiais usados em eventos)
typedef struct
{
    int id;
    char nome[100];
    int quantidade;
} Recurso;

// ----------------- ESTRUTURA: FORNECEDOR -----------------
// (Futuro desenvolvimento: fornecedores de serviços/produtos)
typedef struct
{
    int id;
    char nome[100];
    char cnpj[20];
    char telefone[20];
    char email[50];
} Fornecedor;

// ----------------- ESTRUTURA: OPERADOR -----------------
// (Futuro desenvolvimento: operadores contratados pela produtora)
typedef struct
{
    int id;
    char nome[100];
    char funcao[50];
} Operador;

#endif
