#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//  Limpa o buffer de entrada do teclado.
 
void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}


 // Pausa a execução do programa até que o usuário pressione Enter.
 
void pausar()
{
    printf("\nPressione Enter para continuar...");
    getchar();
}

 // Limpa a tela do console.
 
void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Helper: copia apenas dígitos de src para dst e retorna quantidade
static int apenas_digitos(const char *src, char *dst, int dst_size) {
    int j = 0;
    for (int i = 0; src[i] != '\0' && j + 1 < dst_size; ++i) {
        if (isdigit((unsigned char)src[i])) dst[j++] = src[i];
    }
    dst[j] = '\0';
    return j;
}

// Valida CPF (aceita com ou sem pontuação)
int validarCPF(const char *cpf_raw) {
    char cpf[12];
    if (apenas_digitos(cpf_raw, cpf, sizeof(cpf)) != 11) return 0;

    int nums[11];
    for (int i = 0; i < 11; ++i) nums[i] = cpf[i] - '0';

    // Rejeita sequências iguais
    int todos_iguais = 1;
    for (int i = 1; i < 11; ++i) if (nums[i] != nums[0]) { todos_iguais = 0; break; }
    if (todos_iguais) return 0;

    int soma = 0;
    for (int i = 0; i < 9; ++i) soma += nums[i] * (10 - i);
    int r = soma % 11;
    int d1 = (r < 2) ? 0 : 11 - r;
    if (d1 != nums[9]) return 0;

    soma = 0;
    for (int i = 0; i < 10; ++i) soma += nums[i] * (11 - i);
    r = soma % 11;
    int d2 = (r < 2) ? 0 : 11 - r;
    return d2 == nums[10];
}