#ifndef OPERADOR_H
#define OPERADOR_H

#include "structs.h"

void adicionarOperador(Sistema *sistema);
void alterarOperador(Sistema *sistema);
void listarOperadores(Sistema *sistema);
void excluirOperador(Sistema *sistema);
void salvarOperadores(Sistema *sistema);
void carregarOperadores(Sistema *sistema);
void liberarMemoriaOperadores(Sistema *sistema);

#endif