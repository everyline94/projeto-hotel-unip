#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

// Estrutura para representar um quarto
typedef struct {
    int numero;
    char tipo[50];
    bool disponivel;
} Quarto;

// Função para verificar a disponibilidade de um quarto
// TODO - codigo alterado, copiar para o git
void statusQuarto(Quarto quartos[], int numQuartos) {

        printf("\n******************************************\n");
        printf("*****************QUARTOS******************\n");
        printf("******************************************\n");

        for (int i = 0; i < numQuartos; i++) {
            if(quartos[i].disponivel){
                printf("Quarto %d - %s status: Disponivel\n",(i+1),quartos[i].tipo);
            }else{
                printf("Quarto %d - %s status: Reservado\n",(i+1),quartos[i].tipo);
            }
        }
        printf("******************************************");
        printf("\n");
        printf("\n");
}

// Função para reservar um quarto
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
        printf("Escolha uma opcao:\n");
        printf("1. Verificar disponibilidade\n");
        printf("2. Fazer reserva\n");
        printf("3. Sair\n");

        int opcao;
        scanf("%d", &opcao);

        if (opcao == 1) {
            // TODO - codigo alterado, copiar para o git
            statusQuarto(quartos, numQuartos);
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
