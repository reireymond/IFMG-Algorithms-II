#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include "structs.h"

void adicionarFornecedor(Sistema *sistema);
void alterarFornecedor(Sistema *sistema);
void listarFornecedores(Sistema *sistema);
void excluirFornecedor(Sistema *sistema);
void salvarFornecedores(Sistema *sistema);
void carregarFornecedores(Sistema *sistema);
void liberarMemoriaFornecedores(Sistema *sistema);

#endif