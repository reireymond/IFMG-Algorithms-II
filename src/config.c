#include "config.h"

/* =========================================================
   Arquivo: config.c
   Objetivo: Gerencia a configuração global do sistema,
   mais especificamente o "modo de armazenamento" usado
   para salvar e carregar os dados (em memória, arquivo
   de texto ou arquivo binário).

   Aqui temos funções simples de "get" e "set" para
   manipular a variável global que guarda essa escolha.
   ========================================================= */

// Variável global que guarda o modo de armazenamento atual.
// Por padrão, começa com ARQUIVO_BINARIO.
static TipoArmazenamento modo_de_armazenamento = ARQUIVO_BINARIO;

/* =========================================================
   Função: definirModoDeArmazenamento
   Objetivo: Permite alterar o modo de armazenamento,
   recebendo como parâmetro o novo modo.
   ========================================================= */
void definirModoDeArmazenamento(TipoArmazenamento modo)
{
    modo_de_armazenamento = modo;
}

/* =========================================================
   Função: obterModoDeArmazenamento
   Objetivo: Retorna qual é o modo de armazenamento
   atualmente configurado no sistema.
   ========================================================= */
TipoArmazenamento obterModoDeArmazenamento()
{
    return modo_de_armazenamento;
}
