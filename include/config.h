#ifndef CONFIG_H
#define CONFIG_H

/*
  Enumeração dos tipos de armazenamento de dados.
 */
typedef enum
{
    MEMORIA,
    ARQUIVO_TEXTO,
    ARQUIVO_BINARIO
} TipoArmazenamento;

/*
 * Define o modo de armazenamento de dados do sistema.
 */
void definirModoDeArmazenamento(TipoArmazenamento modo);

/*
 * Obtém o modo de armazenamento de dados atualmente configurado.
 */
TipoArmazenamento obterModoDeArmazenamento();

#endif