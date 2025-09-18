#ifndef MENU_H
#define MENU_H

// ----------------- FUNÇÕES DE MENU -----------------

/**
 * Função: menuEscolherArmazenamento
 * Objetivo: Exibe o menu inicial para o usuário definir
 * o modo de persistência dos dados.
 */
void menuEscolherArmazenamento();

/**
 * Função: menuPrincipal
 * Objetivo: Apresenta o menu principal do sistema e gerencia
 * a navegação entre os módulos.
 */
void menuPrincipal();

/**
 * Função: menuGestaoDeDados
 * Objetivo: Apresenta o submenu de Gestão de Dados, permitindo 
 * ao usuário navegar para os cadastros específicos do 
 * sistema (Produtora, Clientes, Equipe, etc.).
 */
void menuGestaoDeDados();

#endif