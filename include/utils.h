#ifndef UTILS_H
#define UTILS_H


 // Limpa o buffer de entrada do teclado.
 
void limpar_buffer();


 // Pausa a execução do programa até que o usuário pressione Enter.
 
void pausar();

// Valida CPF (aceita com ou sem pontuação). Retorna 1 se válido, 0 caso contrário.
int validarCPF(const char *cpf_raw);

#endif  