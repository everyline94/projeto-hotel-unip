#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef struct {
    int id;
    char nome[50];
    char email[100];
    char senha[100];  
} Hospede;


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

   
    if (obterConsentimento()) {
        
        printf("Seus dados foram armazenados com segurança.\n");
    } else {
        
        printf("Seus dados não serão compartilhados.\n");
    }

    return 0;
}
