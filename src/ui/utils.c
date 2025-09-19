#include <stdio.h>
#include <stdlib.h>

/* =========================================================
   Função: limpar_buffer
   Objetivo: Garante que o buffer de entrada (stdin) seja
   esvaziado, evitando problemas com leituras subsequentes.
   ========================================================= */
void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/* =========================================================
   Função: pausar
   Objetivo: Serve para segurar a tela até que o usuário
   pressione Enter.
   ========================================================= */
void pausar()
{
    printf("\nPressione Enter para continuar...");
    getchar(); // Apenas espera por um 'Enter'
}

/* =========================================================
   Função: limpar tela
   Objetivo: Serve para limpar a tela, compativel com
   Windows e Linux.
   ========================================================= */
void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}