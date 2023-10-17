#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar uma reserva
typedef struct {
    int reservaID;
    char nomeHospede[100];
    char dataCheckIn[20];
    char dataCheckOut[20];
    int numeroQuarto;
    bool checkIn;
    bool checkOut;
} Reserva;

// Banco de dados de reservas (apenas para este exemplo)
Reserva reservas[100];
int totalReservas = 0;

// Função para realizar o check-in de um hóspede
void fazerCheckIn() {
    int reservaID;
    printf("Digite o ID da reserva para check-in: ");
    scanf("%d", &reservaID);

    for (int i = 0; i < totalReservas; i++) {
        if (reservas[i].reservaID == reservaID) {
            reservas[i].checkIn = true;
            printf("Check-in realizado com sucesso para a reserva #%d.\n", reservaID);
            return;
        }
    }
    printf("Reserva não encontrada.\n");
}

// Função para realizar o check-out de um hóspede
void fazerCheckOut() {
    int reservaID;
    printf("Digite o ID da reserva para check-out: ");
    scanf("%d", &reservaID);

    for (int i = 0; i < totalReservas; i++) {
        if (reservas[i].reservaID == reservaID) {
            reservas[i].checkOut = true;
            printf("Check-out realizado com sucesso para a reserva #%d.\n", reservaID);
            return;
        }
    }
    printf("Reserva não encontrada.\n");
}

// Função para listar todas as reservas
void listarReservas() {
    printf("Lista de Reservas:\n");
    for (int i = 0; i < totalReservas; i++) {
        printf("Reserva #%d - Hóspede: %s, Quarto: %d, Check-in: %s, Check-out: %s\n",
               reservas[i].reservaID, reservas[i].nomeHospede, reservas[i].numeroQuarto,
               reservas[i].dataCheckIn, reservas[i].dataCheckOut);
    }
}

int main() {
    int escolha;
    while (1) {
        printf("Menu:\n");
        printf("1. Realizar check-in\n");
        printf("2. Realizar check-out\n");
        printf("3. Listar reservas\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                fazerCheckIn();
                break;
            case 2:
                fazerCheckOut();
                break;
            case 3:
                listarReservas();
                break;
            case 4:
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
