#include <stdio.h>

typedef struct {
    int valorInteiro;
    float valorPontoFlutuante;
    char letra;
} Tipo;

int main() {
    Tipo dado;

    
    dado.valorInteiro = 42;
    dado.valorPontoFlutuante = 3.14;
    dado.letra = 'A';

    
    printf("Valor inteiro: %d\n", dado.valorInteiro);
    printf("Valor ponto flutuante: %.2f\n", dado.valorPontoFlutuante);
    printf("Letra: %c\n", dado.letra);

    return 0;
}

