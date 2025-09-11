#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "structs.h" // Essencial incluir para que ele conheça os tipos como "Cliente".

/*
   INTERFACE DE PERSISTÊNCIA
   Define o "contrato" de todas as funções de manipulação de dados.
*/
typedef struct {
    /* --- Funções para o cadastro de Cliente --- */
    // void (*salvar_cliente)(Cliente c);
    // Este é um ponteiro para uma função que não retorna nada (void)
    // e aceita uma struct Cliente como parâmetro.
    void (*salvar_cliente)(Cliente c);
    void (*listar_todos_clientes)();
    Cliente (*buscar_cliente_por_codigo)(int codigo);
    void (*alterar_cliente)(Cliente c);
    void (*excluir_cliente)(int codigo);


    /* --- Funções para o cadastro de RecursoEquipamento (serão adicionadas depois) --- */
    // void (*salvar_equipamento)(RecursoEquipamento eq);
    // ...


    /* --- Adicionar os outros cadastros aqui posteriormente --- */

} Persistencia;


/*
    FUNÇÕES DE INICIALIZAÇÃO
    O programa principal usará UMA delas para configurar o modo de
    persistência desejado (memória, texto ou binário).
*/

// Configura os ponteiros da struct Persistencia para as funções de memória.
void inicializar_persistencia_memoria(Persistencia* p);

// Configura os ponteiros da struct Persistencia para as funções de arquivo texto.
void inicializar_persistencia_texto(Persistencia* p);

// Configura os ponteiros da struct Persistencia para as funções de arquivo binário.
void inicializar_persistencia_binario(Persistencia* p);


#endif // PERSISTENCIA_H