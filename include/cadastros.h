#ifndef CADASTROS_H
#define CADASTROS_H

#include "structs.h"

/* =========================================================
   Arquivo: cadastros.h
   Objetivo: Declara todas as funções relacionadas aos
   cadastros do sistema (Produtora, Clientes, Equipe Interna,
   Recursos, Fornecedores e Operadores).

   Essas funções implementam operações de CRUD (Cadastrar,
   Alterar, Consultar, Excluir) e também cuidam da
   persistência em arquivo ou memória.
   ========================================================= */

// ----------------- FUNÇÕES AUXILIARES -----------------

/**
 * Função: limpar_buffer
 * Objetivo: Limpa o buffer de entrada para evitar problemas
 * com leitura de strings após scanf.
 */
void limpar_buffer();

// ----------------- PRODUTORA -----------------

void adicionarProdutora();   // Cadastra uma nova produtora
void alterarProdutora();     // Altera dados da produtora já cadastrada
void verDetalhesProdutora(); // Exibe informações da produtora
void excluirProdutora();     // Remove o cadastro da produtora
void salvarProdutora();      // Persiste os dados em disco
void carregarProdutora();    // Recupera os dados salvos

// ----------------- CLIENTES -----------------

void adicionarCliente();        // Cadastra um novo cliente
void alterarCliente();          // Altera dados de um cliente existente
void listarClientes();          // Lista todos os clientes cadastrados
void excluirCliente();          // Remove um cliente do sistema
void salvarClientes();          // Persiste os clientes em disco
void carregarClientes();        // Recupera os clientes salvos
void liberarMemoriaClientes();  // Libera memória alocada para clientes

// ----------------- EQUIPE INTERNA -----------------
// (A ser implementado futuramente)
void adicionarEquipeInterna();
void alterarEquipeInterna();
void listarEquipeInterna();
void excluirEquipeInterna();

// ----------------- RECURSOS -----------------
// (A ser implementado futuramente)
void adicionarRecurso();
void alterarRecurso();
void listarRecursos();
void excluirRecurso();

// ----------------- FORNECEDORES -----------------
// (A ser implementado futuramente)
void adicionarFornecedor();
void alterarFornecedor();
void listarFornecedores();
void excluirFornecedor();

// ----------------- OPERADORES -----------------
// (A ser implementado futuramente)
void adicionarOperador();
void alterarOperador();
void listarOperadores();
void excluirOperador();

#endif
