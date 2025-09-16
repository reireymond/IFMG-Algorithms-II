#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {

    // Dados de Identificação
    char razao_social[101];
    char nome_do_responsavel[101];
    
    // Documentos
    char cnpj[19];
    char inscricao_estadual[25];

    // Contato
    char endereco[256];
    char telefone[16];
    char telefone_responsavel[16];
    char email[255];     

    //  Dados Financeiros
    float margem_lucro;   

} Produtora;

typedef struct {

    // Dados de Identificação
    int codigo;
    char razao_social[101];
    char nome_do_cliente[101];
    
    // Documentos
    char cnpj[19];
    char cpf[16];
    char inscricao_estadual[25];

    // Contato
    char endereco[256];
    char telefone[16];
    char email[255];     
    char nome_do_contato[101];

} Cliente;

typedef struct {

    // Dados de Identificação
    int codigo;
    char nome[101];
    
    // Documentos
    char cpf[16];
    char funcao[50];

    // Monetario
    float valor_diaria;
    float valor_hora;

} Equipe_Interna;

typedef struct {

    // Dados de Identificação
    int codigo;
    
    // Informacoes
    char descricao[128];
    char categoria[50];
    int estoque;
    float preco_custo;
    float valor_locacao;

} Recursos;

typedef struct {

    // Dados de Identificação
    int codigo;
    char razao_social[101];
    char nome_fantasia[101];
    
    // Documentos
    char cnpj[19];
    char cpf[16];

    // Contato
    char endereco[256];
    char telefone[16];

    // Informacoes
    char tipo_servico[126];

} Fornecedores;

typedef struct {

    // Dados de Identificação
    int codigo;
    char nome_do_cliente[101];
    
    // Login
    char usuario[26];
    char hash_senha[128];

} Operadores;

#endif // CADASTRO_H