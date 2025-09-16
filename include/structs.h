#ifndef STRUCTS_H
#define STRUCTS_H

// Estrutura Produtora
typedef struct
{
    char razao_social[101];
    char nome_do_responsavel[101];
    char cnpj[19];
    char inscricao_estadual[25];
    char endereco[256];
    char telefone[16];
    char telefone_responsavel[16];
    char email[255];
    float margem_lucro;

} Produtora;

// Estrutura Cliente
typedef struct
{
    int codigo;
    char razao_social[101];
    char nome_do_cliente[101];
    char cnpj[19];
    char cpf[16];
    char inscricao_estadual[25];
    char endereco[256];
    char telefone[16];
    char email[255];
    char nome_do_contato[101];

} Cliente;

// Estrutura Equipe_Interna
typedef struct
{
    int codigo;
    char nome[101];
    char cpf[16];
    char funcao[50];
    float valor_diaria;
    float valor_hora;

} Equipe_Interna;

// Estrutura Recursos
typedef struct
{
    int codigo;
    char descricao[128];
    char categoria[50];
    int estoque;
    float preco_custo;
    float valor_locacao;

} Recursos;

// Estrutura Fornecedores
typedef struct
{
    int codigo;
    char razao_social[101];
    char nome_fantasia[101];
    char cnpj[19];
    char cpf[16];
    char endereco[256];
    char telefone[16];
    char tipo_servico[126];

} Fornecedores;

// Estrutura Operadores
typedef struct
{
    int codigo;
    char nome_do_cliente[101];
    char usuario[26];
    char hash_senha[128];

} Operadores;

#endif // CADASTRO_H