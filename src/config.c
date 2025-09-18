#include "config.h"

TipoArmazenamento g_tipoArmazenamento = ARQUIVO_BINARIO;

void definirModoDeArmazenamento(TipoArmazenamento novoModo) {
    g_tipoArmazenamento = novoModo;
}

TipoArmazenamento obterModoDeArmazenamento() {
    return g_tipoArmazenamento;
}