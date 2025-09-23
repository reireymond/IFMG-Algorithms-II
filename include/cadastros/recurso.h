#ifndef RECURSO_H
#define RECURSO_H

#include "structs.h"

void adicionarRecurso(Sistema *sistema);
void alterarRecurso(Sistema *sistema);
void listarRecursos(Sistema *sistema);
void excluirRecurso(Sistema *sistema);
void salvarRecursos(Sistema *sistema);
void carregarRecursos(Sistema *sistema);
void liberarMemoriaRecursos(Sistema *sistema);

#endif