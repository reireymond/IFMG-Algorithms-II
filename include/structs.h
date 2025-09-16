#ifndef STRUCTS_H
#define STRUCTS_H

// Estrutura Produtora - Adicionado "nome_fantasia"
typedef struct
{
    char nome_fantasia[101]; // <-- ADICIONADO
    char razao_social[101];
    char nome_do_responsavel[101];
    char cnpj[20];
    char inscricao_estadual[25];
    char endereco[256];
    char telefone[20];
    char telefone_responsavel[20];
    char email[255];
    float margem_lucro;

} Produtora;

// Estrutura Cliente - Removido "inscricao_estadual" (opcional)
typedef struct
{
    int codigo;
    char razao_social[101];
    char nome_do_cliente[101]; // Pode ser usado para PF
    char cnpj[20];
    char cpf[20];
    // char inscricao_estadual[25]; // <-- REMOVIDO (Não está no PDF)
    char endereco[256];
    char telefone[20];
    char email[255];
    char nome_do_contato[101];

} Cliente;

// Estrutura Equipe_Interna
typedef struct
{
    int codigo;
    char nome[101];
    char cpf[20];
    char funcao[50];
    float valor_diaria;
    float valor_hora;

} Equipe_Interna;

// Estrutura Recursos (Equipamentos)
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
    char cnpj[20];
    char cpf[20];
    char endereco[256];
    char telefone[20];
    char tipo_servico[126];

} Fornecedores;

// Estrutura Operadores - Corrigido campo "nome"
typedef struct
{
    int codigo;
    char nome[101]; // <-- CORRIGIDO (estava nome_do_cliente)
    char usuario[26];
    char hash_senha[128]; // Ótima prática usar hash!

} Operadores;

#endif // STRUCTS_H