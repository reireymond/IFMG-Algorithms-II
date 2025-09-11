#ifndef STRUCTS_H // Se "STRUCTS_H" não foi definido ainda...
#define STRUCTS_H // ...então defina-o agora.

/*
    MÓDULO DE CADASTROS E GESTÃO DE DADOS
    Definição de todas as estruturas de dados do sistema.
*/

// Estrutura para os dados da própria Produtora de Eventos
typedef struct {
    char nome_fantasia[100];
    char razao_social[100];
    char inscricao_estadual[30];
    char cnpj[20];
    char endereco[150];
    char telefone[20];
    char email[50];
    char nome_responsavel[100];
    char telefone_responsavel[20];
    float margem_lucro_padrao; // Ex: 0.10 para 10%
} Produtora;

// Estrutura para o cadastro de Clientes que contratam os eventos
typedef struct {
    int codigo;
    char nome_razao_social[100];
    char cpf_cnpj[20];
    char endereco[150];
    char telefone[20];
    char email[50];
    char nome_contato[100];
} Cliente;

// Estrutura para a Equipe Interna (funcionários da produtora)
typedef struct {
    int codigo;
    char nome[100];
    char cpf[15];
    char funcao[50];       // Ex: Produtor, Técnico de Som
    float valor_diaria_hora; // Valor da diária ou da hora de trabalho
} EquipeInterna;

// Estrutura para Recursos e Equipamentos da produtora
typedef struct {
    int codigo;
    char descricao[100];     // Ex: Caixa de Som Ativa, Projetor 5000 lumens
    char categoria[50];      // Ex: Sonorização, Iluminação
    int quantidade_estoque;
    float preco_custo;       // Valor de aquisição do equipamento
    float valor_locacao;     // Valor da locação (diária)
} RecursoEquipamento;

// Estrutura para Fornecedores e Parceiros terceirizados
typedef struct {
    int codigo;
    char nome_fantasia[100];
    char razao_social[100];
    char cnpj_cpf[20];
    char endereco[150];
    char telefone[20];
    char tipo_servico[100]; // Ex: Buffet, Segurança, Atração Musical
} Fornecedor;

// Estrutura para os Operadores que usarão o sistema
typedef struct {
    int codigo;
    char nome[100];
    char usuario[30];
    char senha[30]; // Em um sistema real, isso seria criptografado!
} OperadorSistema;


#endif // Fim do bloco de guarda de inclusão.