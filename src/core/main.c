#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "ui/menu.h"
#include "utils.h"

// Includes de cadastros
#include "cadastros/produtora.h"
#include "cadastros/cliente.h"
#include "cadastros/equipe.h"
#include "cadastros/recurso.h"
#include "cadastros/fornecedor.h"
#include "cadastros/operador.h"

/* =========================================================
   Função: main
   Objetivo: Função principal do programa.
   Aqui onde tudo começa.
   ========================================================= */
int main()
{
    menuEscolherArmazenamento();

    // Carrega todos os dados dos arquivos
    carregarProdutora();
    carregarClientes();
    carregarEquipeInterna();
    carregarRecursos();
    carregarFornecedores();
    carregarOperadores();

    // Chama o menu principal, que agora controla o loop do programa
    menuPrincipal();

    // Libera toda a memória alocada antes de sair
    liberarMemoriaProdutora();
    liberarMemoriaClientes();
    liberarMemoriaEquipe();
    liberarMemoriaRecursos();
    liberarMemoriaFornecedores();
    liberarMemoriaOperadores();

    return 0;
}