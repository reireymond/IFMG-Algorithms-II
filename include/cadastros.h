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

// ----------------- PRODUTORA -----------------

void adicionarProdutora();   // Cadastra uma nova produtora
void alterarProdutora();     // Altera dados da produtora já cadastrada
void verDetalhesProdutora(); // Exibe informações da produtora
void excluirProdutora();     // Remove o cadastro da produtora
void salvarProdutora();      // Persiste os dados em disco
void carregarProdutora();    // Recupera os dados salvos

// ----------------- CLIENTES -----------------

void adicionarCliente();       // Cadastra um novo cliente
void alterarCliente();         // Altera dados de um cliente existente
void listarClientes();         // Lista todos os clientes cadastrados
void excluirCliente();         // Remove um cliente do sistema
void salvarClientes();         // Persiste os clientes em disco
void carregarClientes();       // Recupera os clientes salvos
void liberarMemoriaClientes(); // Libera memória alocada para clientes

// ----------------- EQUIPE INTERNA -----------------
void adicionarEquipeInterna();   // Cadastra um novo membro da equipe
void alterarEquipeInterna();     // Altera dados de um membro existente
void listarEquipeInterna();      // Lista todos os membros da equipe
void excluirEquipeInterna();     // Remove um membro da equipe do sistema
void salvarEquipeInterna();      // Persiste os dados da equipe em disco
void carregarEquipeInterna();    // Recupera os dados da equipe salvos
void liberarMemoriaEquipe();     // Libera memória alocada para a equipe

// ----------------- RECURSOS E EQUIPAMENTOS -----------------
void adicionarRecurso();         // Cadastra um novo recurso ou equipamento
void alterarRecurso();           // Altera dados de um recurso existente
void listarRecursos();           // Lista todos os recursos cadastrados
void excluirRecurso();           // Remove um recurso do sistema
void salvarRecursos();           // Persiste os recursos em disco
void carregarRecursos();         // Recupera os recursos salvos
void liberarMemoriaRecursos();   // Libera memória alocada para os recursos

// ----------------- FORNECEDORES E PARCEIROS -----------------
void adicionarFornecedor();         // Cadastra um novo fornecedor ou parceiro
void alterarFornecedor();           // Altera dados de um fornecedor existente
void listarFornecedores();          // Lista todos os fornecedores cadastrados
void excluirFornecedor();           // Remove um fornecedor do sistema
void salvarFornecedores();          // Persiste os fornecedores em disco
void carregarFornecedores();        // Recupera os fornecedores salvos
void liberarMemoriaFornecedores();  // Libera memória alocada para os fornecedores

// ----------------- OPERADORES DO SISTEMA -----------------
void adicionarOperador();        // Cadastra um novo operador do sistema
void alterarOperador();          // Altera dados de um operador existente
void listarOperadores();         // Lista todos os operadores cadastrados
void excluirOperador();          // Remove um operador do sistema
void salvarOperadores();         // Persiste os operadores em disco
void carregarOperadores();       // Recupera os operadores salvos
void liberarMemoriaOperadores(); // Libera memória alocada para os operadores

#endif