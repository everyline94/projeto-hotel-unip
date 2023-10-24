#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Definição da estrutura de dados para um hóspede
typedef struct {
    int id;
    char nome[50];
    char email[100];
    char senha[100];  
} Hospede;

// Função para verificar o consentimento do hóspede
bool obterConsentimento() {
    char resposta[5];
    printf("Você concorda com o compartilhamento dos seus dados? (sim/nao): ");
    scanf("%s", resposta);
    return (strcmp(resposta, "sim") == 0);
}

int main() {
    Hospede h;
    
    printf("Informe seu nome: ");
    scanf("%s", h.nome);

    printf("Informe seu email: ");
    scanf("%s", h.email);

    printf("Informe sua senha: ");
    scanf("%s", h.senha);

    // Verificar se o hóspede concorda com o compartilhamento de dados
    if (obterConsentimento()) {
        // Armazenar os dados do hóspede em algum local seguro
        printf("Seus dados foram armazenados com segurança.\n");
    } else {
        // O hóspede não concorda com o compartilhamento de dados
        printf("Seus dados não serão compartilhados.\n");
    }

    return 0;
}
