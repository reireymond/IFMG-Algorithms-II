#ifndef CLIENTE_H
#define CLIENTE_H

#include "structs.h"

void adicionarCliente(Sistema *sistema);
void alterarCliente(Sistema *sistema);
void listarClientes(Sistema *sistema);
void excluirCliente(Sistema *sistema);
void salvarClientes(Sistema *sistema);
void carregarClientes(Sistema *sistema);
void liberarMemoriaClientes(Sistema *sistema);

#endif