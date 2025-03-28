#include <stdio.h>
#include <stdlib.h>

int main() {
    // Definição das variáveis principais
    float saldo = 5000.0; // Saldo inicial da conta
    float tesouro_direto = 5.75; // Rendimento mensal do Tesouro Direto
    float poupanca = 1.30; // Rendimento mensal da Poupança
    float cdb = 20.52; // Rendimento mensal do CDB
    char resposta = 's'; // Resposta do usuário para continuar ou não
    float limite_saque = 2000.0; // Limite máximo de saque por operação
    char nome[] = "Gabriel Rosa"; // Nome do cliente

    // Exibição das informações iniciais da conta
    printf("\n------------------------------------\n");
    printf("-- BANCO DA UDF --\n\nCliente: %s\nSaldo: R$%.2f\nLimite de Saque: R$%.2f\n", nome, saldo, limite_saque);

    // Loop principal para realizar operações bancárias
    while (resposta == 's' || resposta == 'S') {
        printf("\n------------------------------------\n");
        printf("Você deseja fazer saque, deposito ou investimento? (s/d/i) ");
        char pergunta;
        scanf(" %c", &pergunta); // Leitura da opção do usuário

        // Verifica se o usuário deseja sacar dinheiro
        if (pergunta == 's' || pergunta == 'S') {
            float saque;
            printf("Escreva o valor do saque (LIMITE R$%.2f / SALDO R$%.2f): ", limite_saque, saldo);
            scanf("%f", &saque);
            
            // Verifica se há saldo suficiente para saque
            if (saldo - saque < 0) {
                printf("! OPERAÇÃO INVÁLIDA, SALDO INSUFICIENTE\n");
            } else if (saque > limite_saque) { // Verifica se ultrapassa o limite de saque
                printf("! OPERAÇÃO INVÁLIDA, LIMITE DE SAQUE DIÁRIO ATINGIDO\n");
            } else {
                saldo -= saque; // Reduz saldo
                limite_saque -= saque; // Reduz o limite de saque diário
                printf("\nSUCESSO AO SACAR.\nSEU NOVO SALDO É DE R$%.2f\nLIMITE PARA SAQUE: R$%.2f\n", saldo, limite_saque);
            }
        }
        // Verifica se o usuário deseja depositar dinheiro
        else if (pergunta == 'd' || pergunta == 'D') {
            float deposito;
            printf("Escreva o valor do deposito: ");
            scanf("%f", &deposito);
            saldo += deposito; // Adiciona valor ao saldo
            printf("\nSUCESSO AO DEPOSITAR.\nSEU NOVO SALDO É DE R$%.2f\n", saldo);
        }
        // Verifica se o usuário deseja investir dinheiro
        else if (pergunta == 'i' || pergunta == 'I') {
            printf("\n------------------------------------\n");
            printf("Para qual área deseja fazer investimento de 1 mês?\nSALDO: R$%.2f\n\n1 - Tesouro Direto (%.2f%% /mês)\n2 - Poupança (%.2f%% /mês)\n3 - CDB (%.2f%% /mês)\n0 - CANCELAR\n", saldo, tesouro_direto, poupanca, cdb);
            int investir;
            scanf("%d", &investir);
            
            // Aplica investimento baseado na escolha do usuário
            if (investir == 1) {
                saldo *= (1 + (tesouro_direto / 100));
                printf("\nSUCESSO COM SEU INVESTIMENTO NO TESOURO DIRETO.\nSALDO ATUALIZADO: R$%.2f\n", saldo);
            } else if (investir == 2) {
                saldo *= (1 + (poupanca / 100));
                printf("\nSUCESSO COM SEU INVESTIMENTO NA POUPANÇA.\nSALDO ATUALIZADO: R$%.2f\n", saldo);
            } else if (investir == 3) {
                saldo *= (1 + (cdb / 100));
                printf("\nSUCESSO COM SEU INVESTIMENTO NO CDB.\nSALDO ATUALIZADO: R$%.2f\n", saldo);
            } else {
                printf("! RESPOSTA DE INVESTIMENTO INVÁLIDA\n");
            }
        }
        // Caso o usuário insira uma opção inválida
        else {
            printf("! RESPOSTA INVÁLIDA\n");
        }
        
        // Pergunta ao usuário se deseja continuar
        printf("\nDeseja fazer outra operação? (s/n) ");
        scanf(" %c", &resposta);
    }

    // Mensagem de encerramento do programa
    printf("\nPROGRAMA FINALIZADO COM SUCESSO!\n");
    return 0;
}
