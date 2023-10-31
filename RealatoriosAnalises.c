#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int id;
    int quarto_id;
    float valor;
    char data_checkin[11];  
    char data_checkout[11]; 
} Reserva;


float calcularOcupacaoHotel(Reserva reservas[], int numReservas, int hotelId) {
    int quartosOcupados = 0;
    for (int i = 0; i < numReservas; i++) {
        if (reservas[i].quarto_id == hotelId) {
            quartosOcupados++;
        }
    }

    return (float)quartosOcupados / numReservas * 100;
}

// Calcular a receita gerada por um hotel
float calcularReceitaHotel(Reserva reservas[], int numReservas, int hotelId) {
    float receita = 0;
    for (int i = 0; i < numReservas; i++) {
        if (reservas[i].quarto_id == hotelId) {
            receita += reservas[i].valor;
        }
    }

    return receita;
}

int main() {
    Reserva reservas[10];
    int numReservas = 10;


    int hotelId = 1;

    
    float ocupacao = calcularOcupacaoHotel(reservas, numReservas, hotelId);
    printf("Ocupação do Hotel %d: %.2f%%\n", hotelId, ocupacao);

    
    float receita = calcularReceitaHotel(reservas, numReservas, hotelId);
    printf("Receita do Hotel %d: R$%.2f\n", hotelId, receita);

    return 0;
}
