#ifndef CADASTROS_H
#define CADASTROS_H

#include "structs.h"

// Setor Clientes
void adicionarCliente();
void alterarCliente();
void excluirCliente();
void verDetalhesCliente();

// Setor Produtora
void adicionarProdutora();
void alterarProdutora();
void excluirProdutora();
void verDetalhesProdutora();

// Setor Equipe Interna
void adicionarEquipe_Interna();
void alterarEquipe_Interna();
void excluirEquipe_Interna();
void verDetalhesEquipe_Interna();

// Setor Recursos
void adicionarRecursos();
void alterarRecursos();
void excluirRecursos();
void verDetalhesRecursos();

// Setor Fornecedores
void adicionarFornecedores();
void alterarFornecedores();
void excluirFornecedores();
void verDetalhesFornecedores();

//
void adicionarOperadores();
void alterarOperadores();
void excluirOperadores();
void verDetalhesOperadores();

#endif