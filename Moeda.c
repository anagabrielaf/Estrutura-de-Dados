#include <stdio.h>

typedef struct {
    float valorEmDolares;
    float valorEmEuros;
} Moeda;

float taxaCambioDolarParaEuro = 0.85; 

Moeda criarMoeda(float dolares, float euros) {
    Moeda moeda;
    moeda.valorEmDolares = dolares;
    moeda.valorEmEuros = euros;
    return moeda;
}

float converterDolarParaEuro(float valorEmDolares) {
    return valorEmDolares * taxaCambioDolarParaEuro;
}

float converterEuroParaDolar(float valorEmEuros) {
    return valorEmEuros / taxaCambioDolarParaEuro;
}

int main() {
    Moeda minhaMoeda = criarMoeda(100.0, 85.0); 

    printf("Bem-vindo ao conversor de moedas!\n");

    while (1) {
        int opcao;
        printf("\nMenu:\n");
        printf("1. Converter de dolares para euros\n");
        printf("2. Converter de euros para dolares\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            float valorDolares;
            printf("Digite o valor em dolares: ");
            scanf("%f", &valorDolares);
            float valorEuros = converterDolarParaEuro(valorDolares);
            printf("%.2f dolares equivalem a %.2f euros.\n", valorDolares, valorEuros);
        } else if (opcao == 2) {
            float valorEuros;
            printf("Digite o valor em euros: ");
            scanf("%f", &valorEuros);
            float valorDolares = converterEuroParaDolar(valorEuros);
            printf("%.2f euros equivalem a %.2f dolares.\n", valorEuros, valorDolares);
        } else if (opcao == 3) {
            printf("Obrigada!\n");
            break;
        } else {
            printf("Opcaoo invalida.\n");
        }
    }

    return 0;
}

