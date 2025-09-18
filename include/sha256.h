// CRIPTOGRAFIA HASH SHA-256
// FEITO POR IA

#ifndef SHA256_H
#define SHA256_H

#include <stddef.h>

#define SHA256_BLOCK_SIZE 32 // SHA256_BLOCK_SIZE = 256 / 8

typedef unsigned char BYTE;
typedef unsigned int WORD;

typedef struct {
    BYTE data[64];
    WORD datalen;
    unsigned long long bitlen;
    WORD state[8];
} SHA256_CTX;

void sha256_init(SHA256_CTX *ctx);
void sha256_update(SHA256_CTX *ctx, const BYTE data[], size_t len);
void sha256_final(SHA256_CTX *ctx, BYTE hash[]);

// Função de conveniência para calcular o hash de uma string e retornar como texto
void sha256_string(const char *input, char outputBuffer[65]);

#endif