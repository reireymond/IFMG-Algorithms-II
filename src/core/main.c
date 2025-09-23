#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "ui/menu.h"
#include "utils.h"

#include "cadastros/produtora.h"
#include "cadastros/cliente.h"
#include "cadastros/equipe.h"
#include "cadastros/recurso.h"
#include "cadastros/fornecedor.h"
#include "cadastros/operador.h"
#include "structs.h"

/*
 * Ponto de entrada do programa.
 */
int main()
{
    // Cria e inicializa a estrutura central do sistema.
    Sistema sistema;
    // Zera toda a estrutura para garantir que ponteiros comecem como NULL e contadores como 0.
    memset(&sistema, 0, sizeof(Sistema));

    menuEscolherArmazenamento();

    // Carrega os dados para dentro da estrutura 'sistema'.
    carregarProdutora(&sistema);
    carregarClientes(&sistema);
    carregarEquipeInterna(&sistema);
    carregarRecursos(&sistema);
    carregarFornecedores(&sistema);
    carregarOperadores(&sistema);

    // Passa o ponteiro da 'sistema' para o menu principal.
    menuPrincipal(&sistema);

    // Libera a memória alocada.
    liberarMemoriaProdutora(&sistema);
    liberarMemoriaClientes(&sistema);
    liberarMemoriaEquipe(&sistema);
    liberarMemoriaRecursos(&sistema);
    liberarMemoriaFornecedores(&sistema);
    liberarMemoriaOperadores(&sistema);

    return 0;
}