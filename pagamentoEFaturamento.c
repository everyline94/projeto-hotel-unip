#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma fatura
typedef struct {
    int faturaID;
    int reservaID;
    double tarifaQuarto;
    double taxasAdicionais;
    double servicosExtras;
    double total;
    int pago;
} Fatura;

// Banco de dados de faturas (apenas para este exemplo)
Fatura faturas[100];
int totalFaturas = 0;

// Função para calcular o total da fatura
double calcularTotalFatura(double tarifaQuarto, double taxasAdicionais, double servicosExtras) {
    return tarifaQuarto + taxasAdicionais + servicosExtras;
}

// Função para gerar uma fatura
void gerarFatura(int reservaID, double tarifaQuarto, double taxasAdicionais, double servicosExtras) {
    if (totalFaturas < 100) {
        Fatura novaFatura;
        novaFatura.faturaID = totalFaturas + 1;
        novaFatura.reservaID = reservaID;
        novaFatura.tarifaQuarto = tarifaQuarto;
        novaFatura.taxasAdicionais = taxasAdicionais;
        novaFatura.servicosExtras = servicosExtras;
        novaFatura.total = calcularTotalFatura(tarifaQuarto, taxasAdicionais, servicosExtras);
        novaFatura.pago = 0;

        faturas[totalFaturas] = novaFatura;
        totalFaturas++;
        printf("Fatura gerada com sucesso.\n");
    } else {
        printf("Limite de faturas atingido.\n");
    }
}

// Função para listar todas as faturas
void listarFaturas() {
    printf("Lista de Faturas:\n");
    for (int i = 0; i < totalFaturas; i++) {
        printf("Fatura #%d - Reserva #%d, Total: R$%.2f, Pago: %s\n",
               faturas[i].faturaID, faturas[i].reservaID, faturas[i].total,
               faturas[i].pago ? "Sim" : "Não");
    }
}

int main() {
    int escolha;
    while (1) {
        printf("Menu:\n");
        printf("1. Gerar fatura\n");
        printf("2. Listar faturas\n");
        printf("3. Sair\n");
        printf("Es
