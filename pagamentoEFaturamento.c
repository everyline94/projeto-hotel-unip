#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int faturaID;
    int reservaID;
    double tarifaQuarto;
    double taxasAdicionais;
    double servicosExtras;
    double total;
    int pago;
} Fatura;


Fatura faturas[100];
int totalFaturas = 0;



double calcularTotalFatura(double tarifaQuarto, double taxasAdicionais, double servicosExtras) {
    return tarifaQuarto + taxasAdicionais + servicosExtras;
}


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


void listarFaturas() {
    printf("Lista de Faturas:\n");
    for (int i = 0; i < totalFaturas; i++) {
        printf("Fatura #%d - Reserva #%d, Total: R$%.2f, Pago: %s\n",
               faturas[i].faturaID, faturas[i].reservaID, faturas[i].total,
               faturas[i].pago ? "Sim" : "Não");
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int escolha;
    while (1) {
        printf("Menu:\n");
        printf("1. Gerar fatura\n");
        printf("2. Listar faturas\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:

                printf("Digite o ID da reserva: ");
                int reservaID;
                scanf("%d", &reservaID);

                printf("Digite a tarifa do quarto: ");
                double tarifaQuarto;
                scanf("%lf", &tarifaQuarto);

                printf("Digite as taxas adicionais: ");
                double taxasAdicionais;
                scanf("%lf", &taxasAdicionais);

                printf("Digite os serviços extras: ");
                double servicosExtras;
                scanf("%lf", &servicosExtras);

                gerarFatura(reservaID, tarifaQuarto, taxasAdicionais, servicosExtras);
                break;

            case 2:

                listarFaturas();
                break;

            case 3:

                printf("Saindo...\n");
                exit(0);

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
