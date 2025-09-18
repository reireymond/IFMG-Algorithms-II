#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastros/equipe.h"
#include "config.h"
#include "utils.h"

// variaveis globais para equipe internas
static EquipeInterna *listarEquipeInterna=NULL;
static int num_equipe=0;
static int capacidade_equipe=0;

// adicionar equipe interna
    void adicionarEquipeinterna(){
        int nova_capacidade;

if (num_equipe == capacidade_equipe)
    {
        int nova_capacidade;
        if (capacidade_equipe == 0)
            nova_capacidade = 10;
        else
            nova_capacidade = capacidade_equipe * 2;

        EquipeInterna *temp = realloc(lista_equipe, nova_capacidade * sizeof(EquipeInterna));
        if (temp == NULL)
        {
            printf("\nErro crítico de alocação de memória para equipe!\n");
            return;
        }
        lista_equipe = temp;
        capacidade_equipe = nova_capacidade;
    }
    // Novo menbro da equipe
    EquipeInterna novo_membro;
    printf("\n--- Cadastro de Novo Membro da Equipe ---\n");
     novo_membro.codigo=num_equipe +1;
     printf("Codigo da Membro:%d",novo_membro); // codigo gerado automaticamente
     
     //coletar usuarios
     lerString(novo_membro.nome, sizeof( novo_membro.nome),"Nome:" );
     lerString(novo_membro.cpf, sizeof( novo_membro.cpf),"CPF:" );
     lerString(novo_membro.funcao, sizeof( novo_membro.funcao),"Funcao:" );

     printf("Valor da diaria:R$ ");
     scanf("%f",&novo_membro.valor_diaria);
     limpar_buffer(); //Limpa o buffer de entrada

     // Salvar vetor dinâmico
     listarEquipeInterna[num_equipe]=novo_membro;
     num_equipe++;

     printf("\n Membro '%s' cadastradi com sucesso!!\n ");
     // salvar em arquivos
     salvarEquipeInterna();
     // mostra a lista da equipe cadastrada
}
     void listarEquipeInterna(){
        if (num_equipe==0)
        {
            printf("\n Nenhum menbro da equipe cadastrado.");
            return;
        }
        
        // Cabeçalho da tabela
        printf("\n---Lista de membros da equipe interna--\n ");
        printf("%-5s %-20s %-15s %-15s %-10s\n", "ID", "Nome", "CPF", "Função", "Diária");
        printf("---------------------------------------------------------------\n");

        // listar dos membros da  equipe para aparecer na tela
        for (int i = 0; i < num_equipe; i++)
        {
             printf("%-5d %-20s %-15s %-15s R$ %-10.2f\n",
               lista_equipe[i].codigo,
               lista_equipe[i].nome,
               lista_equipe[i].cpf,
               lista_equipe[i].funcao,
               lista_equipe[i].valor_diaria);
        }
        
        
     }
        // função de auterar  menbros da equipe (editar)
        void alteraequipe(){
            listarEquipeInterna();
            if (num_equipe==0)
            {
                return;
            }
            int codigo;
            int indice=-1;
            printf("\n Digite o codigo do menbro que deseja alterar:");
            scanf("%d",&codigo);
            limpar_buffer();

            for (int i = 0; i < num_equipe; i++)
            {
                if (lista_equipe[i].codigo==codigo)
                {
                   indice=i;
                   return;
                }
                int opcao;
                do
                {
                    system("cls");
                         printf("--- Alterando Membro: %s ---\n", lista_equipe[indice].nome);
                         printf("1. Alterar Nome\n");
                         printf("2. Alterar CPF\n");
                         printf("3. Alterar Funcao\n");
                          printf("4. Alterar Valor da Diaria\n");
                          printf("0. Salvar e Voltar\n");
                          printf("Escolha: ");
                          scanf("%d", &opcao);
                         limpar_buffer();
                    switch (opcao)
                    {
                    case 1:
                         printf("Novo Nome: ");
                        fgets(lista_equipe[indice].nome, sizeof(lista_equipe[indice].nome), stdin);
                         lista_equipe[indice].nome[strcspn(lista_equipe[indice].nome, "\n")] = 0;
                        break;
                     case 2:
                     printf("Novo CPF:");
                     fgets(lista_equipe[indice].cpf, sizeof(lista_equipe[indice].cpf), stdin);
                     lista_equipe[indice].cpf[strcspn(lista_equipe[indice].cpf, "\n")] = 0;
                     break;
                    case 3:
                    printf("Nova Funcao: ");
                    fgets(lista_equipe[indice].funcao, sizeof(lista_equipe[indice].funcao), stdin);
                    lista_equipe[indice].funcao[strcspn(lista_equipe[indice].funcao, "\n")] = 0;
                    break;
                    case 4:
                          printf("Novo Valor da Diaria: R$ ");
                         scanf("%f", &lista_equipe[indice].valor_diaria);
                        limpar_buffer();
                         break;
                        case 0:
                          printf("\nAlteracoes salvas!\n");
                         break;
                         default:
                         printf("\nOpcao invalida!\n");

                    }

                } while (opcao!=0);
                salvarEquipeInterna();
                
            }
            
            
        }
        








    



