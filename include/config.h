#ifndef CONFIG_H
#define CONFIG_H

/* =========================================================
   Arquivo: config.h
   Objetivo: Define o tipo de armazenamento usado pelo sistema
   e declara funções para alterar e consultar essa configuração.

   O modo de armazenamento afeta como os dados serão gravados:
   - Em memória (não persistem após encerrar o programa)
   - Em arquivo de texto (mais legível, mas menos eficiente)
   - Em arquivo binário (mais eficiente, mas ilegível)
   ========================================================= */

// ----------------- ENUM PARA TIPOS DE ARMAZENAMENTO -----------------

/**
 * TipoArmazenamento:
 *  - MEMORIA → Os dados existem apenas durante a execução
 *  - ARQUIVO_TEXTO → Os dados são salvos em arquivo .txt
 *  - ARQUIVO_BINARIO → Os dados são salvos em arquivo .dat
 */
typedef enum
{
    MEMORIA,
    ARQUIVO_TEXTO,
    ARQUIVO_BINARIO
} TipoArmazenamento;

// ----------------- FUNÇÕES DE CONFIGURAÇÃO -----------------

/**
 * Função: definirModoDeArmazenamento
 * Objetivo: Atualiza a configuração global do sistema para
 * escolher onde os dados serão salvos.
 */
void definirModoDeArmazenamento(TipoArmazenamento modo);

/**
 * Função: obterModoDeArmazenamento
 * Objetivo: Retorna o modo atual de armazenamento definido
 * pelo usuário ou pelo sistema.
 */
TipoArmazenamento obterModoDeArmazenamento();

#endif
