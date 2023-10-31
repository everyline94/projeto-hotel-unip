#include <stdio.h>
#include <stdbool.h>


typedef struct {
    int numero;
    char tipo[50];
    bool disponivel;
} Quarto;


bool verificarDisponibilidade(Quarto quartos[], int numQuartos, int numeroQuarto) {
    if (numeroQuarto < 1 || numeroQuarto > numQuartos) {
        printf("Quarto inválido.\n");
        return false;
    }

    if (quartos[numeroQuarto - 1].disponivel) {
        printf("Quarto %d (%s) está disponível.\n", quartos[numeroQuarto - 1].numero, quartos[numeroQuarto - 1].tipo);
        return true;
    } else {
        printf("Quarto %d (%s) não está disponível.\n", quartos[numeroQuarto - 1].numero, quartos[numeroQuarto - 1].tipo);
        return false;
    }
}


void fazerReserva(Quarto quartos[], int numQuartos, int numeroQuarto) {
    if (numeroQuarto < 1 || numeroQuarto > numQuartos) {
        printf("Quarto inválido.\n");
        return;
    }

    if (quartos[numeroQuarto - 1].disponivel) {
        quartos[numeroQuarto - 1].disponivel = false;
        printf("Reserva feita para o quarto %d (%s).\n", quartos[numeroQuarto - 1].numero, quartos[numeroQuarto - 1].tipo);
    } else {
        printf("O quarto %d (%s) já está reservado.\n", quartos[numeroQuarto - 1].numero, quartos[numeroQuarto - 1].tipo);
    }
}

int main() {
    int numQuartos = 3;
    Quarto quartos[3] = {
        {1, "Standard", true},
        {2, "Deluxe", true},
        {3, "Suite", true}
    };

    while (1) {
        printf("Escolha uma opção:\n");
        printf("1. Verificar disponibilidade\n");
        printf("2. Fazer reserva\n");
        printf("3. Sair\n");

        int opcao;
        scanf("%d", &opcao);

        if (opcao == 1) {
            int numeroQuarto;
            printf("Digite o número do quarto: ");
            scanf("%d", &numeroQuarto);
            verificarDisponibilidade(quartos, numQuartos, numeroQuarto);
        } else if (opcao == 2) {
            int numeroQuarto;
            printf("Digite o número do quarto que deseja reservar: ");
            scanf("%d", &numeroQuarto);
            fazerReserva(quartos, numQuartos, numeroQuarto);
        } else if (opcao == 3) {
            break;
        } else {
            printf("Opção inválida.\n");
        }
    }

    return 0;
}
