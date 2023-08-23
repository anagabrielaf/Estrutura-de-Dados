#include <stdio.h>

typedef struct {
    int valorInteiro;
    float valorFlutuante;
    char letra;
} Tipo;

int main() {
    Tipo exemplo;
   
    exemplo.valorInteiro = 42;
    exemplo.valorFlutuante = 3.14159;
    exemplo.letra = 'A';

    
    printf("Valor Inteiro: %d\n", exemplo.valorInteiro);
    printf("Valor Flutuante: %.5f\n", exemplo.valorFlutuante);
    printf("Letra: %c\n", exemplo.letra);

    return 0;
}

