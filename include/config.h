#ifndef CONFIG_H
#define CONFIG_H

typedef enum
{
    MEMORIA,
    ARQUIVO_TEXTO,
    ARQUIVO_BINARIO
} TipoArmazenamento;

extern TipoArmazenamento g_tipoArmazenamento;

void definirModoDeArmazenamento(TipoArmazenamento novoModo);
TipoArmazenamento obterModoDeArmazenamento();

#endif