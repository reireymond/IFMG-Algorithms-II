#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "ui/menu.h"
#include "utils.h"

#include "cadastros/produtora.h"
#include "cadastros/cliente.h"
#include "cadastros/equipe.h"
#include "cadastros/recurso.h"
#include "cadastros/fornecedor.h"
#include "cadastros/operador.h"

/*
 * Ponto de entrada principal do programa.
 *
 * Esta função inicializa o sistema, carrega os dados e exibe o menu principal.
 */
int main()
{
    // Exibe o menu para o usuário escolher o modo de armazenamento dos dados.
    menuEscolherArmazenamento();

    // Carrega todos os dados dos arquivos de acordo com o modo de armazenamento escolhido.
    carregarProdutora();
    carregarClientes();
    carregarEquipeInterna();
    carregarRecursos();
    carregarFornecedores();
    carregarOperadores();

    // Exibe o menu principal, que controla o fluxo de execução do programa.
    menuPrincipal();

    // Libera toda a memória alocada dinamicamente antes de encerrar o programa.
    liberarMemoriaProdutora();
    liberarMemoriaClientes();
    liberarMemoriaEquipe();
    liberarMemoriaRecursos();
    liberarMemoriaFornecedores();
    liberarMemoriaOperadores();

    return 0;
}