#ifndef EQUIPE_H
#define EQUIPE_H

#include "structs.h"

void adicionarEquipeInterna(Sistema *sistema);
void alterarEquipeInterna(Sistema *sistema);
void listarEquipeInterna(Sistema *sistema);
void excluirEquipeInterna(Sistema *sistema);
void salvarEquipeInterna(Sistema *sistema);
void carregarEquipeInterna(Sistema *sistema);
void liberarMemoriaEquipe(Sistema *sistema);

#endif