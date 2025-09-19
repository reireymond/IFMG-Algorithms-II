#include "config.h"

// Mantém o modo de armazenamento de dados escolhido pelo usuário.
// Por padrão, o sistema inicia com ARQUIVO_BINARIO.
static TipoArmazenamento modo_de_armazenamento = ARQUIVO_BINARIO;

/*
 *  Define o modo de armazenamento de dados do sistema.
 * * (MEMORIA, ARQUIVO_TEXTO ou ARQUIVO_BINARIO).
 */
void definirModoDeArmazenamento(TipoArmazenamento modo)
{
   modo_de_armazenamento = modo;
}

/*
 * Obtém o modo de armazenamento de dados atualmente configurado.
 */
TipoArmazenamento obterModoDeArmazenamento()
{
   return modo_de_armazenamento;
}