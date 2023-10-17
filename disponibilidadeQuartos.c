#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar uma tarifa de quarto
typedef struct {
    char tipo[50];
    double tarifaPadrao;
    double tarifaEspecial;
} TarifaQuarto;

// Banco de dados de tarifas de quarto (apenas para este exemplo)
TarifaQuarto tarifasQuarto[3] = {
    {"Standard", 100.00, 120.00},
    {"Deluxe", 150.00, 180.00},
    {"Suite", 200.00, 240.00}
};

// Estrutura para representar a disponibilidade de quartos
typedef struct {
    char tipo[50];
    int quantidadeDisponivel;
} DisponibilidadeQuarto;

// Banco de dados de disponibilidade de quartos (apenas para este exemplo)
DisponibilidadeQuarto disponibilidadeQuartos[3] = {
    {"Standard", 10},
    {"Deluxe", 5},
    {"Suite", 3}
};

// Função para listar as tarifas de quartos
void listarTarifas() {
    printf("Tarifas de Quartos:\n");
    for (int i = 0; i < 3; i++) {
        printf("Tipo: %s, Tarifa Padrão: R$%.2f, Tarifa Especial: R$%.2f\n",
               tarifasQuarto[i].tipo, tarifasQuarto[i].tarifaPadrao, tarifasQuarto[i].tarifaEspecial);
    }
}

// Função para listar a disponibilidade de quartos
void listarDisponibilidade() {
    printf("Disponibilidade de Quartos:\n");
    for (int i = 0; i < 3; i++) {
        printf("Tipo: %s, Quantidade Disponível: %d\n",
               disponibilidadeQuartos[i].tipo, disponibilidadeQuartos[i].quantidadeDisponivel);
    }
}

int main() {
    int escolha;
    while (1) {
        printf("Menu:\n");
        printf("1. Listar Tarifas de Quartos\n");
        printf("2. Listar Disponibilidade de Quartos\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                listarTarifas();
                break;
            case 2:
                listarDisponibilidade();
                break;
            case 3:
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
