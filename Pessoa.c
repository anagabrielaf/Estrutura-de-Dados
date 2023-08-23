#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float altura;
} Pessoa;

int main() {
    Pessoa pessoa1; 

    
    printf("Informe o nome da pessoa: ");
    scanf("%s", pessoa1.nome);

    printf("Informe a idade da pessoa: ");
    scanf("%d", &pessoa1.idade);

    printf("Informe a altura da pessoa: ");
    scanf("%f", &pessoa1.altura);

    
    printf("\nDados da pessoa:\n");
    printf("Nome: %s\n", pessoa1.nome);
    printf("Idade: %d anos\n", pessoa1.idade);
    printf("Altura: %.2f metros\n", pessoa1.altura);

    return 0;
}

