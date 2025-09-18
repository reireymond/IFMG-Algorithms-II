#include <stdio.h>

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
    // Limpa o buffer de entrada para aguardar o Enter
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    getchar();
}